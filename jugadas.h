#ifndef JUGADAS_H_INCLUDED
#define JUGADAS_H_INCLUDED
#include "rlutil.h"
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "dibujo.h"
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

int tirarDados(int [], int, int);

int verificarJugadas (int [], int , int);

void juegoSimulado(char [], int );

int tirarDadosSimulados( int [], int, int );

int VerificarSimulado(int [], int, int);

void AcomodarDados(int [], int);



void MayorPuntuacion();



void GrabarPuntuacion(char [],int ,int ,int );





///implemetacion de la funcion
/*
void MayorPuntuacion(){


cout<<"asd";



}*/

int menu_principal()
{
    int total=5, opcionSeleccionada=0, tecla, valorMenu;
    bool salirMenu=true;
    const char *menuOpciones[] = {"1 jugador", "2 Jugadores", "Mayor puntaje", "Simulado", "Salir"};


    do
    {

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

        switch(tecla)
        {

        case TECLA_ABAJO:

            if(opcionSeleccionada==0)
            {

                opcionSeleccionada=4;
            }

            else
            {

                opcionSeleccionada--;
            }

            break;

        case TECLA_ARRIBA:

            if(opcionSeleccionada==4)
            {

                opcionSeleccionada=0;
            }

            else
            {

                opcionSeleccionada++;
            }

            break;

        case ENTER:

            salirMenu=false;
            valorMenu=opcionSeleccionada+1;
            break;
        }


    }
    while(salirMenu);

    return valorMenu;

}

void AcomodarDados(int Posicion[], int taman) /// Recibo el vector con las tres pociones cargadas
{
   int x,y; /// Inicializo X e Y, para luego usarlo con gotoxy

    for(int P=0; P<taman; P++) /// Compruebo la posicion del vector
    {

        switch(P)
        {

            case 0:
            x=1;
            y=7;
            pintarDados(Posicion,P,x,y); /// Envio el vector, con la posicion correspondiente e X y Y.

            break;

            case 1:

            x=9;
            y=7;
            pintarDados(Posicion,P,x,y);  /// Envio el vector, con la posicion correspondiente e X y Y.

            break;

            case 2:

            x=17;
            y=7;
            pintarDados(Posicion,P,x,y);  /// Envio el vector, con la posicion correspondiente e X y Y.

            break;


        }



    }






}

void unJugador()
{

    char nombre[15];

    system("cls");

    gotoxy(20,20);
    cout<<"Ingrese nombre: ";
    gotoxy(40,20);
    cin.getline(nombre,15);

    juegoD1(nombre, 15);

}

void juegoD1(char nombre[], int tam)
{

    int ronda=6, valorDados[3]= {0}, puntaje,Totalpuntos,Lanzamientos, LanzamientosFinales=0,TiradasFallidas=0, TiradasinP,Buncos=0,PuntajeFinal=0;

    for(int rondas=1; rondas<=ronda; rondas++)
    {
        puntaje=0;
        Totalpuntos=0;
        TiradasinP=0;
        Lanzamientos=0;
        do
        {
            system("cls");
            puntaje=tirarDados(valorDados, 3, rondas); /// Puntaje guarda lo que returna TirarDados
            Lanzamientos++;
            LanzamientosFinales++;


            if(puntaje==0) /// Si el puntaje que entra es 0, entonces sumo uno a tiradas sin puntaje.
            {
                TiradasinP++;
                TiradasFallidas++;
            }
            else
            {
                if(puntaje==21) /// Si el puntaje que entra es 21, entonces hubo Bungo y sumo uno mas
                {
                    Buncos++;
                }
            }

            Totalpuntos+=puntaje; ///Acumulo todo los puntos que me vaya returnando
            PuntajeFinal+=puntaje; /// Guarda todos los puntos que hubo en todas las rondas

           DatosDelJugador(nombre,Buncos,TiradasinP,Lanzamientos,PuntajeFinal,Totalpuntos,rondas);///Llamo a la funcion para que dibuje los datos actual del juego

       }
        while(Totalpuntos<21); /// Totalpuntos debe cumplir 21 puntos para pasar de ronda*/
        system("cls");
        EntreRondas(rondas, nombre ,15 ,Totalpuntos ,Buncos , TiradasinP, Lanzamientos); /// Dibuja los datos de la ronda finaliza, ejemplo cuando termina ronda 1, muestra todo los datos, despues avanza a la 2.
        system("pause");
        ///GrabarPuntuacion(nombre,15, Buncos,PuntajeFinal);

    }
     system("cls");

     PuntuacionFinal(nombre, 15, Buncos, TiradasFallidas, LanzamientosFinales, PuntajeFinal);///PARA QUE SIRVE?
     ///TablaFinal();
     system("pause");

}


int tirarDados(int valorDados[], int tama, int rondas)
{
 int puntajeT;

    srand(time(NULL));

    for(int t=0; t<tama; t++)
    {
        valorDados[t]= rand()%6+1;

    }
    AcomodarDados(valorDados,3);
    puntajeT=verificarJugadas(valorDados, 3, rondas); ///PuntajeT guarda el puntaje que retorna de verificarjugadas.

    return puntajeT;
}

int verificarJugadas (int valorDados[], int tam, int rondas)
{
    int puntaje=0, total=0; int bunco=0;


    for(int r=0; r<tam; r++)/// Suma todos los dados
    {
        total+=valorDados[r]; /// Valor total
    }

    for(int t=0; t<3; t++)
    {
        if(valorDados[t]==rondas) /// Verifica que dado es igual a la ronda y suma 1 punto por cada igual.
        {
            puntaje+=1;
        }
    }

    if((valorDados[0]==valorDados[1]+1) && (valorDados[1]==valorDados[2]+1)) /// Escalera mayor a menor
    {
        puntaje=2;
    }

    if((valorDados[0]==valorDados[1]-1) && (valorDados[1]==valorDados[2]-1)) /// Escalera menor a mayor
    {
        puntaje=2;
    }


    if(total%5==0) /// Jugada de 3 puntos
    {
        puntaje=3;
    }

    if(valorDados[0]==valorDados[1] && valorDados[2]==valorDados[0]) /// Comparo los tres dados para saber si son iguales, jugada 5 puntos
    {
        puntaje=5;
    }


    if((valorDados[0]==valorDados[1]) && (valorDados[2]==valorDados[0]) && (valorDados[0]==rondas)) /// Comparo los tres dados y el primero con la ronda
    {
       puntaje=21;
       bunco++;
    }



return puntaje;
}

void simulado()
{

    char nombre[15];

    system("cls");

    gotoxy(20,20);
    cout<<"Ingrese nombre: ";
    gotoxy(40,20);
    cin.getline(nombre,15);

    juegoSimulado(nombre, 15);

}

void juegoSimulado(char nombre[], int tam)
{

   int ronda=6, valorDados[3]= {0}, puntaje,Totalpuntos,Lanzamientos, LanzamientosFinales=0,TiradasFallidas=0, TiradasinP,Buncos=0,PuntajeFinal=0;

    ///recuadroGeneral();///solo recuadro, el nombre se coloca con gotoxy.


    for(int rondas=1; rondas<=ronda; rondas++)
    {
        puntaje=0;
        Totalpuntos=0;
        TiradasinP=0;
        Lanzamientos=0;
        do
        {
            system("cls");
            puntaje=tirarDadosSimulados(valorDados, 3, rondas); /// Puntaje guarda lo que returna TirarDados
            Lanzamientos++;
            LanzamientosFinales++;


            if(puntaje==0) /// Si el puntaje que entra es 0, entonces sumo uno a tiradas sin puntaje.
            {
                TiradasinP++;
                TiradasFallidas++;
            }
            else
            {
                if(puntaje==21) /// Si el puntaje que entra es 21, entonces hubo Bungo y sumo uno mas
                {
                    Buncos++;
                }
            }

            Totalpuntos+=puntaje; ///Acumulo todo los puntos que me vaya returnando
            PuntajeFinal+=puntaje; /// Guarda todos los puntos que hubo en todas las rondas

           DatosDelJugador(nombre,Buncos,TiradasinP,Lanzamientos,PuntajeFinal,Totalpuntos,rondas);///Llamo a la funcion para que dibuje los datos actual del juego

       }
        while(Totalpuntos<21); /// Totalpuntos debe cumplir 21 puntos para pasar de ronda*/
        system("cls");
        EntreRondas(rondas, nombre ,15 ,Totalpuntos ,Buncos , TiradasinP, Lanzamientos); /// Dibuja los datos de la ronda finaliza, ejemplo cuando termina ronda 1, muestra todo los datos, despues avanza a la 2.
        ///GrabarPuntuacion(nombre,15, Buncos,PuntajeFinal);
        ///PREGUTNAR SI PIDE LOS DATOS ENTRERONDA
    }
     system("cls");

     PuntuacionFinal(nombre, 15, Buncos, TiradasFallidas, LanzamientosFinales, PuntajeFinal);///PARA QUE SIRVE?
     system("pause");

}

int tirarDadosSimulados (int valorDados[], int tam, int rondas) /// Ingresa los dados en simulado
{
    int puntaje;
    for (int i=0; i<tam; i++)
    {
    cout<<"Ingrese el valor de los dados: "<<endl;
    cin>>valorDados[i];
    }
    system("cls");
    AcomodarDados(valorDados,3);
    puntaje=VerificarSimulado(valorDados, 3, rondas);


  return puntaje;
}

int VerificarSimulado(int valorDados[], int tam, int rondas) /// Verifica las jugadas del simulado.
{
int puntaje=0, total=0;


    for(int r=0; r<tam; r++)/// Suma todos los dados
    {
        total+=valorDados[r]; /// Valor total
    }

    for(int t=0; t<3; t++)
    {
        if(valorDados[t]==rondas) /// Verifica que dado es igual a la ronda y suma 1 punto por cada igual.
        {
            puntaje+=1;
        }
    }

    if((valorDados[0]==valorDados[1]+1) && (valorDados[1]==valorDados[2]+1)) /// Escalera mayor a menor
    {
        puntaje=2;
    }

    if((valorDados[0]==valorDados[1]-1) && (valorDados[1]==valorDados[2]-1)) /// Escalera menor a mayor
    {
        puntaje=2;
    }


    if(total%5==0) /// Jugada de 3 puntos
    {
        puntaje=3;
    }

    if(valorDados[0]==valorDados[1] && valorDados[2]==valorDados[0]) /// Comparo los tres dados para saber si son iguales, jugada 5 puntos
    {
        puntaje=5;
    }


    if((valorDados[0]==valorDados[1]) && (valorDados[2]==valorDados[0]) && (valorDados[0]==rondas)) /// Comparo los tres dados y el primero con la ronda
    {
        puntaje=21;
    }

    return puntaje;
}

/*
void GrabarPuntuacion(nombre,15, Buncos,PuntajeFinal){

char ListaNombres[6];


for(int a=6; a<0; a--){

    if(PuntajeFinal>puntos[])


}



}*/

#endif // JUGADAS_H_INCLUDED
