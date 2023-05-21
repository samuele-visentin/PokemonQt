#ifndef LIST_CUSTOM_H
#define LIST_CUSTOM_H

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
};

#endif // LIST_H
