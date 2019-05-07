/*
 * Implementacion_pagina.cpp
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include <string>
#include <list>
#include "Tupla.h"
#include "Pagina.h"

using namespace std;
template <typename TipoDato>
Pagina<TipoDato>::Pagina(){
	count = 0;
	capacity = 4000;
}
//crear arreglo de apunadores
template <typename TipoDato>
void Pagina<TipoDato>::agregarTupla(Tupla tupla){
	tupla[count] = &tupla;
	count++;
}

template <typename TipoDato>
void Pagina<TipoDato>:: eliminarTupla(){
	pag[count-4];


}

template <typename TipoDato>
int Pagina<TipoDato>::getEspaciosUsados(){
	if(count == 0){
		return 0;
	}else{
		int ocupados = 0;
				for(int i = 0; i < count; i++){
					//Esta sintaxis funciona ?
					ocupados = ocupados + *pag[i].getSize();
				}
				return ocupados;
	}
}


template <typename TipoDato>
int Pagina<TipoDato>::getEspacioDisponible(){
	//tomar todos las las longitudes de las tuplas presentes
	if(count == 0){
		return capacity;
	}else{
		// la sintaxis está bien ?
		return (capacity - this->getEspaciosUsados());

	}

}

template <typename TipoDato>
Pagina<TipoDato>::~Pagina(){
	// Ver como se borran los elementos en un vector
	if(count == 0){
		delete pag;
		//Hay que hacer delete con cada elemento del arreglo ?
	}else{
		while(count <= 0){
			Tupla * t = pag[count -1];
			delete t;
		}
		// se borra tambien el arreglo ?
	}
}

