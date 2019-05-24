/*
 * Tabla.cpp
 *
 *  Created on: May 11, 2019
 *      Author: lovelace
 */
#include "Tabla.h"
#include <list>


const int n=3;

Tabla::Tabla(std::string nombre){
	identificador = nombre;
	indice = ArbolB(n);
}

Tabla::~Tabla(){
}

void Tabla::insertar_tupla(Tupla tup){
		tuplas.push_back(tup);
		indice.insertar(tup.getid(), &tup);

}
void Tabla::eliminar_tupla(int ID){
		//tuplas.remove(tup);
		indice.eliminar(ID);
}
Tupla* buscar_tupla(int ID){
	return indice.buscar(ID);
}





