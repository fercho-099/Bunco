#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "jugadas.h"


using namespace std;

int main()
{

   int seleccion;
   bool salir=true;


do{



seleccion=menu_principal();

switch(seleccion){

case 1:

    unJugador();

    break;

/*case 2:

   dosJugadores();

    break;

case 3:

    MayorPuntuacion();

    break;*/

case 4:

    simulado();

    break;

case 5:

    salir=false;


}

}while (salir);


system("pause");

    return 0;
}
