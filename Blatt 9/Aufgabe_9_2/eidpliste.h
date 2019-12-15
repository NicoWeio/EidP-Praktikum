#ifndef EIDPLISTE_H_
#define EIDPLISTE_H_

#include <stdexcept>

template<typename T>
class Liste {
    struct ListElement {
        T data;
        ListElement *prev;
        ListElement *next;
    };

public:
    Liste() = default;

    Liste(Liste<T> const &liste);

    Liste<T> const &operator=(Liste<T> const &other);

    virtual ~Liste();

    void append(T const &x);

    void clear();

    unsigned int size() const;

    T elementAt(unsigned int position) const;

    void print(bool directionForward);

    void reverse();

    void deleteAt(unsigned int position);

private:
    void clear(ListElement *obj);

    ListElement *sz = nullptr;
    ListElement *ez = nullptr;
    unsigned int counter = 0;
};


template<typename T>
Liste<T>::Liste(Liste<T> const &liste) {
    for (ListElement const *ptr = liste.sz; ptr != nullptr; ptr = ptr->next) {
        append(ptr->data);
    }
}


template<typename T>
Liste<T> const &Liste<T>::operator=(Liste<T> const &other) {
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
void Liste<T>::append(T const &x) {
    ListElement *obj = new ListElement;
    obj->data = x;
    obj->next = nullptr;
    obj->prev = nullptr;
    if (sz == nullptr) {
        sz = obj;
    } else {
        ez->next = obj;
        obj->prev = ez;
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
unsigned int Liste<T>::size() const {
    return counter;
}


template<typename T>
T Liste<T>::elementAt(unsigned int position) const {
    ListElement *ptr = sz;
    while (position > 0) {
        if (ptr->next == nullptr) {
            throw std::range_error("Gesuchter Index ist zu gross.");
        }
        ptr = ptr->next;
        --position;
    }
    return ptr->data;
}

template<typename T>
void Liste<T>::print(bool directionForward) {
    ListElement *ptr = directionForward ? sz : ez;
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        if (directionForward) {
            ptr = ptr->next;
        } else {
            ptr = ptr->prev;
        }
    }
    cout << endl;
}

template<typename T>
void Liste<T>::deleteAt(unsigned int position) {
    ListElement *ptr = sz;
    while (position-- > 0) {
        if (ptr->next == nullptr) {
            throw std::range_error("Gesuchter Index ist zu gross.");
        }
        ptr = ptr->next;
    }

    if (ptr->prev == nullptr) {
        sz = ptr->next;
    } else {
        ptr->prev->next = ptr->next;
    }

    if (ptr->next == nullptr) {
        ez = ptr->prev;
    } else {
        ptr->next->prev = ptr->prev;
    }

    delete ptr;
    --counter;
}

template<typename T>
void Liste<T>::reverse() {
    ListElement *tmp = nullptr;
    ListElement *ptr = sz;

    ez = sz;

    while (ptr != nullptr) {
        tmp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = tmp;

        ptr = ptr->prev;
    }

    if (tmp != nullptr) {
        sz = tmp->prev;
    }
}


#endif /* EIDPLISTE_H_ */
