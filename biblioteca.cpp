#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <locale>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    int annoPublicacion;
    bool disponible;
    time_t fechaDevolucion;
    string quienRetiro;
};

struct Usuario {
    string nombre;
    string apellido;
    string dni;
};

vector<Libro> biblioteca;
vector<string> historial;
Usuario usuario;
const string ARCHIVO_BIBLIOTECA = "bibliotecaa.txt";

void inicializarBiblioteca() {
    biblioteca.push_back({"Introduccion a la Ingenieria", "John Doe", 2000, true, 0, ""});
    biblioteca.push_back({"Calculo para Ingenieria", "Jane Smith", 2005, true, 0, ""});
    biblioteca.push_back({"Fisica General", "Albert Einstein", 1920, true, 0, ""});
    biblioteca.push_back({"Programacion en C++", "Alice Johnson", 2010, true, 0, ""});
    biblioteca.push_back({"Diseno de Circuitos", "Bob Williams", 1998, true, 0, ""});
    biblioteca.push_back({"Mecanica Clasica", "Isaac Newton", 1687, true, 0, ""});
    biblioteca.push_back({"Ingenieria de Software", "Ian Sommerville", 2020, true, 0, ""});
    biblioteca.push_back({"Redes de Computadoras", "Andrew S. Tanenbaum", 2019, true, 0, ""});
    biblioteca.push_back({"Inteligencia Artificial: Un Enfoque Moderno", "Stuart Russell", 2021, true, 0, ""});
}

void leerBibliotecaDesdeArchivo() {
    ifstream archivo(ARCHIVO_BIBLIOTECA);
    if (!archivo.is_open()) {
        inicializarBiblioteca();
        return;
    }

    Libro libro;
    while (archivo >> ws, getline(archivo, libro.titulo)) {
        getline(archivo, libro.autor);
        archivo >> libro.annoPublicacion;
        archivo >> libro.disponible;
        archivo >> libro.fechaDevolucion;
        archivo.ignore();
        getline(archivo, libro.quienRetiro);
        biblioteca.push_back(libro);
    }
    archivo.close();
}

void guardarBibliotecaEnArchivo() {
    ofstream archivo(ARCHIVO_BIBLIOTECA);
    for (const auto& libro : biblioteca) {
        archivo << libro.titulo << endl;
        archivo << libro.autor << endl;
        archivo << libro.annoPublicacion << endl;
        archivo << libro.disponible << endl;
        archivo << libro.fechaDevolucion << endl;
        archivo << libro.quienRetiro << endl;
    }
    archivo.close();
}

void registrarUsuario() {
    cout << "Ingrese su nombre: ";
    getline(cin, usuario.nombre);
    cout << "Ingrese su apellido: ";
    getline(cin, usuario.apellido);
    cout << "Ingrese su DNI: ";
    getline(cin, usuario.dni);
    cout << "Usuario registrado correctamente!" << endl;
}

void agregarLibro() {
    Libro nuevoLibro;
    cout << "Ingrese el titulo del libro: ";
    getline(cin, nuevoLibro.titulo);
    cout << "Ingrese el autor del libro: ";
    getline(cin, nuevoLibro.autor);
    cout << "Ingrese el ano de publicacion del libro: ";
    cin >> nuevoLibro.annoPublicacion;
    nuevoLibro.disponible = true;
    nuevoLibro.fechaDevolucion = 0;
    nuevoLibro.quienRetiro = "";
    cin.ignore();
    biblioteca.push_back(nuevoLibro);
    historial.push_back(nuevoLibro.titulo);
    cout << "Libro agregado correctamente." << endl;
}

void retirarLibro() {
    string titulo;
    cout<<"Escribir el nombre del libro igual a como esta en la biblioteca";
    cout << "\nIngrese el titulo del libro que desea retirar: ";
    getline(cin, titulo);
    for (auto& libro : biblioteca) {
        if (libro.titulo == titulo) {
            if (libro.disponible) {
                libro.disponible = false;
                time_t now = time(0);
                libro.fechaDevolucion = now + (10 * 24 * 60 * 60);
                libro.quienRetiro = usuario.nombre + " " + usuario.apellido;

                cout << "Libro retirado correctamente. Debe devolverlo antes del ";

                char buffer[80];
                struct tm * timeinfo = localtime(&libro.fechaDevolucion);
                strftime(buffer, 80, "%A, %d %B %Y %H:%M:%S", timeinfo);
                cout << buffer << endl;

                cout << "Quien retiro el libro: " << usuario.nombre << " " << usuario.apellido << endl;
                return;
            } else {
                cout << "El libro no esta disponible en este momento." << endl;
                return;
            }
        }
    }
    cout << "El libro no esta disponible en la biblioteca." << endl;
}

void devolverLibro() {
    string titulo;
    cout<<"Escribir el nombre del libro igual a como esta en la biblioteca";
    cout << "\nIngrese el titulo del libro que desea devolver: ";
    getline(cin, titulo);
    for (auto& libro : biblioteca) {
        if (libro.titulo == titulo) {
            if (!libro.disponible && libro.quienRetiro == usuario.nombre + " " + usuario.apellido) {
                libro.disponible = true;
                libro.fechaDevolucion = 0;
                libro.quienRetiro = "";
                cout << "Libro devuelto correctamente." << endl;
                return;
            } else {
                cout << "No tiene registrado este libro como retirado." << endl;
                return;
            }
        }
    }
    cout << "El libro no esta en la biblioteca." << endl;
}

void mostrarBiblioteca()   {
    cout << "Biblioteca:" << endl;
    for (const auto& libro : biblioteca) {
        cout << "Titulo: " << libro.titulo << endl;
        cout << "Autor: " << libro.autor << endl;
        cout << "Ano de publicacion: " << libro.annoPublicacion << endl;
        cout << "Disponible: " << (libro.disponible ? "Si" : "No") << endl;
        if (!libro.disponible) {
            char buffer[80];
            struct tm * timeinfo = localtime(&libro.fechaDevolucion);
            strftime(buffer, 80, "%A, %d %B %Y %H:%M:%S", timeinfo);
            cout << "Fecha de devolucion: " << buffer << endl;
            cout << "Quien retiro el libro: " << libro.quienRetiro << endl;
        }
        cout << endl;
    }
}

int main() {
    leerBibliotecaDesdeArchivo();
    registrarUsuario();

    int opcion;
    do {
        cout << "Menu:" << endl;
        cout << "1. Mostrar biblioteca" << endl;
        cout << "2. Retirar libro" << endl;
        cout << "3. Agregar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                mostrarBiblioteca();
                break;
            case 2:
                retirarLibro();
                break;
            case 3:
                agregarLibro();
                break;
            case 4:
                devolverLibro();
                break;
            case 5:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while(opcion != 5);

    guardarBibliotecaEnArchivo();
    return 0;
}
