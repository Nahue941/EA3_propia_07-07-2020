/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

int promedio (float total, float k)//total / k, donde k es la cantidad de materias
{
    int r = total / k;
    float x = total / k, aux; //5.54
    aux = x - r; // saco parte entera;
    if(aux < 0.5)
        return r;
    return r+1;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    tFinal *aux = (tFinal *) d;
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
/**
int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{

}
 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

