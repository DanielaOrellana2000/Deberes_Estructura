/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*		PROGRAMA PARA JUEGO 8 REINAS							  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 10/06/2020                                   *
* NRC: 6396                                                       *
*******************************************************************/
#include "Reina.h"
#include <iostream>
#include <fstream> 
////////////////////////////////////////////////////////////////////////
// Name:       Reina::Reina(int n1)
// Purpose:    Implementation of Reina::Reina()
// Parameters:
// - n1
// Return:     
////////////////////////////////////////////////////////////////////////

Reina::Reina(int n1)
{
	n=n1;
	cont=0;
	validar = new bool *[n];
	tablero= new char *[n];
	for(int i=0;i<n;i++){
		validar[i]=new bool [n];
		tablero[i]=new char[n];
		for(int j=0;j<n;j++){
			*(*(validar+i)+j)=false;
			*(*(tablero+i)+j)='.';
		}
	}
	enter.open("solucion.txt",fstream::out); //para leer in, para salir es out escribir
	enter<<"solucion "<<n<<"*"<<n<<endl<<endl;
	contador=0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Reina::~Reina()
// Purpose:    Implementation of Reina::~Reina()
// Return:     
////////////////////////////////////////////////////////////////////////

Reina::~Reina()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Reina::solucion(int x, int y, int n1)
// Purpose:    Implementation of Reina::solucion()
// Parameters:
// - x
// - y
// - n1
// Return:     void
////////////////////////////////////////////////////////////////////////

void Reina::solucion(int x, int y, int n1)
{
	cont+=1;
	//cout<<cont<<endl;
   *(*(tablero+x)+y)='R';
	bloquear(x,y);
	if(n1==n){
		mostrar();
	}else{
		for(int i=0;i<n;i++){
			if(*(*(validar+i)+y+1)==false){
				solucion(i,y+1,n1+1);
			}
		}
	}
	quitarRelleno(x,y);
	
}

////////////////////////////////////////////////////////////////////////
// Name:       Reina::bloquear(int x, int y)
// Purpose:    Implementation of Reina::bloquear()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void Reina::bloquear(int x, int y)
{
   	int aux1,aux2;
	aux2=y;
	aux1=0;
	while(aux1<n){ //vertical
		*(*(validar+aux1)+aux2)=true;
		aux1++;
	}
	aux2=0;
	aux1=x;
	while(aux2<n){
	   	*(*(validar+aux1)+aux2)=true;
		aux2++;
	}
	aux2=y;  //Diagonales
	aux1=x;
	while(aux1>0&&aux2>0){
	  	aux1--;
	  	aux2--;
	}
	aux2=y;
	aux1=x;
	while(aux1<n&&aux2>0){
	   	aux1++;
	   	aux2--;
	}
	aux1--;
	aux2++;
	while(aux1>=0&&aux2<n){
		*(*(validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Reina::quitarRelleno(int x, int y)
// Purpose:    Implementation of Reina::quitarRelleno()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void Reina::quitarRelleno(int x, int y)
{
   *(*(tablero+x)+y)='.';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
	   		*(*(validar+i)+j)=false;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(*(*(tablero+i)+j)=='R')
				bloquear(i,j);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Reina::mostrar()
// Purpose:    Implementation of Reina::mostrar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Reina::mostrar()
{
   	contador++;
	enter<<"Solucion N "<<contador<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			enter<<*(*(tablero+i)+j)<<" ";
		}
		enter<<endl;
	} 
	enter<<endl;
}
/*************************************************************************************************************************************/
//DEBER: MOSTRAR LOS DATOS DEL ARCHIVO EN PANTALLA 
////////////////////////////////////////////////////////////////////////
// Name:       Reina::mostrarPantalla()
// Purpose:    Implementation of Reina::mostrarPantalla()
// Return:     void
////////////////////////////////////////////////////////////////////////


void Reina::mostrarPantalla(){
	/*FILE *ar = fopen("solucion.txt", "r");
	int c;
	//Toma un caracter del archivo y lo asigna a c
	while((c=fgetc(ar))!=EOF){
		putchar(c);
	}*/
	//DEBER: MOSTRAR EL NUMERO DE VECES QUE SE REPITE EL METODO RECURSIVO
	enter<<"numero de repiticiones "<<cont<<endl;
	string texto;
	ifstream archivo;
	cout<<"\nRepeticion: "<<cont<<'\n';
	archivo.open("solucion.txt",ios::in);
	while(!archivo.eof()){
		getline(archivo, texto);
		cout<<texto<<endl;
	}
	archivo.close();
}


////////////////////////////////////////////////////////////////////////
// Name:       Reina::solucionReinas()
// Purpose:    Implementation of Reina::solucionReinas()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Reina::solucionReinas()
{
   	for(int i=0;i<n;i++){
		solucion(i,0,1);
	}
	mostrarPantalla();
	enter.close();
}
