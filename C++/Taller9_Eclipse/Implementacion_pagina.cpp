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

const std::size_t TAMANO_PAG  = 4000; //FIJO

template <typename TipoDato>
Pagina<TipoDato>::Pagina(int cod){
	capacity = TAMANO_PAG; // es eficiente o necesario crear de una el arreglo de 4000 posiciones ?
	count = 0;
	codigo = cod;
	espaciosUsados = 0;
	positionArray = new TipoDato*[TAMANO_PAG];

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
		cerr << "Error: intenta eliminar elemento de una Pagina vacia"<<endl;
	}else{
		espaciosUsados = espaciosUsados - arreglo[count-1].getSize();
		count--;
	}

}

template <typename TipoDato>
bool Pagina<TipoDato>::hasSpaceForTuple(Tupla tupla){
	return (getEspacioDisponible() >= tupla.getSize());
}


template<typename TipoDato>
int Pagina<TipoDato>::getEspaciosUsados(){
	return espaciosUsados;
}


template <typename TipoDato>
int Pagina<TipoDato>::getEspacioDisponible(){
	return (capacity - espaciosUsados);
}

template <typename TipoDato>
bool Pagina<TipoDato>::isEmpty(){
	return count == 0;
}

//verificar
template<typename TipoDato>
Pagina<TipoDato>::~Pagina(){
	delete[] positionArray;
	delete[] arreglo;


}
