
#include "persona.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {

    Persona P;
    Autor A;
    Usuario U;
    string nombre;
    double Dni;
    string medio;
    string nombreArchivo; 
    Noticia noticia;
    int dia,mes,ano;
    string titulo,detalle;
    int opcion;

        cout << "Bienvenidos a Daily Bugle" << endl;
        cout << "1. Publicar una noticia" << endl;
        cout << "2. Leer noticias" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

     
    if (opcion == 1)
    {
        cout<<"Indique su Nombre: ";
                cin.ignore();
                getline(cin,nombre);
                A.setnombre(nombre);
                cout<<"Indique su DNI: ";
                cin >> Dni;
                A.setdni(Dni);
                cout<<"Indique su Medio: ";
                cin.ignore();
                getline(cin,medio);
                A.setmedio(medio);
            
                cout<<"Usted se Registro Exitosamente"<<endl;
                cout<<"Ingrese la fecha de hoy dia, mes y anio: "<<endl;
                cin >> dia;
                cin >> mes;
                cin >> ano;
                noticia.setdia(dia);
                noticia.setmes(mes);
                noticia.setano(ano);
                cout<<"Ingrese el titulo de su noticia: "<<endl;
                cin.ignore();
                getline(cin, titulo);
                noticia.settitulo(titulo);
                cout<<"Escriba su noticia: "<<endl;
                getline(cin, detalle);
                noticia.setdetalle(detalle);

                replace(titulo.begin(), titulo.end(), ' ', '_');
                nombreArchivo = titulo + ".txt";
                ofstream Archi(nombreArchivo,std::ios::app); 
       
                if (!Archi)
                {
                   cout<<"ERROR";
                }
                else 
                {
                    Archi <<"Noticia de: "<<A.mostrarMedio()<<endl;
                    Archi << noticia.getdia()<<"/"<<noticia.getmes()<<"/"<<noticia.getano()<<endl;
                    Archi <<endl<< noticia.gettitulo()<<endl;
                    Archi <<endl<< noticia.getdetalle()<<endl;
                    Archi <<endl<<"Autor: "<<A.mostrarautor()<<endl;
                }
    }else if(opcion==2){
            int edad;
                cout<<"Indique su Nombre: ";
                cin.ignore();
                getline(cin,nombre);
                U.setnombre(nombre);
                cout<<"Indique su DNI: ";
                cin >> Dni;
                U.setdni(Dni);
                cout<<"Indique su Edad: ";
                cin>>edad;
                U.setedad(edad);

                cout<<"Usted se Registro Exitosamente"<<endl;
                cout<<"Busque una noticia: "<<endl;
                cout<<"1.Autor: "<<endl;
                cout<<"2.Titulo: "<<endl;
                cout<<"3.Anio: "<<endl;
                int busqueda;
                cin>>busqueda;
                if (busqueda == 1) {
                    cout << "Ingrese el nombre del Autor: ";
                    string nombA;
                    cin.ignore();
                    getline(cin, nombA);

                     ifstream archivo;
                    archivo.open(nombreArchivo, ios::in);

                     if (!archivo) {
                     cout << "No se pudo abrir el archivo." << endl;
                      } else {
                    bool autorEncontrado = false;
                    while (getline(archivo, detalle)) {
                    if (detalle.find(nombA) != string::npos) {
                    autorEncontrado = true;
                    cout << detalle << endl;
            }
        }
        archivo.close();

        if (!autorEncontrado) {
            cout << "El autor no fue encontrado en la noticia." << endl;
        }
    }
}

                
    }   
}
