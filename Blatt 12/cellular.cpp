#include <iostream>
#include <fstream>
#include <string>
#include "PortableBitmap.h"

using namespace std;


bool transition(bool left, bool center, bool right);


int main() {
    char const characterMap[] = {'_', '#'};
    int const maxGenerations = 150;
    int const cellCount = 100;

    ofstream file("cellular.txt");
    if (!file.is_open()) {
        throw std::ios_base::failure("Fehler beim Öffnen von cellular.txt!");
    }

    //Test von d)
    cout << "woman endswith man: " << endswith(string("woman"), string("man")) << endl;
    cout << "text endswith txt: " << endswith(string("text"), string("txt")) << endl;
    cout << "ab endswith bab: " << endswith(string("ab"), string("bab")) << endl;

    PortableBitmap bitmap(maxGenerations, cellCount);

    bool universe[cellCount] =
            {0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    bool tempUniverse[cellCount] = {0};

    for (int i = 0; i < maxGenerations; ++i) {
        // output & save to file
        for (int j = 0; j < cellCount; ++j) {
            cout << characterMap[universe[j]];
            file << characterMap[universe[j]];
            bitmap.setPixel(universe[j], j, i);
        }
        cout << endl;
        file << endl;
        // update
        tempUniverse[0] = transition(universe[cellCount - 1], universe[0], universe[1]);
        for (int j = 1; j < cellCount - 1; ++j) {
            tempUniverse[j] = transition(universe[j - 1], universe[j], universe[j + 1]);
        }
        tempUniverse[cellCount - 1] = transition(universe[cellCount - 2], universe[cellCount - 1], universe[0]);
        // copy
        for (int j = 0; j < cellCount; ++j) {
            universe[j] = tempUniverse[j];
        }
    }

    //Test von f)
    try {
        bitmap.save("cell.pbm");
    }
    catch (invalid_argument &invalidArgument) {
        cerr << invalidArgument.what();
    }
    catch (ios_base::failure &failure) {
        cerr << failure.what();
    }

    //Test von g)
    try {
        PortableBitmap bitmap2 = load("cell.pbm");
    }
    catch (invalid_argument &invalidArgument) {
        cerr << invalidArgument.what() << endl;
    }
    catch (ios_base::failure &failure) {
        cerr << failure.what() << endl;
    }

    return 0;
}

bool transition(bool left, bool center, bool right) {
    static bool const transitionMap[] = {0, 1, 1, 1, 0, 1, 1, 0};

    int inputEncoded = right + 2 * center + 4 * left;
    return transitionMap[inputEncoded];
}
