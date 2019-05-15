#include <iostream>
#include <list>
#include <string>
#include "Tupla.h"
#include "Pagina.h"
#include "Archivo.h"

using namespace std;

int main(){
	Tupla t1 = Tupla("Juan Camilo","Ruiz Ortiz","12345","MACC");
	Tupla t2 = Tupla("Miguel","Valencia","3333","MACC");
	string idA = "a1";
	list<string> nombres = {"Nombres","Apellidos","ID_estudiante","Carrera"};
	list<string> tiposDatos = {"varchar(20)","varchar(20)","varchar(20)","varchar(20)"};
	list<bool> isFixed_array = {false,false,false,false};
	Archivo a = Archivo(idA, nombres, tiposDatos, isFixed_array);

	a.insertarTupla(t1);
	a.insertarTupla(t2);

	a.printArchivo();
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
	//cout << t1.getIDTupla() << endl;

	string idT1 = "Juan CamiloRuiz Ortiz12345MACC";
	a.eliminarTupla(idT1);
	a.printArchivo();



	return 0;
}



