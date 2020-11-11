#ifndef JUGADAS_H_INCLUDED
#define JUGADAS_H_INCLUDED
#include "rlutil.h"
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "dibujodados.h"
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

///void pintarDados(int [], int);

void juegoD1(char [], int );

int tirarDados(int [], int, int);

int verificarJugadas (int [], int, int);

void simulado ();

void juegoSimulado(char [], int );

void tirarDadosSimulados( int [], int, int );

int menuJuego();
///implementacion de funciones


int menu_principal()
{

    int total=5, opcionSeleccionada=0, tecla, valorMenu;
    bool salirMenu=true;
    const char *menuOpciones[] = {"1 jugador", "2 Jugadores", "Mayor puntuacion", "Simulado", "Salir"};


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

int menuJuego()
{

    const char *SeleccionenJuego[] = {"Lanzar dados", "Terminar juego"};
    int total=2, opcionSeleccionado=0, tecla, miniMenu=0, opcion;
    bool salirMenu=true;

    ///dibujoMarcoJuego();

    do
    {

        system("cls");
        gotoxy(20,8+opcionSeleccionado);
        cout<<"<---";

        for(int p=0; p<total; p++)
        {

            gotoxy(3,8 + p);
            cout<<SeleccionenJuego[p];

        }

            do
            {
                tecla=getch();

            }
            while(tecla != TECLA_ABAJO && tecla != TECLA_ARRIBA && tecla != ENTER);

            switch(tecla)
            {

            case TECLA_ABAJO:

                if(opcionSeleccionado==0)
                {

                    opcionSeleccionado=1;
                }

                else
                {

                    opcionSeleccionado--;
                }

                break;

            case TECLA_ARRIBA:

                if(opcionSeleccionado==1)
                {

                    opcionSeleccionado=0;
                }

                else
                {

                    opcionSeleccionado++;
                }

                break;

            case ENTER:

                salirMenu=false;
                miniMenu=opcionSeleccionado+1;

            }



    }while(salirMenu);

    switch(miniMenu){


        case 1:

                opcion=1;

                break;

        case 2:

                opcion=2;

        }

    return opcion;

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

    int ronda=6, valorDados[3]= {0}, puntaje;


    for(int rondas=1; rondas<=ronda; rondas++)
    {

        puntaje=0;

        do
        {
        system("cls");

        tirarDadosSimulados(valorDados, 3, rondas);

        puntaje=verificarJugadas(valorDados, 3, rondas);

         }while(puntaje<=21); /// cada ronda debe cumplir con los 21 puntos*/

        cout<<"Puntaje obtenido: "<<puntaje<<endl;
        cout<<"Ronda "<<rondas<<endl;
        system("pause");

    }

}

void tirarDadosSimulados (int valorDados[], int tam, int rondas)
{

    for (int i=0; i<tam; i++)
    {

        cin>>valorDados[i];
    }

    verificarJugadas(valorDados, 3, rondas);
}

void juegoD1(char nombre[], int tam)
{

    int ronda=6, valorDados[3]= {0}, puntaje=0, Totalpuntos, opcion, tiradasFallidas=0, puntosObtenidos;
    bool terminar=true;
    ///recuadroGeneral();///solo recuadro, el nombre se coloca con gotoxy.
    ///dadosDibujo();///para que dibuje los dados iniciales.

    for(int rondas=1; rondas<=ronda; rondas++)
    {

        Totalpuntos=0;
        tiradasFallidas=0;

        do
        {
            ///system("cls");

            opcion=menuJuego();

        switch(opcion){

        case 1:

            puntosObtenidos=tirarDados(valorDados, 3, rondas);

           if(puntosObtenidos==0){

            tiradasFallidas++;

           }

           else{

            Totalpuntos+=puntosObtenidos;

           }

            break;

        case 2:

            terminar=false;

                }
            /// Puntaje guarda lo que returna TirarDados
            ///Totalpuntos+=puntaje; ///Acumulo todo los puntos que me vaya returnando


        }while(Totalpuntos<=21 || terminar==false);  /// Totalpuntos debe cumplir 21 puntos para pasar de ronda

        puntaje+=Totalpuntos;

    }

      ///anotacion final
      system("cls");
      cout<<"Total puntos: "<<puntaje<<endl;
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
    pintarDados(valorDados,3);
    puntajeT=verificarJugadas(valorDados, 3, rondas); ///PuntajeT guarda el puntaje que retorna de verificarjugadas.

    return puntajeT;
}

int verificarJugadas (int valorDados[], int tam, int rondas)
{
    int puntaje=0, total=0;
    int bunco=0;


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


#endif // JUGADAS_H_INCLUDED
