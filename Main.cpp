
#include "persona.h"
#include <iostream>
 #include <string>
using namespace std;
int main() {

    Persona P;
      
    string nombre;
    double Dni;
    string medio;
    Autor A;
    Noticia noticia;
    int opcion;
    do {
        cout << "Bienvenidos a Daily Bugle" << endl;
        cout << "1. Publicar una noticia" << endl;
        cout << "2. Leer noticias" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:

                cout<<"Indique su Nombre:";
                cin >> nombre;
                P.setnombre(nombre);
                cout<<"Indique su DNI";
                cin >> Dni;
                P.setdni(Dni);
                 cout<<"Indique su Medio";
                cin >> medio;
                 A.setmedio(medio);
                cout<<"Usted se Registro Exitosamente";
                A.mostrarautor();
               
                
       
         


                break;
            case 2:  
                break;
            case 3:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while(opcion != 5);
