
#include "persona.h"
#include <iostream>
 #include <string>
#include <fstream>
using namespace std;
int main() {

    Persona P;
    Autor A;
    string nombre;
    double Dni;
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
        int dia,mes,ano;
        string titulo,texto;
        cout<<"Indique su Nombre:";
                cin >> nombre;
                A.setnombre(nombre);
                cout<<"Indique su DNI";
                cin >> Dni;
                A.setdni(Dni);
                 cout<<"Indique su Medio";
                cin >> medio;
                A.setmedio(medio);
            
                cout<<"Usted se Registro Exitosamente"<<endl;
                cout<<"Ingrese la fecha de hoy dia, mes y año"<<endl;
                cin >> dia;
                cin >> mes;
                cin >> ano;
                noticia.setdia(dia);
                noticia.setmes(mes);
                noticia.setano(ano);
                cout<<"Ingrese el titulo de su noticia"<<endl;
                cin >> titulo;
                noticia.settitulo(titulo);
                cout<<"Escriba su noticia"<<endl;
                cin >> texto;
                noticia.setdetalle(texto);
                ofstream Archi("Noticia.txt"); 
       
                if (!Archi)
                {
                   cout<<"ERROR";
                }
                else 
                {
                    Archi << noticia.gettitulo();
                    Archi << noticia.getdia()<<"/"<<noticia.getmes()<<"/"<<noticia.getano()<<endl;
                    Archi << noticia.getdetalle();
                    Archi << A.mostrarautor();
                }
                


    }
    
