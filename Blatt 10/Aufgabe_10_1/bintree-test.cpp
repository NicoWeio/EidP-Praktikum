#include <iostream>
#include "bintree.h"

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
