/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*		PROGRAMA PARA JUEGO 8 REINAS							  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 10/06/2020                                   *
* NRC: 6396                                                       *
*******************************************************************/
#if !defined(__OchoReinas2_Reina_h)
#define __OchoReinas2_Reina_h
#include <iostream>
#include <fstream> 

using namespace std;

class Reina
{
public:
   Reina(int n1);
   ~Reina();
   void solucion(int x, int y, int n1);
   void bloquear(int x, int y);
   void quitarRelleno(int x, int y);
   void mostrar();
   void mostrarPantalla();
   void solucionReinas();

protected:
private:
   int  cont;
   bool** validar;
   char** tablero;
   fstream enter;
   int contador;
   int n;


};

#endif
