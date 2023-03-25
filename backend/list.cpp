#include "list.h"

template<class T>
List<T>::nodo::nodo(const T& e, nodo *p, nodo *n) :
    elem(e), prev(p), next(n){}

template<class T>
void List<T>::destroy(nodo *f) {
    //caso base f == nullptr
    if(f != nullptr) {
        destroy(f->next);
        delete f;
    }
}

template<class T>
void List<T>::copy(nodo* fst, nodo*& f, nodo*& l) {
    if(fst == nullptr) { //lista vuota
        f=l=nullptr;
        return;
    }
    l=f= new nodo(f->elem,nullptr,nullptr);
    nodo *tmp = f;
    while(fst->next != nullptr) {
        fst = fst->next;
        l->next = new nodo(fst->elem, l, nullptr);
        l = l->next;
    }
}

template<class T>
List<T>::List(const T& elem) :
    first(new nodo(elem, nullptr, nullptr)),
    last(first){}

template<class T>
List<T>::List() : first(nullptr), last(nullptr){}

template<class T>
List<T>::List(const List& list) : first(nullptr),
    last(nullptr) {
    copy(list.first, first, last);
}

template<class T>
List<T>::~List() {
    if(first)
        destroy(first);
}

template<class T>
List<T>& List<T>::operator=(const List& list) {
    if(this != &list) {
        if(first) destroy(first);
        copy(list.first, first, last);
    }
    return *this;
}

template<class T>
void List<T>::insertFront(const T& elem) {
    if(first != nullptr) {
        first->prev = new nodo(elem,nullptr,first);
        first = first->prev;
    } else
        first = last = new nodo(elem,nullptr, nullptr);
}

template<class T>
void List<T>::insertBack(const T& elem) {
    if(last != nullptr) {
        last->next = new nodo(elem, last, nullptr);
        last = last->next;
    } else
        first = last = new nodo(elem, nullptr, nullptr);
}

template<class T>
List<T>::const_iterator::const_iterator(const nodo *p, bool pte) :
    ptr(p), pastTheEnd(pte){}

template<class T>
List<T>::const_iterator::const_iterator() :
    ptr(nullptr), pastTheEnd(false){}

template<class T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++() {
    if(ptr && !pastTheEnd) {
        if(ptr->next == nullptr) {
            ptr += 1;
            pastTheEnd = true;
        } else ptr = ptr->next;
    }
    return *this;
}

template<class T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
    const_iterator tmp(*this);
    if(ptr && !pastTheEnd) {
        if(ptr->next == nullptr) {
            ptr += 1;
            pastTheEnd = true;
        } else ptr = ptr->next;
    }
    return tmp;
}

template<class T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--() {
    if (ptr) {
        if(pastTheEnd) {
            ptr -= 1;
            pastTheEnd = false;
        } else {
            ptr = ptr->prev;
        }
    }
    return *this;
}

template<class T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
    const_iterator tmp(*this);
    if (ptr) {
        if(pastTheEnd) {
            ptr -= 1;
            pastTheEnd = false;
        } else {
            ptr = ptr->prev;
        }
    }
    return tmp;
}

template<class T>
const T& List<T>::const_iterator::operator*() const {
    return ptr->elem;
}

template<class T>
const T* List<T>::const_iterator::operator->() const {
    return &(ptr->elem);
}

template<class T>
typename List<T>::const_iterator List<T>::begin() const {
    if(first != nullptr)
        return const_iterator(first);
    return const_iterator();
}

template<class T>
typename List<T>::const_iterator List<T>::end() const {
    if(first == nullptr) return const_iterator();
    return const_iterator(last+1, true);
}

template<class T>
bool List<T>::const_iterator::operator==(const const_iterator& cit) const {
    return ptr == cit.ptr;
}

template<class T>
bool List<T>::const_iterator::operator!=(const const_iterator& cit) const {
    return ptr != cit.ptr;
}
