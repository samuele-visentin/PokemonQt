#ifndef LIST_CUST_H
#define LIST_CUST_H

template<class T>
class List { //Lista doppiamente linkata
private:
    class nodo {
    public:
        T elem;
        nodo *prev, *next;
        nodo(const T& e, nodo* p=0, nodo* n=0);
    };
    nodo *first, *last;
    static void destroy(nodo* f);
    static void copy(nodo *fst, nodo*& f, nodo*& l);
public:
    List(const T& elem);
    List();
    List(const List<T>& list);
    ~List();
    List<T>& operator=(const List<T>& list);
    void insertFront(const T& elem);
    void insertBack(const T& elem);
    void erase();
    class const_iterator {
        friend class List<T>;
    private:
        const nodo* ptr;
        bool pastTheEnd;
        const_iterator(const nodo* p, bool pte=false);
    public:
        const_iterator();
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const const_iterator& cit) const;
        bool operator!=(const const_iterator& cit) const;
    };
    const_iterator begin() const;
    const_iterator end() const;

    class iterator {
        friend class List<T>;
    private:
        nodo* ptr;
        bool pastTheEnd;
        iterator(nodo* p, bool pte=false);
    public:
        iterator();
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        T& operator*() const;
        T* operator->() const;
        bool operator==(const iterator& cit) const;
        bool operator!=(const iterator& cit) const;
    };
    iterator begin();
    iterator end();

    template<class C, class compare>
    List<T>::iterator find(const C& elem, compare comp);
    T removeAt(iterator it);
    void insert(iterator it, const T& elem);
};

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
List<T>::List() : first(nullptr), last(nullptr)
{}

template<class T>
List<T>::List(const List<T>& list) : first(nullptr),
    last(nullptr) {
    copy(list.first, first, last);
}

template<class T>
List<T>::~List() {
    if(first)
        destroy(first);
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list) {
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
void List<T>::erase() {
    if(first) {
        destroy(first);
        first = last = nullptr;
    }
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

template<class T>
List<T>::iterator::iterator(nodo *p, bool pte) :
    ptr(p), pastTheEnd(pte){}

template<class T>
List<T>::iterator::iterator() :
    ptr(nullptr), pastTheEnd(false){}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    if(ptr && !pastTheEnd) {
        if(ptr->next == nullptr) {
            ptr += 1;
            pastTheEnd = true;
        } else ptr = ptr->next;
    }
    return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    iterator tmp(*this);
    if(ptr && !pastTheEnd) {
        if(ptr->next == nullptr) {
            ptr += 1;
            pastTheEnd = true;
        } else ptr = ptr->next;
    }
    return tmp;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator--() {
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
typename List<T>::iterator List<T>::iterator::operator--(int) {
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
T& List<T>::iterator::operator*() const {
    return ptr->elem;
}

template<class T>
T* List<T>::iterator::operator->() const {
    return &(ptr->elem);
}

template<class T>
typename List<T>::iterator List<T>::begin() {
    if(first != nullptr)
        return iterator(first);
    return iterator();
}

template<class T>
typename List<T>::iterator List<T>::end() {
    if(first == nullptr) return iterator();
    return iterator(last+1, true);
}

template<class T>
bool List<T>::iterator::operator==(const iterator& cit) const {
    return ptr == cit.ptr;
}

template<class T>
bool List<T>::iterator::operator!=(const iterator& cit) const {
    return ptr != cit.ptr;
}

template<class T>
template<class C, class Compare>
typename List<T>::iterator List<T>::find(const C& elem, Compare comp) {
    for (iterator it = begin(); it != end(); ++it) {
        if (comp(*it, elem)) {
            return it;
        }
    }
    return end();
}

template<class T>
T List<T>::removeAt(iterator it) {
    if(it == begin()){
        if(first==last)
            last = nullptr;
        delete first;
        first = nullptr;
    } else if(++it == end()) {
        last = last->prev;
    } else {
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
    }
    return *it;
}

template<class T>
void List<T>::insert(iterator it, const T& elem) {
    if(it == begin()) {
        //inserimento all'inizio
        first = new nodo(elem, nullptr, first);
        if(first->next != nullptr) {
            first->next->prev = first;
        } else {
            last = first;
        }
    } else if(it == end()) {
        //inserimento alla fine
        nodo* newNode = new nodo(elem, last, nullptr);
        if (last != nullptr) {
            last->next = newNode;
        } else {
            first = newNode;
        }
        last = newNode;
    } else {
        //inserimento a metà
        nodo* newNode = new nodo(elem, it.ptr->prev, it.ptr);
        it.ptr->prev->next = newNode;
        it.ptr->prev = newNode;
    }
}

#endif // LIST_CUST_H

