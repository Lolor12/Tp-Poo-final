#include <string>
using namespace std;
/// ////////////////
class Usuario;
class Autor;
///////////////////7
class Persona
{
private:
    int Dni;
    string nombre;
public:
    Persona(string, int);
    Persona();

    void setdni(int);
    double getDni();
    void setnombre(string);
    string getnombre();
};

//////////
class Autor : public Persona
{
protected:
    string medio;
public:
    Autor();
    Autor(string, double, string);
    void setmedio(string);
    string getmedio();
    void mostrarautor();
};
///////////
class Usuario : public Persona
{
protected:
    int edad;
public:
    Usuario();
    Usuario(string, double, int);
    void setedad(int);
    int getedad();
};


class Comentario
{
protected:
    
    int numero;
    string texto;
public:
    Usuario Usuario;
    Comentario();
    Comentario(int, string);
    void setnumero(int);
    void settexto(string);
    int getnumero();
    string gettexto();
};

///////////
class Noticia
{
private:
     
    string titulo;
    string detalle;
    int dia;
    int mes;
    int ano;
public:
Comentario C; 
    Autor A; 
    Noticia(string, string, int, int, int);
    Noticia();
    void settitulo(string);
    string gettitulo();
    void setdetalle(string);
    string getdetalle();
    void setdia(int);
    int getdia();
    void setmes(int);
    int getmes();
    void setano(int);
    int getano();
};

