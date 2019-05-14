/*
 * Implementacion_pagina.cpp
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include <string>
#include "Tupla.h"
#include "Pagina.h"

using namespace std;


//Corregir espacios disponibles de pagina
Pagina::Pagina(){
	count = 0;
	espaciosUsados = 0;
	posLast = TAMANO_PAG;
	tupleList = {};
}





//Destructor - CORREGIR
/*
template <typename TipoDato>
Pagina<TipoDato>::~Pagina(){
	delete ;// con [] elimina  el bloque de memoria
}
*/

void Pagina::insertarTupla(Tupla tupla){
	if(getEspacioDisponible() < tupla.getSize()){
		cerr <<"ERROR: CAPACIDAD MAXIMA DE PAGINA ALCANZADA" << endl;
		return;
	}
	count++;
	espaciosUsados = espaciosUsados + tupla.getSize();
	posLast = posLast - tupla.getSize();
	tupleList.push_back(tupla);

}


void Pagina::eliminarTupla(string idTuple){
	//Borra siempre la ultima Tupla: como en el stack
	if(count == 0){
		cerr << "Error: intenta eliminar elemento de una Pagina vacia"<<endl;
	}else{
		for(std::list<Tupla>::iterator it = tupleList.begin(); it != tupleList.end(); it++){
			Tupla t = *it;
			if(t.ID == idTuple){
				espaciosUsados = espaciosUsados - t.getSize();
				posLast = posLast + t.getSize();
				return;
			}
		}
		count--;
	}

}

bool Pagina::hasSpaceForTuple(Tupla tupla){
	return (getEspacioDisponible() >= tupla.getSize());
}


bool Pagina::isTupleInside(string idTupla){
	for(std::list<Tupla>::iterator it = tupleList.begin(); it != tupleList.end(); it++){
		Tupla t = *it;
		if(t.ID == idTupla){
			return true;
		}

	}
	return false;
}
int Pagina::getEspaciosUsados(){
	return espaciosUsados;
}


int Pagina::getEspacioDisponible(){
	return (TAMANO_PAG - espaciosUsados);
}


bool Pagina::isEmpty(){
	//cuenta el numero de tuplas
	return count == 0;
}


