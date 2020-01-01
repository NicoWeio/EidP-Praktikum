
#ifndef EIDPLISTE_H_
#define EIDPLISTE_H_

#include <iostream>

template<typename T>
class Liste {
public:
    Liste();

    Liste(const Liste<T> &liste);

    ~Liste();

    const Liste<T> &operator=(const Liste<T> &other);

    void append(const T &x);

    void clear();

    unsigned int size();

    T elementAt(unsigned int i);

    void print();

private:
    struct ListElement {
        T data;
        ListElement *next;
    } *sz, *ez;
    unsigned int counter;

    void clear(ListElement *obj);
};

template<typename T>
Liste<T>::Liste() :
        sz(nullptr), ez(nullptr), counter(0) {}

template<typename T>
Liste<T>::Liste(const Liste<T> &liste) :
        sz(nullptr), ez(nullptr), counter(0) {
    for (ListElement *ptr = liste.sz; ptr != nullptr; ptr = ptr->next) {
        append(ptr->data);
    }
}

template<typename T>
const Liste<T> &Liste<T>::operator=(const Liste<T> &other) {
    if (this == &other) {
        return *this;
    }
    clear();
    for (ListElement *ptr = other.sz; ptr != nullptr; ptr = ptr->next) {
        append(ptr->data);
    }
    return *this;
}

template<typename T>
void Liste<T>::append(const T &x) {
    ListElement *obj = new ListElement;
    obj->data = x;
    obj->next = nullptr;
    if (sz == nullptr) {
        sz = obj;
    } else {
        ez->next = obj;
    }
    ez = obj;
    ++counter;
}

template<typename T>
void Liste<T>::clear(ListElement *obj) {
    if (obj == nullptr)
        return;
    clear(obj->next);
    delete obj;
}

template<typename T>
void Liste<T>::clear() {
    clear(sz);
    sz = nullptr;
    ez = nullptr;
    counter = 0;
}

template<typename T>
Liste<T>::~Liste() {
    clear();
}

template<typename T>
unsigned int Liste<T>::size() {
    return counter;
}

template<typename T>
T Liste<T>::elementAt(unsigned int i) {
    ListElement *ptr = sz;
    while (i > 0) {
        ptr = ptr->next;
        --i;
    }
    return ptr->data;
}

template<typename T>
void Liste<T>::print() {
    for (ListElement *ptr = sz; ptr != nullptr; ptr = ptr->next)
        std::cout << ptr->data << " ";
}


#endif /* EIDPLISTE_H_ */
