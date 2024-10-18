#include <iostream>
using namespace std;

const int tamaño = 3;
char cuadricula[tamaño][tamaño] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void tablero() {
   cout << " " << cuadricula[0][0] << " | " << cuadricula[0][1] << " | " << cuadricula[0][2] << " \n";
   cout << "---|---|---\n";
   cout << " " << cuadricula[1][0] << " | " << cuadricula[1][1] << " | " << cuadricula[1][2] << " \n";
   cout << "---|---|---\n";
   cout << " " << cuadricula[2][0] << " | " << cuadricula[2][1] << " | " << cuadricula[2][2] << " \n";
}

bool ganador(char jugador) {
   for (int i = 0; i < tamaño; i++) {
       if (cuadricula[i][0] == jugador && cuadricula[i][1] == jugador && cuadricula[i][2] == jugador) return true;
       if (cuadricula[0][i] == jugador && cuadricula[1][i] == jugador && cuadricula[2][i] == jugador) return true;
   }
   if (cuadricula[0][0] == jugador && cuadricula[1][1] == jugador && cuadricula[2][2] == jugador) return true;
   if (cuadricula[0][2] == jugador && cuadricula[1][1] == jugador && cuadricula[2][0] == jugador) return true;
   return false;
}

bool empate() {
   for (int i = 0; i < tamaño; i++) {
       for (int j = 0; j < tamaño; j++) {
           if (cuadricula[i][j] != 'X' && cuadricula[i][j] != 'O') {
               return false;
           }
       }
   }
   return true;
}

void turno(char player) {
   int movimiento;
   bool movimientoV = false;
   while (!movimientoV) {
       cout << "Jugador " << player << ", Ingrese su movimiento (1-9): ";
       cin >> movimiento;
       movimiento--;
       int fil = movimiento / tamaño;
       int col = movimiento % tamaño;
       if (movimiento >= 0 && movimiento < tamaño * tamaño && cuadricula[fil][col] != 'X' && cuadricula[fil][col] != 'O') {
           cuadricula[fil][col] = player;
           movimientoV = true;
       } else {
           cout << "Movimiento Invalido.Intente de nuevo \n";
       }
   }
}

int main() {
   char jugadoractual = 'X';
   bool juegoganado = false;
   tablero();

   while (!juegoganado && !empate()) {
       turno(jugadoractual);
       tablero();
       juegoganado = ganador(jugadoractual);
       if (juegoganado) {
           cout << "El jugador " << jugadoractual << " gano!\n";
       } else if (empate()) {
           cout << "Empate!\n";
       } else {
           jugadoractual = (jugadoractual == 'X') ? 'O' : 'X';
       }
   }
    
   return 0;
}