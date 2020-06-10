/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*		PROGRAMA PARA JUEGO 8 REINAS							  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 10/06/2020                                   *
* NRC: 6396                                                       *
*******************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>  
#include "Reina.h"
#include "Ingreso.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	int n;
	cout<<"\tCuantas reinas: "<<endl;
	cin>>n;
	Reina *obj= new Reina(n);
	obj->solucionReinas();
	//cout<<"Se creo el archivo solucion.txt"<<endl;
	return 0;
}

