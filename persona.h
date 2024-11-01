#include <string>
using namespace std;
/// ////////////////
class Usuario;
class Autor;
///////////////////7
class Persona
{
private:
    long Dni;
    string nombre;
public:
 Persona();
    Persona(string, long);
   

    void setdni(long);
    long getDni();
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
    Autor(string, long, string);
    void setmedio(string);
    string getmedio();
    string mostrarautor();
    
};
///////////
class Usuario : public Persona
{
protected:
    int edad;
public:
    Usuario();
    Usuario(string, long, int);
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
     Noticia();
    Noticia(string, string, int, int, int);
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


