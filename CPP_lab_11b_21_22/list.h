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

		while (tmp->next != nullptr)
		{
			this_tmp->next = new node(tmp->next->data, nullptr, this_tmp);

			this_tmp = this_tmp->next;
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

	this->head = nullptr;
}

template<typename T>
void linkedList<T>::addFront(const T& data)
{
	if (this->head != nullptr)
	{
		this->head->prev = new node(data, this->head, nullptr);
		this->head->prev->next = this->head;
		this->head = this->head->prev;
	}
	else
	{
		this->head = new node(data, nullptr, nullptr);
	}
}

template<typename T>
void linkedList<T>::addBack(const T& data)
{
	if (this->head != nullptr)
	{
		node* tmp = this->head;

		//goes to the end of the list
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}

		tmp->next = new node(data, nullptr, tmp);
		tmp->next->prev = tmp;
	}
	else
	{
		this->head = new node(data, nullptr, nullptr);
	}
}

template<typename T>
void linkedList<T>::popBack()
{
	if (this->head == nullptr)
	{
	}
	else if (this->head->next == nullptr)
	{
		delete this->head;
		this->head = nullptr;
	}
	else
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

//-----------------------Etap 2---------------------------------
//Uzupełnij implementacje metod klasy listIterator oraz linkedList etapu 2

//UWAGA
//Gdy wartością zwracaną z metody jest listIterator, sygnatura powinna wyglądać tak:
//(np. dla operatora --)
//typename linkedList<T>::listIterator linkedList<T>::listIterator::operator--(int){...}

template<typename T>
T& linkedList<T>::listIterator::operator*()
{
	if (ptr != nullptr)
	{
		return this->ptr->data;
	}
	else
	{
		throw std::out_of_range("Wyjatek - Pusta lista");
	}
}

template<typename T>
typename linkedList<T>::listIterator& linkedList<T>::listIterator::operator--()
{
	if (this->ptr == nullptr)
	{
		throw std::out_of_range("Wyjatek - Pusta lista");
	}

	if (!this->ptr->prev)
	{
		throw std::out_of_range("Wyjatek - Poczatek listy");
	}
	else
	{
		this->ptr = this->ptr->prev;
		return *this;
	}
}

template<typename T>
typename linkedList<T>::listIterator linkedList<T>::listIterator::operator--(int)
{
	if (this->ptr == nullptr)
	{
		throw std::out_of_range("Wyjatek - Pusta lista");
	}

	if (!this->ptr->prev)
	{
		throw std::out_of_range("Wyjatek - Poczatek listy");
	}
	else
	{
		listIterator tmp(*this);

		this->ptr = this->ptr->prev;

		return tmp;
	}
}

template<typename T>
typename bool linkedList<T>::listIterator::operator== (const listIterator& it) const
{
	if (this->ptr == it.ptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<typename T>
typename linkedList<T>::listIterator linkedList<T>::begin()
{
	if (this->head != nullptr)
	{
		return this->head;
	}
}

template<typename T>
typename linkedList<T>::listIterator linkedList<T>::end()
{
	if (this->head != nullptr)
	{
		listIterator tmp(this->head);

		while (tmp.ptr->next != nullptr)
		{
			tmp.ptr = tmp.ptr->next;
		}

		return tmp.ptr;
	}
}

//-----------------------Etap 3---------------------------------
//Uzupełnij implementacje metody extract



