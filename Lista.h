#ifndef List_H_INCLUDED
#define List_H_INCLUDED

#include <string>
#include <string.h>
#include <iostream>

using namespace std;

template <class T>
class List
{
    public:
        class Nodo
        {
            private:
                T data;
                Nodo* next;
            public:
                Nodo();
                Nodo(const T&);

                T& getData();
                Nodo* getNext() const;

                void setData(const T&);
                void setNext(Nodo*);
        };
    private:
        Nodo* anchor;

    public:
        List();
        List(const List&);

        ~List();

        void insertAtStart(const T&);
        void deleteAtStart(Nodo*);

        Nodo* getFirstPos() const;
        Nodo* getLastPos() const;
        Nodo* getPrevPos(Nodo* ) const;
        Nodo* getNextPos(Nodo* ) const;

        string toString() const;

        void deleteAll();

        void orderByOrigin();

        void orderByWeight();

        List& operator = (const List&);
};

///-----------------------------------------------------Implementación------------------------------------------------------------

///Nodo

template <class T>
List<T>::Nodo::Nodo() : next(nullptr) { }

template <class T>
List<T>::Nodo::Nodo(const T& e) : data(e), next(nullptr) { }

template <class T>
T& List<T>::Nodo::getData()
{
    return data;
}

template <class T>
typename List<T>::Nodo* List<T>::Nodo::getNext() const
{
    return next;
}

template <class T>
void List<T>::Nodo::setData(const T& d)
{
    data = d;
}

template <class T>
void List<T>::Nodo::setNext(List<T>::Nodo* s)
{
    next = s;
}

///Paquetería

template <class T>
List<T>::List() : anchor(nullptr) { }

template <class T>
List<T>::List(const List<T>& l) : anchor(nullptr)
{
    copiarTodo(l);
}

template <class T>
List<T>::~List()
{
    deleteAll();
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l)
{
    deleteAll();

    deleteAll(l);

    return *this;
}



template <class T>
void List<T>::insertAtStart( const T& e)
{
    Nodo* aux(new Nodo(e));

    aux->setNext(anchor);
    anchor = aux;

}

template <class T>
void List<T>::deleteAtStart(List<T>::Nodo* p)
{
    ///Eliminar el primero
    if(p == anchor)
    {
	    anchor = anchor->getNext();
    }
    ///Eliminar cualquier otro
    else
    {
        obtenerAnteriorPos(p)->establecerSiguiente(p->getNext());
    }

    delete p;
}

template <class T>
typename List<T>::Nodo* List<T>::getFirstPos() const
{
    return anchor;
}

template <class T>
typename List<T>::Nodo* List<T>::getLastPos() const
{
    if(anchor == nullptr)
    {
        return nullptr;
    }

    Nodo* aux(anchor);

    while(aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
typename List<T>::Nodo* List<T>::getPrevPos(List<T>::Nodo* p) const
{
    Nodo* aux(anchor);

    while(aux != nullptr and aux->getNext() != p);
    {
        aux = aux->getNext();
    }

    return aux;
}

template <class T>
typename List<T>::Nodo* List<T>::getNextPos(List<T>::Nodo* p) const
{
    if(!esPosicionValida(p))
    {
        return nullptr;
    }

    return p->getNext();
}

/*
template <class T>
typename List<T>::Nodo* List<T>::buscarDato(const T& e) const
{
    Nodo* aux(anchor);
    do{
        if(aux->getData() == e)
        {
            return aux;
        }

        aux = aux->getNext();
    }while(aux != anchor);

    return nullptr;
}

template <class T>
T& List<T>::recuperar(List<T>::Nodo* p)
{
    return p->getData();
}
*/

template <class T>
string List<T>::toString() const
{
    string result;

    Nodo* aux(anchor);
    while(aux != nullptr)
    {
        result += aux->getData().toString() + "\n";

        aux = aux->getNext();
    }

    return result;
}

template <class T>
void List<T>::deleteAll()
{
    Nodo* aux;

    while(anchor != nullptr)
    {
        aux = anchor;

        anchor = anchor->getNext();

        delete aux;
    }
}


template <class T>
void List<T>::orderByOrigin()
{
    Nodo* aux(anchor);
    T auxDato;
    string result;

    while(aux != nullptr)
    {
        Nodo* aux1(aux->getNext());
        result = aux->getData().getOrigin();
        while(aux1 != nullptr)
        {
            if(strcoll(aux->getNext()->getData().getOrigin().c_str(), result.c_str()) < 0)
            {
                auxDato = aux1->getData();
                aux1->setData(aux->getData());
                aux->setData(auxDato);
            }
            aux1 = aux1->getNext();
        }
        aux = aux->getNext();
    }
}


template <class T>
void List<T>::orderByWeight()
{
    Nodo* aux(anchor);
    T auxDato;

    while(aux != nullptr)
    {
        Nodo* aux1(aux->getNext());
        while(aux1 != nullptr)
        {
            if(atoi(aux->getData().getWeight().c_str()) < atoi(aux1->getData().getWeight().c_str()))
            {
                auxDato = aux1->getData();
                aux1->setData(aux->getData());
                aux->setData(auxDato);
            }
            aux1 = aux1->getNext();
        }
        aux = aux->getNext();
    }
}


#endif // List_H_INCLUDED
