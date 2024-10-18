#include "persona.h"

persona::persona()
{
}
persona::persona(string _nombre, double _dni){

 
}
void persona::setdni(double _dni)
{
    Dni = _dni;
}


string persona::getnombre()
{
return nombre;
}

void persona::setnombre(string _nombre)
{
    nombre = _nombre;
}

double persona::getDni()
{
return Dni;
}


//////////////////////////////////////////////////////////


Usuario::Usuario(string _nombre, double _dni, int _edad): persona (_nombre, _dni){
    
}

void Usuario::setedad(int _edad){
    edad = _edad;
}
int Usuario::getedad()
{
return edad;
}
;




