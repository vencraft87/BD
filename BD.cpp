#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Datos en tuplas
struct celda{
	char * dato;
	celda * sig;
};
typedef struct celda * Tupla;
//Array de tuplas
struct punteroTupla{
	Tupla celdas;
	punteroTupla * sig;
};
typedef struct punteroTupla * arrayTuplas;
//Array de columnas
struct columna{
	char * nombre;
	columna * sig;
};
typedef struct columna * arrayColumnas;
//Estructura de tabla
struct tabla{
	char * nombre; // cambiar por char* y ver como insertar alli
	arrayColumnas columnas;
	arrayTuplas tuplas;
};

typedef struct tabla Tabla;
//Array de Tablas
struct punteroTabla{
	Tabla tabla;	
	punteroTabla * sig;
};
typedef struct punteroTabla * arrayTablas;


//operaciones sobre arreglo tablas
arrayTablas creaPunteroTablas(){
	return NULL;
}
Tabla cabezaPunteroTablas(arrayTablas arr_Tablas){
	return arr_Tablas->tabla;
}
arrayTablas colaPunteroTablas(arrayTablas arr_Tablas){
	return arr_Tablas->sig;
}
bool arrayTablasVacia(arrayTablas arr_Tablas){
	return arr_Tablas == NULL;
}
void agregaTabla(arrayTablas &arr_Tablas, Tabla t){
	arrayTablas aux = new punteroTabla;
	aux->tabla = t;
	aux->sig = arr_Tablas;
	arr_Tablas = aux;
//	return arr_Tablas;
}


//operaciones sobre tablas

bool existeTabla(arrayTablas arr_Tablas, char *nombreTabla){
//	cout << "En existeTabla \n";
	if(arrayTablasVacia(arr_Tablas)){
//		cout << "En if de tabla no existe\n";
		return false;		
	}
	else
	{
		while ((arr_Tablas != NULL) && ((strcmp(arr_Tablas->tabla.nombre, nombreTabla)) != 0)){
//			cout << "\n";
//			cout <<  arr_Tablas->tabla.nombre << " - ";
//			cout <<  nombreTabla << "\n";
//			cout << "Entra al while buscando si la tabla existe \n";
			arr_Tablas = arr_Tablas->sig;
		}
		if (arr_Tablas == NULL){
//			cout << "Termina while sin encontrar nombre de tabla \n";
			return false;
		}
		else
		{
//			cout << "Termina while porque encontro el mismo nombre\n";
			return true;
		}
	}
//	cout << "Fin de existeTabla \n";
}
arrayColumnas creaColumna(){
	return NULL;
}


arrayTablas creaTabla(arrayTablas arr_Tablas, char *nombreTabla){
//	cout << "En creaTabla\n";
	if(existeTabla(arr_Tablas, nombreTabla)){
		cout << "Error ya existe tabla\n";
		return arr_Tablas;
	}
	else
	{
//		cout << "creaTabla: no existe tabla, la crea\n";
		Tabla tab;
		tab.nombre = nombreTabla;
		tab.columnas = creaColumna();
	    agregaTabla(arr_Tablas, tab);
	    return arr_Tablas;
	}
//	cout << "Finaliza creaTtabla\n";
}
//ver que va a hacer
bool tablaVacia(){
}
char * cabezaColumna(arrayColumnas arr_columnas){
	return arr_columnas->nombre;
}
arrayColumnas colaColumna(arrayColumnas arr_columnas){
	return arr_columnas->sig;
}
bool columnaVacia(arrayColumnas arr_columnas){
	return arr_columnas == NULL;
}
arrayColumnas agregaColumna(arrayColumnas arr_columnas, char * nombreColumna){
	arrayColumnas aux = new columna;
	aux->nombre = nombreColumna;
	aux->sig = arr_columnas;
	arr_columnas = aux;
	return arr_columnas;
}
void imprimirColumnas(arrayColumnas array_columnas){
	if(array_columnas != NULL){
		cout << cabezaColumna(array_columnas) << "\n";
		imprimirColumnas(colaColumna(array_columnas));
	}
}
	
arrayColumnas agregaColumnaFinal(arrayColumnas arr_columnas, char * nombreColumna){
	if(columnaVacia(arr_columnas)){
		return agregaColumna(arr_columnas, nombreColumna);
	}
	else
	{
		return agregaColumna(agregaColumnaFinal(colaColumna(arr_columnas), nombreColumna), nombreColumna);
	}
} 

//agrega columna desde array
void addCol(arrayTablas arr_Tablas, char * nombreTabla, char * nombreColumna){
	arrayTablas aux = new punteroTabla;
	aux = arr_Tablas;
	bool fin = false;
	while(!fin){
		if(aux != NULL){
			if((strcmp(aux->tabla.nombre, nombreTabla) != 0)){
				aux = aux->sig;
			}
			else
			{
				agregaColumnaFinal(aux->tabla.columnas, nombreColumna);
				fin = true;			
			}
		}
		else
		{
			fin = true;
			cout << "No existe columna. \n";
		}
	}
}





void imprimeTablas(arrayTablas arr_Tablas){
	if(arr_Tablas != NULL){
		cout << cabezaPunteroTablas(arr_Tablas).nombre << "\n";
		imprimeTablas(colaPunteroTablas(arr_Tablas));
	}
}





//Revisar esta función
string get_str_between_two_str(const string &s, const string &start_delim, const string &stop_delim){
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find_first_of(stop_delim, end_pos_of_first_delim);

    return s.substr(end_pos_of_first_delim,last_delim_pos - end_pos_of_first_delim);
}

// Optimizar estas dos funciones!
char * copiarChar(char *s){
	char *copy = new char[(strlen(s)+1)];
	return 	strcpy(copy,s); 
}
char * cambiaAChar(string s){
	int n = s.length();
	//char char_array[n+1];
	char * char_array = new char[n+1];
	strcpy(char_array, s.c_str());
	return char_array;
}

int main(){
	
	arrayTablas at = creaPunteroTablas();

	char * tabla1 = (char *) "tabla1";
	at = creaTabla(at, tabla1);
	imprimeTablas(at);
	addCol(at, (char*) "tabla1", (char*) "CI");	


	string comando;
	string str;
	string start;
	string stop;

	do {
		cout << "Ingrese un comando: \n";
		getline(cin, str);
		comando = str.substr(0, str.find(' '));
		
		if(comando == "createTable"){
			start = "(";
			stop = ")";
			str = get_str_between_two_str(str, start, stop);
//			cout << str << " \n";
			at = creaTabla(at,copiarChar(cambiaAChar(str)));
			imprimeTablas(at);
		}else if (comando == "dropTable"){
			cout << "Borrar tabla. \n";
		}else if(comando == "addCol"){
			cout << "Agregar columna. \n";		
		}else if(comando == "dropCol"){
			cout << "Borrar columna. \n";			
		}else if(comando == "insertInto"){
			cout << "Insertar tupla \n";			
		}else if(comando == "deleteFrom"){
			cout << "Eliminar tupla \n";
		}else if(comando == "update"){
			cout << "Actualizar tupla. \n";
		}else if(comando == "printDataTable"){
			cout << "Imprimir tabla.\n";
			imprimeTablas(at);
		}else if(comando == "end"){
			
		}else{
			cout << "Comando erroneo.\n";
		}		
		
			
	}while (comando != "end");
/*
	
	
	char * tabla1 = (char *) "Uno";
	at = creaTabla(at, tabla1);
	char * tabla2 = (char *) "Dos";
	at = creaTabla(at, tabla2);	
	char * tabla3 = (char *) "";
	at = creaTabla(at, tabla3);	
	char * tabla4 = (char *) "Uno";
	at = creaTabla(at, tabla4);	
	char * tabla5 = (char *) "Cinco";
	at = creaTabla(at, tabla5);
	imprimeTablas(at);
	
*/
	
	return 0;
}
