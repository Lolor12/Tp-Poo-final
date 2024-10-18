#include <string>
using namespace std;
class persona
{
private:
    double Dni; 
    string nombre;
public:
   persona (string, double);
   persona ();

   void setdni(double);
   double getDni();
   void setnombre(string);
   string getnombre();


};

class Usuario: public persona
{
private:
    int edad;
public:
  
    Usuario(string , double , int );
    void setedad(int);
    int getedad();



};




