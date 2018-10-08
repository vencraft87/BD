#ifndef BD_H
#define BD_H

typedef struct punteroTabla * arrayTablas;

typedef struct tabla Tabla;

typedef struct columna * arrayColumnas;

typedef struct punteroTupla * arrayTuplas;

typedef struct celda * Tupla;

//Array de punteros a Tablas 
arrayTablas creaPunteroTablas();

Tabla cabezaPunteroTablas(arrayTablas arr_Tablas);

arrayTablas colaPunteroTablas(arrayTablas arr_Tablas);

bool arrayTablasVacia(arrayTablas arr_Tablas);

arrayTablas agregaTabla(arrayTablas arr_Tablas, Tabla tabla); // agrega elemento tabla en arrayTabla

//Tablas - struct que contiene nombre, array de columnas, y array de tuplas
bool existeTabla(arrayTablas arr_Tablas,char *nombreTabla);

arrayTablas creaTabla(arrayTablas arr_Tablas, char *nombreTabla);

bool tablaVacia(); // fijarse si tupla es vacia

void imprimeTablas(arrayTablas arr_Tablas);

//Array de Columnas
void creaColumna();

void cabezaColumna();

void colaColumna();

bool columnaVacia();

void agregaColumna();

//Array de Tuplas - contendrán una lista de celdas
void creaTupla();

void cabezaTupla();

void colaTupla();

bool tuplaVacia();

void agregaTupla(); //agregar tupla al principio o al final de la lista?, evaluar... (al principio no se precisa recorrer toda)

//Celdas
void creaCelda();

void cabezaCelda();

void colaCelda();

bool celdaVacia();

void agregaCelda();

//otras funciones auxiliares
//faltan todas las de comprobacion 

#endif

