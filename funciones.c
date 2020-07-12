/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <stdlib.h>
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
int promedio (float total, float k)//total / k, donde k es la cantidad de materias
{
    int r = total / k;//guardo el entero de la division
    float x = total / k, aux; //guardo la division con decimales
    aux = x - r; // me quedo solamente con los decimales de la division y 0 en la parte de entero.
    if(aux < 0.5)//En caso que el resultado sea menor que 0.5
        return r;//retorno la parte entera de la division, es decir, redondeo para abajo
    return r+1;//si no, incremento en 1 el entero de la division, es decir, redondeo para arriba.
}

char* strcpy_(char *s1, const char *s2)
{
    char *aux=s1;
    while (*s2)
        *s1++ = *s2++;

    *s1=*s2;
    return (char*)aux;
}

void nodoMayorOcurrencia (tNodo* nodMov, char* clave, int(*comparar)(const void*, const void*))
{
    int mayorApariciones=0, // Cuenta cuantas veces aparece el que aparecio mas veces
        contadorApariciones=0;// contador apariciones individual por clave

    tNodo* nodReset = nodMov;//Nodo que tengo para volver al incio de la lista.
    char cadComparada[11];//En esta cadena voy a ir guardando las claves que estoy contando sus apariciones

    while (nodMov->sig){//el ultimo ya lo voy a tener contemplado por eso no lo analizo
        strcpy_(cadComparada, nodMov->info);//Tengo la clave del primer nodo
        while (nodMov){
            if (!comparar(cadComparada, nodMov->info))//si hubo coincidencia
                contadorApariciones++;//incremento el contador de apariciones
            nodMov = nodMov->sig;//avanzo el puntero
        }
        if (contadorApariciones>mayorApariciones){
            mayorApariciones = contadorApariciones;
            strcpy_(clave, cadComparada);//guardo en clave la cadena que por el momento aparecion mas veces
        }
        nodMov = nodReset = nodReset -> sig;//Avanzo el nodo Reset e igualo al nodo movimiento a la siguiente sub lista
        contadorApariciones = 0;// Reseteo el contador de apariciones
    }
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    tFinal* aux = (tFinal *) d;
    if(!aux)//En caso de mandar un puntero NULL podemos imprimir el encabezado con la misma funcion
        fprintf(fp," D. N. I.  Apellido(s), Nombre(s)\t  CodM Cal\n");

    else
       fprintf(fp,"%*s %-*s %4d %2d\n", (int)sizeof(aux->dni)-1, aux->dni,(int)sizeof(aux->apYNom)-1,aux->apYNom,aux->codMat,aux->calif);

}


int  compararFinal_MIO(const void *d1, const void *d2)  //Un caso curioso es que de la manera en que está planteado el tipo de dato tFinal, esta resolución es suficiente para comparar.
                                                        //No tengo necesidad de castear un tFinal, porque la cadena de DNI está primera que el resto de datos.
{
    const char* s1 = d1,* s2 = d2;
    while (*s1 && *s1==*s2){//Cuando no sea la misma cadena el programa retorna un valor distinto de 0.
        s1++;
        s2++;
    }
    return *(char*)s1- *(char*)s2; // Retorna la resta entre los caracteres en los cuales no son iguales.
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    tFinal **finDest = (tFinal**) dest;
    tFinal *finOri = (tFinal*) orig;
    (*finDest)->calif += finOri->calif;
    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)//estoy pasando la estructura acumulada.
{
    tFinal *aux = (tFinal *) d2;
    fprintf(fp, "   --- Rindio  %d final(es) con un promedio de:  %d\n\n",cantCalif,promedio(aux->calif,cantCalif));
}


/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    tNodo *aux = *p;
    int cant = 0;
    if(aux){
        mostrar(NULL,fp);
        while(aux->ant)
            aux = aux->ant;

        while(aux){
            mostrar(aux->info,fp);
            aux = aux->sig;
            cant++;
        }
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    if (!*p)
        return;

    tNodo* nodMov = *p;//Nodo con el cual voy a ir recorriendo la lista desordenada
    char auxCad [11];//Cadena que voy a usar para la comparacion
    while (nodMov->ant)//me muevo al principio de la lista
        nodMov = nodMov->ant;

    tNodo* nodFirst = nodMov;//NODFIRST es el nodo que va a apuntar al primer Nodo de la lista desordenada
    tNodo* nodOrd = NULL;//El Nodo de la lista una vez ordenada. Va a ser NULL porque el anterior del primer ordena tiene que apuntar a NULL

    while (nodFirst->sig){
        nodoMayorOcurrencia(nodFirst, auxCad, comparar);//BIEN

        while(nodMov){
            if(!comparar(auxCad, nodMov->info)){
                if(nodMov==nodFirst)//En caso de que este parado en el primero y este sea uno a desenganchar muevo el puntero first.
                    nodFirst=nodFirst->sig;
                //-----desenganche-del-nodo-----//
                tNodo* ant = nodMov->ant,* sig = nodMov->sig;
                //USAR NODO SIG COMO MARCA//
                if (ant)
                    ant->sig = sig;
                if (sig){
                    sig->ant = ant;
                    *p = sig;
                }
                else
                    *p = ant;
                //-----desenganche-del-nodo-----//
                nodMov->ant = nodOrd;//EL ANTERIOR DEL NODO QUE DESENGANCHO VA A SER LO QUE APUNTE ORDEANDO
                if(nodOrd)//En caso de que el puntero no sea nulo tengo que apuntar su sig al nodo que le engancho
                    nodOrd->sig = nodMov;
                nodOrd = nodMov;
                nodMov = sig;//Resetie el nodo movimiento para poder seguir buscando desde aca y no tener que recorrer lo que ya recorri
                nodOrd->sig = nodFirst;//engancho el ultimo de la lista ordenada ->
                nodFirst->ant = nodOrd;//-> con el primero de la lista desordenada.
            }
            else
                nodMov = nodMov->sig;//Avanzo el nodo movimiento
        }
        nodMov = nodFirst;//Muevo al principio de la lista ordenada el nodMov para volver a arrancar
       ///ESTO TENGO QUE HACERLO SOLO SI EL PRIMERO QUE ENGANCHE ERA NODO A MOVER!!!!!!!!!!!///
        //nodMov = nodMov->sig //AVANZO EL PUNTERO MOVIMIENTO
    }

}


int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    if (!*p)//Controlo que la lista no este vacia
        return 0;

    int contTotal = 0, cantMaterias;//contador de materias por alumno
    tNodo* nodMov = *p;//Una vez que tengo el puntero a lista en el principio lo igualo al nodo

    while (nodMov->ant)//me muevo al principio de la lista
        nodMov = nodMov->ant;

    while (nodMov){
        tFinal aux;
        tFinal* pAux = &aux;


        aux.calif = 0;//seteo en 0 las calificaciones. Las voy a usar como acumuladores
        strcpy_(aux.dni, nodMov->info);//copio el dni en la estructura auxiliar

        mostrar(NULL, fp);//Imprimo el encabezado
        cantMaterias = 0;//Reseteo la cantidad de materias por alumno, variable que uso para el promedio


        do{//Utilizo un DO porque si hay lista quiere decir que hay un puntero si o si. Por lo tanto aunque sea 1 nodo tendre.


            acumular((void*)&pAux,NULL, nodMov->info, (unsigned)NULL);///BIEN
            mostrar(nodMov->info,fp);///BIEN

            tNodo* nodAux = nodMov->sig;

            free(nodMov->info);
            free(nodMov);

            nodMov = nodAux;

            cantMaterias++;
            contTotal++;
        }while (nodMov && !comparar(aux.dni,nodMov->info));//Mientras haya nodo y que sean el mismo DNI sigo acumulando

        mostrar2(&aux,cantMaterias, fp);
    }
    *p = NULL;//Como la lista esta vacia seteo a la "fuerza" el puntero de la lista a NULL
    return contTotal;
}
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

