#include <iostream>
#include <list>
#include <string>
#include "Tupla.h"
#include "Pagina.h"
#include "Archivo.h"

using namespace std;

int main(){
	Tupla t1 = Tupla("Juan Camilo","Ruiz Ortiz","12345","MACC");
	string idA = "a1";
	list<string> nombres = {"Nombres","Apellidos","ID_estudiante","Carrera"};
	list<string> tiposDatos = {"varchar(20)","varchar(20)","varchar(20)","varchar(20)"};
	list<bool> isFixed_array = {false,false,false,false};
	Archivo a = Archivo(idA,nombres,tiposDatos,isFixed_array);

	a.insertarTupla(t1);



	return 0;
}



