#include "persona.h"
#include <iostream>
 #include <string>
using namespace std;
int main() {

    Persona P;
    Autor A;
    string nombre;
    long Dni;
    string medio;
    Noticia noticia;
    int opcion;

        cout << "Bienvenidos a Daily Bugle" << endl;
        cout << "1. Publicar una noticia" << endl;
        cout << "2. Leer noticias" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

     
    if (opcion == 1)
    {

        cout<<"Indique su Nombre: ";
                cin >> nombre;
                A.setnombre(nombre);
                cout<<"Indique su DNI: ";
                cin >> Dni;
                A.setdni(Dni);
                 cout<<"Indique su Medio: ";
                cin >> medio;
                A.setmedio(medio);
            
                cout<<"Usted se Registro Exitosamente"<<endl;
                A.mostrarautor();
    }
  
}
