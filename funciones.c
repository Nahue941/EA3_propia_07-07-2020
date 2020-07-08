/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/


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


int  compararFinal_MIO(const void *d1, const void *d2)
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
    tNodo *act = *p;
    int cant = 0;
    if(act){
        mostrar(NULL,fp);
        while(act->ant)
            act = act->ant;

        while(act){
            mostrar(act->info,fp);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}

/**
void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{

}
 **/

int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    int contTotal = 0, cantMaterias;//contador de materias por alumno
    while(*p){
        tFinal aux;//lo voy a usar para acumular y comparar
        tFinal* paux = &aux;

        tNodo* nodoAct = *p;

        aux.calif = 0;//seteo en 0 las calificaciones. Las voy a usar como acumuladores
        strcpy_(aux.dni, nodoAct->info);//copio el dni en la estructura auxiliar

        mostrar(NULL, fp);//Imprimo el encabezado
        cantMaterias = 0;
        do{//Utilizo un DO porque si hay lista quiere decir que hay un puntero si o si. Por lo tanto aunque sea 1 nodo tendre.

            acumular((void*)&paux,NULL, nodoAct->info, (unsigned)NULL);///BIEN

            mostrar((*p)->info,fp);
            /////eliminando nodo/////
            tNodo* elimAnt = nodoAct->ant,* elimSig = nodoAct->sig;

            if(elimAnt){
                elimAnt->sig = elimSig;
                *p = elimAnt;
            }
            if(elimSig)
                elimSig->sig = elimAnt;

            else
                *p = elimAnt;
            free(nodoAct->info);
            free(nodoAct);

            cantMaterias++;
            contTotal++;
        }while (comparar(aux.dni,nodoAct->info));//Mientras que sean el mismo DNI sigo acumulando
        /**AL PARECER ESTOY PASANDO MAL EL SEGUNDO ARGUMENTO. CON LA FUNCION DE LOPEZ LA FUNCION DE COMPRAR FUNCIONA PERO
        CON LA MIA NO. REEVER QUE PARAMETROS PASO.**/

        mostrar2(&aux,cantMaterias, fp);
    }
    return contTotal;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

