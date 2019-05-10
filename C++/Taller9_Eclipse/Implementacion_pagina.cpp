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

void Pagina::agregarTupla(Tupla tupla){
	if(getEspacioDisponible() < tupla.getSize()){
		cerr <<"ERROR: CAPACIDAD MAXIMA DE PAGINA ALCANZADA" << endl;
		return;
	}
	count++;
	espaciosUsados = espaciosUsados + tupla.getSize();
	posLast = posLast - tupla.getSize();
	tupleList.push_back(tupla);

}


void Pagina::deleteTupleAt(int idx){
	//Borra siempre la ultima Tupla: como en el stack
	if(count == 0){
		cerr << "Error: intenta eliminar elemento de una Pagina vacia"<<endl;
	}else{
		espaciosUsados = espaciosUsados - tupleList.back().getSize();
		posLast = posLast + tupleList.back().getSize();
		list<Tupla>::iterator it;
		it = tupleList.begin();
		for(int i = 0; i < idx; i++){
			advance(it,idx);
		}
		tupleList.erase(it);
		count--;
	}

}

bool Pagina::hasSpaceForTuple(Tupla tupla){
	return (getEspacioDisponible() >= tupla.getSize());
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


