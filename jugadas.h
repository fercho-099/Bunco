#ifndef JUGADAS_H_INCLUDED
#define JUGADAS_H_INCLUDED
#include "rlutil.h"
#include <windows.h>
#include <conio.h>
#include <ctime>
#define TECLA_ARRIBA 80
#define TECLA_ABAJO 72
#define ENTER 13

using namespace std;
///declaracion de funciones

int menu_principal();

void unJugador();

void dosJugadores();

void mayorPuntuacion();

void simulado();

void juegoD1(char [], int );

void tirarDados(int [], int );


///implementacion de funciones


int menu_principal()
{

    int total=5, opcionSeleccionada=0, tecla, valorMenu;
    bool salirMenu=true;
    const char *menuOpciones[] = {"1 jugador", "2 Jugadores", "Mayor puntuacion", "Simulado", "Salir"};


do{

    system("cls");
    gotoxy(20,8 + opcionSeleccionada);///gotoxy o rlutil es lo mismo
    cout<<"<---";


    for(int r=0; r<total; r++)
    {


        rlutil::locate(3,8 + r);
        cout<<menuOpciones[r];
    }

    do
    {

        tecla=getch();

    }
    while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

    switch(tecla){

case TECLA_ABAJO:

    if(opcionSeleccionada==0){

        opcionSeleccionada=4;
    }

    else{

        opcionSeleccionada--;
    }

    break;

    case TECLA_ARRIBA:

    if(opcionSeleccionada==4){

        opcionSeleccionada=0;
    }

    else{

        opcionSeleccionada++;
    }

    break;

    case ENTER:

    salirMenu=false;
    valorMenu=opcionSeleccionada+1;
    break;
    }


}while(salirMenu);

return valorMenu;

}

void unJugador(){

char nombre[15];

system("cls");

gotoxy(20,20);
cout<<"Ingrese nombre: ";
gotoxy(40,20);
cin.getline(nombre,15);

juegoD1(nombre, 15);

}

void juegoD1(char nombre[], int tam){

int ronda=6, valorDados[3]= {0}, puntaje;

/**recuadroGeneral();///solo recuadro, el nombre se coloca con gotoxy.
dadosDibujo();///para que dibuje los dados iniciales.*/

for(int rondas=0; rondas<ronda; rondas++){

    puntaje=0;

    do{

        tirarDados(valorDados, 3);

        /*puntaje=puntos();*/



    }while(puntaje<=21);/// cada ronda debe cumplir con los 21 puntos

    cout<<"Puntaje obtenido: "<<puntaje<<endl;
    cout<<"Ronda "<<rondas<<endl;
    system("pause");

}

///pondria return o no, vemos que nos sirve.


}


void tirarDados(int valorDados[], int tama){


 srand(time(NULL));

    for(int t=0; t<tama; t++)
    {

        valorDados[t]= rand()%6+1;

    }

    verficarJugadas(valorDados, 3);


}

int verificarJugadas (int valorDados[], int tam ){

int puntaje=0, total=0;

    for(int r=0; r<tam, r++){

        total+=valorDados[r];
    }


    if(valorDados[0]==valorDados[1]==valorDados[2]){

        puntaje=valorDados[0];
    }
    if()





return puntaje;
}



#endif // JUGADAS_H_INCLUDED
