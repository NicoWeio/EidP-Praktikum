#include <iostream>
#include <cstdlib> // d)

using namespace std;

template<typename T>
class Stack {
private:
    // a)
    struct StackElement {
        T const data;
        StackElement *next;
    };
    StackElement *top_element = nullptr;
public:
    Stack();

    bool empty();

    void push(T x);

    void pop();

    T top(); //TODO Referenz zurückgeben

    void clear();

    ~Stack();

    Stack(const Stack &stack);

    Stack<T> &operator=(const Stack<T> &stack);
};

// b)
template<typename T>
Stack<T>::Stack() {
    //nichts zu tun…
}

template<typename T>
bool Stack<T>::empty() {
    return top_element == nullptr;
}

// c)
template<typename T>
void Stack<T>::push(T x) {
    StackElement *oldTop = top_element;
    StackElement *stackElement = new StackElement{x, oldTop}; //das war nicht gerade offensichtlich…
    top_element = stackElement;
}

// d)
template<typename T>
void Stack<T>::pop() {
    if (empty()) {
        cout << "Fehler: Stapel ist leer" << endl;
        exit(1);
    }

    StackElement *newTop = top_element->next;
    delete top_element;
    top_element = newTop;
}

// e)
template<typename T>
T Stack<T>::top() {
    if (empty()) {
        cout << "Fehler: Stapel ist leer" << endl;
        exit(1);
    }

    return top_element->data;
}

// f)
template<typename T>
void Stack<T>::clear() {
    while (top_element != nullptr) {
        pop();
    }
}

template<typename T>
Stack<T>::~Stack() {
    clear();
}

// g)
template<typename T>
Stack<T>::Stack(const Stack &stack) {
    *this = stack;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stack) {
    if (this == &stack)
        return *this;

    clear();
    Stack<T> hilfsStack;

    //ohne Rekursion o.ä. zu nutzen, müssen wir zuerst falsch herum in den Hilfs-Stack kopieren…
    StackElement *nextElement = stack.top_element;
    while (nextElement != nullptr) {
        hilfsStack.push(nextElement->data);
        nextElement = nextElement->next;
    }

    //jetzt richtig herum in den eigentlichen Stack…
    nextElement = hilfsStack.top_element;
    while (nextElement != nullptr) {
        push(nextElement->data);
        nextElement = nextElement->next;
    }

    return *this;
}

