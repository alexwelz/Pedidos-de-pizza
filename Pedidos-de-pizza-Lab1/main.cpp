#include <iostream>
using namespace std;
#include <cstdlib>
#include "funciones.h"
/*
Una pizzería dispone de la información de los pedidos recibidos en el último mes. Por cada
pedido se registró:

- Número de pedido (entero)
- Número de pizza (1 a 10)
- Número de localidad de envío (1 a 20 ó 0 para retiro por el local)
- Número de cliente (100 a 250)
- Forma de pago ('E' - Efectivo, 'T' - Tarjeta)
- Importe (float)

Aclaraciones

- Las pizzas con números entre 1 y 3 son veganas. Y las pizzas con números entre 1 y 5 son
vegetarianas.
- La localidad de envío con número 0 (cero) significa que el cliente retiró el pedido por el
local.
- Hay sólo una pizza en un pedido.

El fin de los datos se indica con un número de pedido igual a 0. Los datos no están
agrupados ni ordenados.

Calcular e informar:

A) Los números de clientes que nunca hayan abonado con efectivo.
B) Por cada tipo de pizza, el total recaudado en efectivo y el total recaudado en tarjeta.
Ejemplo:
Pizza Efectivo Tarjeta
1 $ xxx.xx $xxx.xx
2 $ xxx.xx $xxx.xx
. . .
10 $ xxx.xx $xxx.xx

C) La cantidad de clientes distintos que hayan retirado al menos un pedido por el local.
Aclaración:
Esto significa que si el cliente 100 retiró 5 pedidos por el local sólo debe ser tenido
en cuenta una sola vez.
*/

int main() {
    setlocale(LC_ALL, "Spanish");

    const int CLIENTES=151; //Es 151 por que hacemos 250-100= 150 y como el vector es siempre base -1 para contar todos los clientes se agrega uno mas

    int opcion, Exit;

    int nPedido, nPizza, lEnvio, ncliente;
    char fPago;
    float importe;

    //A
    bool Vcliente[CLIENTES]= {false};

    //B
    int Vefectivo[10]= {}, Vtarjeta [10]={};

    //C
    bool VbanC[CLIENTES]={false};
    int contLocal=0;


    while(true)
    {
        MenuPrincipal();


        cout<<endl<<"Ingrese opcion: "<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            cout<<endl<<"Ingrese numero de pedido: "<<endl;
            cin>>nPedido;
            while (nPedido !=0)
            {
                cout<<endl<<"Ingrese numero de pizza: "<<endl;
                cin>>nPizza;
                cout<<endl<<"Ingrese la localidad de envio: "<<endl;
                cin>>lEnvio;
                cout<<endl<<"Ingrese numero de cliente: "<<endl;
                cin>>ncliente;
                cout<<endl<<"Ingrese forma de pago: "<<endl;
                cin>>fPago;
                cout<<endl<<"Ingrese el importe: "<<endl;
                cin>>importe;

                //A
                if(fPago == 'E'||'e')
                {
                    Vcliente[ncliente - 100]=true;
                }

                //B
                if(nPizza == 'E' || 'e')
                {
                    Vefectivo[nPizza-1]+= importe;
                }
                else
                {
                    Vtarjeta[nPizza -1] += importe;
                }

                //C
                if(lEnvio ==0)
                {
                    VbanC[ncliente - 100]= true;//ingresa el usuario (ncliente = 100) - 100= 0 posicion vector 0
                }


                cout<<endl<<"Ingrese numero de pedido: "<<endl;
                cin>>nPedido;
            }




            break;

        case 2:
            for(int x=0; x< CLIENTES; x++)
            {
                if(Vcliente[x]== false)
                {
                    cout<<endl<<"El N° de cliente "<< x+100<<" nunca abono en efectivo"<<endl;//posicion vector 0 +100 =100. Como le reste en la operacion mas arriba al mostrar se le suma
                }
            }
            system("pause>nul");
            break;

        case 3:
            cout<<"   Pizza          Efectivo               Tarjeta";
            for (int x=0; x<10; x++)
            {
                cout<< x+1 << "  "<< Vefectivo[x] <<"   " <<Vtarjeta[x]<<endl;// [x] seria por cada vuelta del for de 0 a 9. x+1 para que se acomode el vector al usuario de 1 a 10

            }

            system("pause>nul");
            break;

        case 4:
            for(int x=0; x< CLIENTES; x++)
            {
                if(VbanC[x]== true)
                {

                    contLocal++;
                }
            }
            cout<<endl<< "La cantidad de clientes que retiraron al menos un pedido por el local fueron: "<<contLocal<<endl;

            system("pause>nul");
            break;

        case 0:
            cout<<endl<<"Estas seguro que quieres salir? \n 1- Menu Principal \n 0- Exit"<<endl;
            cin>>Exit;

            if(Exit==0)
            {
                return 0;
            }

            break;

        }
        system("cls");


    }

    system("pause>nul");
    return 0;


}
