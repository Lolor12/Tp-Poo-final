#include "persona.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
int main() {
    bool noticiaEncontrada = false;
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
    Comentario c;
    string coment;
   
while (opcion != 3)
{
     cout << "Bienvenidos a Daily Bugle" << endl;
        cout << "1. Publicar una noticia" << endl;
        cout << "2. Leer noticias" << endl;
        cout<<"3. Salir"<<endl;
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
                    Archi <<endl<<"Comentarios: "<<endl;
                }
    } else if (opcion == 2) {
        int edad;
        cout << "Indique su Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        U.setnombre(nombre);
        cout << "Indique su DNI: ";
        cin >> Dni;
        U.setdni(Dni);
        cout << "Indique su Edad: ";
        cin >> edad;
        U.setedad(edad);

        cout << "Usted se Registro Exitosamente" << endl;
        cout<<"Busque una noticia por: "<<endl;
                cout<<"1.Autor: "<<endl;
                cout<<"2.Titulo: "<<endl;
                cout<<"3.Anio: "<<endl;
                int opcion1;
                cin >> opcion1;
if (opcion1 == 1) {
    string nombA;
    cin.ignore();
    cout << "Ingrese el nombre del Autor: ";
    getline(cin, nombA);

    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".txt") {
            ifstream archivo(entry.path());
            if (archivo) {
                string linea;
                bool autorCoincide = false;
                string contenidoNoticia;

                while (getline(archivo, linea)) {
                    contenidoNoticia += linea + "\n";
                    if (linea.find("Autor: " + nombA) != string::npos) {
                        autorCoincide = true;
                    }
                }

                if (autorCoincide) {
                    cout << "Noticia encontrada en el archivo: " << entry.path().filename() << endl;
                    cout << contenidoNoticia << endl;
                    noticiaEncontrada = true;
                    cout << "Ingrese su comentario: " << endl;
                
                    getline(cin, coment);
                    c.settexto(coment);

               
                    ofstream Archi(entry.path(), std::ios::app);
                    if (Archi) {
                        Archi << endl << c.gettexto();
                        cout << endl << "Se registró tu comentario de una forma EXITOSA" << endl;
                    } else {
                        cout << "ERROR al abrir el archivo para guardar el comentario." << endl;
                    }
                }
            }
            archivo.close();
        }
    }

    if (!noticiaEncontrada) {
        cout << "No se encontró ninguna noticia del autor: " << nombA << endl;
    }
}

else if (opcion1 == 2) {
        
            cout << "Ingrese el título de la noticia: ";
            string tituloBusqueda;
            cin.ignore();
            getline(cin, tituloBusqueda);

            for (const auto& entry : fs::directory_iterator(".")) {
                if (entry.path().extension() == ".txt") {
                    ifstream archivo(entry.path());
                    if (archivo) {
                        string linea;
                        bool tituloCoincide = false;
                        string contenidoNoticia;

                        while (getline(archivo, linea)) {
                            contenidoNoticia += linea + "\n";
                            if (linea.find(tituloBusqueda) != string::npos) {
                                tituloCoincide = true;
                            }
                        }

                        if (tituloCoincide) {
                            cout << "Noticia encontrada en el archivo: " << entry.path().filename() << endl;
                            cout << contenidoNoticia << endl;
                            noticiaEncontrada = true;
                             cout << "Ingrese su comentario: " << endl;
                    
                    getline(cin, coment);
                    c.settexto(coment);

               
                    ofstream Archi(entry.path(), std::ios::app);
                    if (Archi) {
                        Archi << endl << c.gettexto();
                        cout << endl << "Se registró tu comentario de una forma EXITOSA" << endl;
                    } else {
                        cout << "ERROR al abrir el archivo para guardar el comentario." << endl;
                    }
                }
            }
            archivo.close();
        }
    }

    if (!noticiaEncontrada) {
        cout << "No se encontró ninguna noticia del autor" << endl;
    }
                        }
                    

         else if (opcion1 == 3) {
           
            cout << "Ingrese el año de la noticia: ";
            int anoBusqueda;
            cin >> anoBusqueda;

            for (const auto& entry : fs::directory_iterator(".")) {
                if (entry.path().extension() == ".txt") {
                    ifstream archivo(entry.path());
                    if (archivo) {
                        string linea;
                        bool anoCoincide = false;
                        string contenidoNoticia;

                        while (getline(archivo, linea)) {
                            contenidoNoticia += linea + "\n";
                            if (linea.find("/" + to_string(anoBusqueda)) != string::npos) {
                                anoCoincide = true;
                            }
                        }

                        if (anoCoincide) {
                            cout << "Noticia encontrada en el archivo: " << entry.path().filename() << endl;
                            cout << contenidoNoticia << endl;
                            noticiaEncontrada = true;
                        cout << "Ingrese su comentario: " << endl;
                            cin.ignore();
                             getline(cin, coment);
                              c.settexto(coment);

               
                    ofstream Archi(entry.path(), std::ios::app);
                    if (Archi) {
                        Archi << endl << c.gettexto();
                        cout << endl << "Se registró tu comentario de una forma EXITOSA" << endl;
                    } else {
                        cout << "ERROR al abrir el archivo para guardar el comentario." << endl;
                    }
                }
            }
            archivo.close();
        }
    }

    if (!noticiaEncontrada) {
        cout << "No se encontró ninguna noticia del autor"<< endl;
    }
    }
}
   
}  
}
   
