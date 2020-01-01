#include <iostream>
#include "bintree.h"

// Aufgabe 1f)
// wir nutzen die PreOrder-Reihenfolge
void save(BinTree<int> &tree) {
    string s = tree.stringify();

    ofstream output;
    output.open("tree.txt");
    output << s;
    output.close();
}

// Aufgabe 1g)
// entspricht nicht ganz der Aufgabenstellung, da die Datei nicht vollständig in einen String eingelesen wird
void load(BinTree<int> &tree) {
    ifstream input("tree.txt");
    if (!input.is_open()) {
        cerr << "Konnte tree.txt nicht öffnen" << endl;
        exit(1);
    }

    char ch;
    string s;
    while (input >> ch) {
        if (ch == ',') {
            tree.insert(atoi(s.c_str()));
            s.clear();
        } else {
            s += ch;
        }
    }
}

// Aufgabe 1g)
// genau nach der Aufgabenstellung und ohne Bibliotheken wie sstream:
void load2(BinTree<int> &tree) {
    // Datei in einen String einlesen
    ifstream input("tree.txt");
    if (!input.is_open()) {
        cerr << "Konnte tree.txt nicht öffnen" << endl;
        exit(1);
    }
    string s;
    while (!input.eof()) {
        char ch;
        input >> ch;
        s += ch;
    }
    input.close();

    // mittels find und substr die einzelnen Zahlen auslesen
    size_t pos = 0;
    string token;
    while ((pos = s.find(',')) != string::npos) {
        token = s.substr(0, pos);
        tree.insert(atoi(token.c_str()));
        s.erase(0, pos + 1);
    }
}

int main(int argc, const char *argv[]) {
    BinTree<int> bt;
    cout << "Fuege 50, 3, 53, 21, 72, 15, 69, 111 zu binaerem Suchbaum hinzu" << endl;
    bt.insert(50);
    bt.insert(3);
    bt.insert(53);
    bt.insert(21);
    bt.insert(72);
    bt.insert(15);
    bt.insert(69);
    bt.insert(111);

    cout << endl;
    cout << "Aufgabe 1a)" << endl;
    cout << "Soll-Ausgabe preorder: 50 3 21 15 53 72 69 111" << endl;
    cout << "Ist-Ausgabe preorder : ";
    bt.preOrder();
    cout << endl;

    cout << "Soll-Ausgabe inorder: 3 15 21 50 53 69 72 111" << endl;
    cout << "Ist-Ausgabe inorder : ";
    bt.inOrder();
    cout << endl;

    cout << "Soll-Ausgabe postorder: 15 21 3 69 111 72 53 50" << endl;
    cout << "Ist-Ausgabe postorder : ";
    bt.postOrder();
    cout << endl << endl;

    cout << "Aufgabe 1b) Baumhoehe" << endl;
    cout << "Soll-Ausgabe: 4" << endl;
    cout << "Ist-Ausgabe : " << bt.height() << endl << endl;

    cout << "Aufgabe 1c) Anzahl Elemente" << endl;
    cout << "Soll-Ausgabe: 8" << endl;
    cout << "Ist-Ausgabe : " << bt.count() << endl << endl;

    cout << "Aufgabe 1d) Elemente in [16, 69]" << endl;
    cout << "Soll-Ausgabe: 21 50 53 69" << endl;
    cout << "Ist-Ausgabe : ";
    bt.range(16, 69);
    cout << endl << endl;

    cout << "Aufgabe 1e) newRootLeft" << endl;
    bt.rotateLeft();
    cout << "Soll-Ausgabe Wurzel: 3" << endl;
    cout << "Ist-Ausgabe Wurzel : " << bt.rootData() << endl;
    cout << "Soll-Ausgabe preorder : 3 50 21 15 53 72 69 111" << endl;
    cout << "Ist-Ausgabe preorder  : ";
    bt.preOrder();
    cout << "Soll-Ausgabe postorder: 15 21 69 111 72 53 50 3" << endl;
    cout << "Ist-Ausgabe postorder : ";
    bt.postOrder();
    cout << endl;

    save(bt);

    cout << "Aufgabe 1g) load" << endl;
    load(bt);
    cout << "preorder : ";
    bt.preOrder();
    cout << "inorder  : ";
    bt.inOrder();
    cout << "postorder: ";
    bt.postOrder();
    cout << endl;


    return 0;
}
