/*
 * Implementacion_pagina.cpp
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include <string>
#include <map>
#include "Tupla.h"
#include "Pagina.h"

using namespace std;

const std::size_t TAMANO_PAG  = 4000; //FIJO
int idx = 0;

template <typename TipoDato>
Pagina<TipoDato>::Pagina(string cod){
	capacity = TAMANO_PAG;
	count = 0;
	codigo = cod;
	espaciosUsados = 0;

}



//Destructor - CORREGIR
/*
template <typename TipoDato>
Pagina<TipoDato>::~Pagina(){
	delete ;// con [] elimina  el bloque de memoria
}
*/

template<typename TipoDato>
void Pagina<TipoDato>::agregarTupla(Tupla tupla){
	if(getEspacioDisponible() < tupla.getSize()){
		cerr <<"ERROR: CAPACIDAD MAXIMA DE PAGINA ALCANZADA" << endl;
		return;
	}
	//agregando Tupla a arreglo de posiciones
	arreglo[count] = tupla;

	//asumiendo que hay espacio suficiente en el arreglo de posiciones
	positionArray[count] = &tupla;
	espaciosUsados = espaciosUsados + tupla.getSize();
	count++;

}

template <typename TipoDato>
void Pagina<TipoDato>::eliminarTupla(){
	//Borra siempre la ultima Tupla: como en el stack
	if(count == 0){
		cerr << "Error: intenta eliminar elemento de una Pagina vacia";
	}else{
		espaciosUsados = espaciosUsados - arreglo[count-1].getSize();
		positionArray[count-1];
		arreglo[count-1];
		count--;
	}

}


template<typename TipoDato>
int Pagina<TipoDato>::getEspaciosUsados(){
	return espaciosUsados;
}


template <typename TipoDato>
int Pagina<TipoDato>::getEspacioDisponible(){
	return (capacity - espaciosUsados);
}

//verificar
template<typename TipoDato>
Pagina<TipoDato>::~Pagina(){
	delete[] positionArray;
	delete[] arreglo;

}
