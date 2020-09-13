#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Paquete
{
    private:
        string id;
        string origin;
        string destination;
        string weight;
    public:
        Paquete();
        ~Paquete();

        void setId(const string&);
        void setOrigin(const string&);
        void setDestination(const string&);
        void setWeight(const string&);

        bool operator==(const Paquete& ) const;

        string getId();
        string getOrigin();
        string getDestination();
        string getWeight();

        string toString();

        friend std::ostream& operator << (std::ostream&, Paquete&);
        friend std::istream& operator >> (std::istream&, Paquete&);
};

#endif // ALUMNO_H_INCLUDED
