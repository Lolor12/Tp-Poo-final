#include <string>
using namespace std;

class Persona
{
private:
    double Dni; 
    string nombre;
public:
   Persona (string, double);
   Persona ();

   void setdni(double);
   double getDni();
   void setnombre(string);
   string getnombre();
};
///////////////////////////////////////////////////////
class Usuario: public Persona
{
private:
    int edad;
public:
    Usuario();
    Usuario(string , double , int );
    void setedad(int);
    int getedad();
};
//
class Autor : public Persona
{
private:
    string medio;
public:
    Autor();
    Autor(string , double, string);
    void setmedio(string);
    string getmedio();

};
//////////////////////////////////////
class Comentario
{
private:
    int numero;
    string texto;
public:
    Comentario();
    Comentario(int,string);
    void setnumero(int);
    void settexto(string);
    int getnumero();
    string gettexto();
};
///////////////////////////////////////
class Noticia
{
private:
    string titulo; 
    string detalle;
    int dia;
    int mes;
    int ano;
public:
   Noticia (string, string,int,int,int);
   Noticia ();
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




