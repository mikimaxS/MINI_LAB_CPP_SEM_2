#pragma once
#include <iostream>

//Etap 1 - 4.0 pkt
template<typename T>
class linkedList
{
public:
    class node
    {
        friend class linkedList;

        T data;
        node* next;
        node* prev;

    public:
        node(const T& data, node* next, node* prev) : data{ data }, next{ next }, prev{ prev } {}

        T& getData() { return data; }

        node* getNext() { return next; }

        node* getPrev() { return prev; }
    };

private:
    node* head;

public:
    linkedList() : head{ nullptr } {};
    linkedList(const linkedList& L);
    ~linkedList();

    bool isEmpty() const { return !head; };
    int size() const;
    void clear();
    T& getFirst() const;
    void addFront(const T& data);
    void addBack(const T& data);
    void popBack();

    template<typename T>
    friend std::ostream& operator<<(std::ostream& out, const linkedList<T>& list);

    /*
    //Etap 2 - 3.0 pkt
    class listIterator
    {
        friend class linkedList;
        node* ptr;

    public:
        listIterator(node* p) : ptr(p) {}
        T& operator*();
        listIterator& operator--();
        listIterator operator--(int);
        bool operator==(const listIterator& it) const;
    };

    listIterator begin();
    listIterator end();
    */
    /*
    //Etap 3 - 3.0 pkt
    template<typename P>
    linkedList<T>* extract(P pred);
    */
};

//Gotowe
template<typename T>
std::ostream& operator<<(std::ostream& out, const linkedList<T>& list)
{
    typename linkedList<T>::node* p;

    for (p = list.head; p != nullptr; p = p->getNext())
        out << " " << p->getData();

    return out;
}

//-----------------------Etap 1---------------------------------
//Uzupełnij implementacje metod klasy linkedList etapu 1

template<typename T>
linkedList<T>::linkedList(const linkedList& L) : linkedList<T>()
{
    if (!L.isEmpty())
    {
        this->head = new node(L.head->data, nullptr, nullptr);

        node* tmp = L.head;
        node* this_tmp = this->head;

        while (!tmp->getNext())
        {
            this_tmp->next = new node(tmp->next->data, nullptr, this_tmp);

            tmp = tmp->next;
        }
    }
}

template<typename T>
linkedList<T>::~linkedList()
{
    this->clear();
}

template<typename T>
void linkedList<T>::clear()
{
    if (!this->isEmpty())
    {
        node* tmp = this->head;
        node* to_be_deleted;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }

        while (tmp != nullptr)
        {
            to_be_deleted = tmp;
            tmp = tmp->prev;

            delete to_be_deleted;
        }
    }
}

template<typename T>
void linkedList<T>::addFront(const T& data)
{
    this->head->prev = new node(data, this->head, nullptr);
    this->head = this->head->prev;
}

template<typename T>
void linkedList<T>::addBack(const T& data)
{
    node* tmp = this->head;

    //goes to the end of the list
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->next = new node(data, nullptr, tmp);
}

template<typename T>
void linkedList<T>::popBack()
{
    node* tmp = this->head;

    //goes to the end of the list
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }

    tmp->prev->next = nullptr;
    delete tmp;
}

template<typename T>
T& linkedList<T>::getFirst() const
{
    if (isEmpty())
    {
        throw "Pusta lista - nie ma pierwszego elementu";
    }
    else
    {
        return this->head->data;
    }
}

template<typename T>
int linkedList<T>::size() const
{
    if (!this->head)
    {
        return 0;
    }
    else
    {
        node* tmp = this->head;
        int i = 1;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            ++i;
        }

        return i;
    }
}




