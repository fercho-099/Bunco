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

void tirarDados(int [], int, int );

int verificarJugadas (int [], int , int);


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

    int ronda=6, valorDados[3]= {0}, puntaje;

    /**recuadroGeneral();///solo recuadro, el nombre se coloca con gotoxy.
    dadosDibujo();///para que dibuje los dados iniciales.*/

    for(int rondas=1; rondas<=ronda; rondas++)
    {

        puntaje=0;

        /*do
        {*/
            system("cls");
            tirarDados(valorDados, 3, rondas);

            /*puntaje=puntos();*/

            puntaje=verificarJugadas(valorDados, 3, rondas);

       /* }
        while(puntaje<=21); /// cada ronda debe cumplir con los 21 puntos*/

        cout<<"Puntaje obtenido: "<<puntaje<<endl;
        cout<<"Ronda "<<rondas<<endl;
        system("pause");

    }

///pondria return o no, vemos que nos sirve.


}


void tirarDados(int valorDados[], int tama, int rondas)
{


    srand(time(NULL));

    for(int t=0; t<tama; t++)
    {

        valorDados[t]= rand()%6+1;

    }

    verificarJugadas(valorDados, 3, rondas);///aca debe retornar a la funcion juegoD1 y despues ir a verificar

}

int verificarJugadas (int valorDados[], int tam, int rondas )
{

    int puntaje=0, total=0, bunco=0, noCoincidentes=0, escalera=0, divisiblepor5=0, coincidente=0, vectorJugadas[5]={0}, vectorSinjugadas=0;
    int aux=valorDados[0], aux1=valorDados[1], aux2=valorDados[2], p, pp;


    for(int r=0; r<tam; r++)
    {

        total+=valorDados[r];///suma para saber si es divisble por 5
    }
    ///divisible por 5
    if(total % 5 == 0)
    {
    vectorJugadas[3]=3;///2
    divisiblepor5=1;
    }

    ///bunco
    if((aux==aux1) && (aux1 ==aux2) && (aux==rondas))
    {
    vectorJugadas[1]=1;///0
    bunco=1;
    }

    ///no coinciden con ronda
    if(((aux==aux1) && (aux==aux2)) != rondas)
    {
    vectorJugadas[2]=2;///1
    noCoincidentes=1;
    }

    ///dados que coinciden
    for(int t=0; t<3; t++){


        if(valorDados[t]==rondas){

            vectorJugadas[4]+=1;
            /*dadosCoinciden++;///dados que coinciden con la ronda sin formas bunco ni 3 iguales*/
        }
    }




///BENDITA SEA LA ESCALERA



if(aux>aux1) ///arbol 1
{

    if(aux>aux2) ///sub-arbol 1, alternativa 1, t1
        {

            p=aux1+1;///condicion de alternativa 1
            pp=aux2+2;///conicion de alternativa 1

            if((aux==p) && (aux==pp)) ///verificacion de alternativa 1
            {

                vectorJugadas[4]=4;///3
                escalera=1;

            }

            else
            {

                p=aux1+2;
                pp=aux2+1;

                if((aux==p) && (aux==pp)) ///arbol 2, alternativa 2 t1
                {
                    vectorJugadas[4]=4;///3
                    escalera=1;
                }
            }

        }

        else /*if(aux<aux2)*/ ///arbol 1 alternativa 1, t2
        {

            p=aux1+1;
            pp=aux2-1;

            if((aux==p) && (aux==pp))
            {
                vectorJugadas[4]=4;///3
                escalera=1;///o se inicia con 0 y cuando es verdadero le asignamos 1 o le mandamos un else que de valor escalera falso

            }

        }

    }

    else /*if (aux<aux1)*/ ///arbol 2
    {

        if(aux>aux2) ///sub-arbol 2, t2
        {

            p=aux1-1;
            pp=aux2+1;

            if((aux==p) && (aux==pp))
            {
                vectorJugadas[4]=4;///3
                escalera=1;

            }
        }


        else /*if(aux<aux2)*/
        {

            if(aux1>aux2)
            {

                p=aux1-2;
                pp=aux2-1;

                if((aux==p)  && (aux==pp))
                {
                    vectorJugadas[4]=4;///3
                    escalera=1;

                }

            }

            else
            {

                p=aux-1;
                pp=aux2-2;

                if((aux1==p) && (aux2==pp))
                {
                    vectorJugadas[4]=4;///3
                    escalera=1;
                }
            }


        }



    }

///bendita sea la escalera


    for(int y=1; y<=5; y++){


        switch(vectorJugadas[y]){


            case 1:

                puntaje=21;
                y=5;

            break;

            case 2:

                puntaje=5;

                y=5;

            break;

            case 3:

                puntaje=3;

                y=5;

            break;

            case 4:

                puntaje=2;
                y=5;

            break;

            case 5:

                puntaje=vectorJugadas[y];


            break;

            case 0:

                vectorSinjugadas++;

                if(vectorSinjugadas==3){

                puntaje=8;


                }

            }

    }



return puntaje;
}



#endif // JUGADAS_H_INCLUDED
