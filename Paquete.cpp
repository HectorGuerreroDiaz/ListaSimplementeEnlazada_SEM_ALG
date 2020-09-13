#include "Paquete.h"

Paquete::Paquete() { }

Paquete::~Paquete() { }

bool Paquete::operator==(const Paquete& a) const
{
    return origin == a.origin;
}

string Paquete::toString()
{
    string result;

    result+= id;
    result+= " | ";
    result+= origin;
    result+= " | ";
    result+= destination;
    result+= " | ";
    result+= weight;
    result+= " |";

    return result;
}

void Paquete::setId(const string& i)
{
    id = i;
}

void Paquete::setOrigin(const string& o)
{
    origin = o;
}

void Paquete::setDestination(const string& d)
{
    destination = d;
}

void Paquete::setWeight(const string& p)
{
    weight = p;
}

string Paquete::getId()
{
    return id;
}

string Paquete::getOrigin()
{
    return origin;
}

string Paquete::getDestination()
{
    return destination;
}

string Paquete::getWeight()
{
    return weight;
}

ostream& operator << (ostream& os, Paquete& paquete)
{
    os << paquete.id << endl;
    os << paquete.origin << endl;
    os << paquete.destination << endl;
    os << paquete.weight << endl;

    return os;
}

istream& operator >> (istream& is, Paquete& paquete)
{
    string nada;
    getline(is, paquete.id, '|');
    getline(is, paquete.origin, '|');
    getline(is, paquete.destination, '|');
    getline(is, paquete.weight, '|');
    getline(is, nada, '\n');

    return is;
}
