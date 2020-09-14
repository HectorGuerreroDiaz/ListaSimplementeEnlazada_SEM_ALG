#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Paquete.h"
#include "Lista.h"

using namespace std;

int main()
{
    List<Paquete> miLista;
    Paquete miPaquete;

    string caracter, cosas, CambiosGuardados;
    int longitud;
    int NumPaquetes=0;

    char opc;


    fstream archAlumnos;
    archAlumnos.open("paquetes.dat", ios::in|ios::app);
    if(!archAlumnos.good())
    {
        cerr << " No se pudo abrir el archivo." << endl;
        exit(1);
    }
    while(!archAlumnos.eof())
    {
        archAlumnos >> miPaquete;
        cout<< miPaquete.getId();
        if(miPaquete.getId() != "\0" and miPaquete.getId() != "" and miPaquete.getId() != "\n")
        {
            miLista.insertAtStart(miPaquete);
            NumPaquetes++;
        }
    }

    CambiosGuardados = '1';
    do
    {
        cout << "Menu - Lista Simplemente Ligada" << endl;
        cout << "1. Insertar paquete al inicio" << endl;
        cout << "2. Mostrar todos los paquetes" << endl;
        cout << "3. Ordenar por peso" << endl;
        cout << "4. Ordenar por origen" << endl;
        cout << "5. Guardar Cambios" << endl;
        cout << "6. Salir"<<endl;
        cout << "Elige tu opcion: ";
        cin.sync();
        cin >> opc;
        cout << endl << endl;
        switch(opc)
        {
            case '1':
                NumPaquetes++;
                miPaquete.setId(to_string(NumPaquetes));
                cout << " Origen del Paquete:  ";
                cin.sync();
                getline(cin, caracter, '\n');
                longitud = strlen(caracter.c_str());
                for(int contador = 0;contador <= longitud;contador++)
                {
                    caracter[contador] = toupper(caracter[contador]);
                }
                 miPaquete.setOrigin(caracter);
                cout << " Peso: ";
                cin.sync();
                cin>> caracter;
                miPaquete.setWeight(caracter);

                cout << " Destino: ";
                cin.sync();
                getline(cin, caracter, '\n');
                longitud = strlen(caracter.c_str());
                for(int contador = 0;contador <= longitud;contador++)
                {
                    caracter[contador] = toupper(caracter[contador]);
                }
                miPaquete.setDestination(caracter);

                miLista.insertAtStart(miPaquete);
                CambiosGuardados = '0';
                cout << endl << " Paquete registrado exitosamente: " << endl << endl;
            break;
            case '2':
                if(!(miLista.getFirstPos() == nullptr))
                    cout << " Contenido de la lista: " << endl << endl;
                else
                    cout << " La lista esta vacia " << endl << endl;

                cout << miLista.toString();

                cout << endl << endl;
            break;
            case '3':
                miLista.orderByWeight();

                if(!(miLista.getFirstPos() == nullptr))
                    cout << " Contenido de la lista: " << endl << endl;
                else
                    cout << " La lista esta vacia " << endl << endl;

                cout << miLista.toString();

                cout << endl << endl;
            break;
            case '4':
                miLista.orderByOrigin();

                if(!(miLista.getFirstPos() == nullptr))
                    cout << " Contenido de la lista: " << endl << endl;
                else
                    cout << " La lista esta vacia " << endl << endl;

                cout << miLista.toString();

                cout << endl << endl;
            break;
            case '5':
                archAlumnos.clear();
                archAlumnos.seekp(ios::beg);
                archAlumnos << miLista.toString();
                CambiosGuardados = '1';
            break;
            case '6':
                if(atoi(CambiosGuardados.c_str()) == 1){
                    cout << "Gracias por usar este software!" << endl << endl;
                }else{
                    cosas = '0';
                    do{
                        cout << "No se han guardado los cambios, quiere salir igualmente?\n 1-Si\n 2-No\n";
                        cin >> opc;
                        if(opc == '1'){
                            cout<<"Gracias por usar este software!\n";
                            opc = '6';
                        }else if(opc == '2'){
                            cout<<"Volviendo al menu...\n";
                            opc = '7';
                        }else{
                            cout<<"Opcion no reconocida!\n";
                            cosas = '1';
                        }
                    }while(atoi(cosas.c_str()) == 1);
                }
            break;

        }

    }while(opc != '6');
    archAlumnos.close();
    return 0;
}
