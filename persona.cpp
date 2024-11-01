#include "persona.h"
#include <iostream>

Persona::Persona()
{
}
Persona::Persona(string _nombre, int _dni)
{
}
void Persona::setdni(int _dni)
{
    Dni = _dni;
}

string Persona::getnombre()
{
return nombre;
}

void Persona::setnombre(string _nombre)
{
    nombre = _nombre;
}

double Persona::getDni()
{
return Dni;
}
///////////////////////////////////////////////////////////////////////////////
Usuario::Usuario()
{
}
Usuario::Usuario(string _nombre, double _dni, int _edad): Persona (_nombre, _dni){    
}
void Usuario::setedad(int _edad)
{
    edad = _edad;
}
int Usuario::getedad()
{
return edad;
};
/////////////////////////////////////////////////////////////////////
Autor::Autor(){
}
Autor::Autor(string _nombre, double _dni, string _medio): Persona (_nombre, _dni){    
}
void Autor::setmedio(string _medio){
    medio = _medio;
}
string Autor::getmedio()
{
return medio;
};

void Autor::mostrarautor(){
 cout << "Autor: " << getnombre() << "\nDNI: " << getDni() << "\nMedio: " << medio << endl;
};
///////////////////////////////////////////////////////////////////////
Comentario::Comentario()
{
}
Comentario::Comentario(int _numero,string _texto)
{
}
void Comentario::setnumero(int _numero)
{
    numero=_numero;
}
int Comentario::getnumero()
{
    return numero;
}
void Comentario::settexto(string _texto)
{
    texto=_texto;
}
string Comentario::gettexto()
{
    return texto;
}
////////////////////////////////////////////////////////
Noticia::Noticia()
{
}
Noticia::Noticia(string _titulo, string _detalle, int _dia, int _mes, int _ano)
{
}

void Noticia::settitulo(string _titulo)
{
    titulo = _titulo;
}
string Noticia::gettitulo()
{
return titulo;
}
void Noticia::setdetalle(string _detalle)
{
    detalle = _detalle;
}
string Noticia::getdetalle()
{
return detalle;
}
void Noticia::setdia(int _dia)
{
    dia = _dia;
}
int Noticia::getdia()
{
return dia;
}
void Noticia::setmes(int _mes)
{
    mes = _mes;
}
int Noticia::getmes()
{
return mes;
}
void Noticia::setano(int _ano)
{
    ano = _ano;
}
int Noticia::getano()
{
return ano;
}

