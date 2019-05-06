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
	return count*4;
}


template <typename TipoDato>
int Pagina<TipoDato>::getEspacioDisponible(){
	return (capacity - 4*count);
}

//verificar en java
// insertar en el sql al zyklorecolector
