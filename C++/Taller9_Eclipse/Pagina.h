/*
 * Pagina.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include "Tupla.h"
#ifndef PAGINA_H_
#define PAGINA_H_

const std::size_t TAMANO_PAG  = 4000; //FIJO
template <typename TipoDato>
class Pagina{

private:
	//numero de espacios incluye encabezado ?
	//Creando un arreglo de apuntadores a tuplas
	//con getTuplePosition se obtendrá el indice
	TipoDato **positionArray;
	// VARIA

	//Tiene encabezado: # de espacios usados (funcion), codigo, capacidad

	int count; // # de tuplas en el arreglo
	int espaciosUsados; // metadato
	const int capacity; // metadato
	int codigo; // metadato-- cuando el archivo cree una nueva pagina el codigo es el indice



	//arreglo de posiciones: la ultima de cada uno;

	Tupla  arreglo[TAMANO_PAG] ; // arreglo fijo SUFICIENTEMENTE GRANDE para almacenar tuplas
	// NO EFICIENTE EN MEMORIA , 1000 elegido al comienzo arbitrariamente
	// CORREGIR PARA HACER MÁS EFICIENTE

	void expandCapacity();

public:
	Pagina<TipoDato>(int cod);

	void agregarTupla(Tupla tupla);

	void eliminarTupla();

	bool hasSpaceForTuple(Tupla tupla);

	int getEspaciosUsados();

	int getEspacioDisponible();

	bool isEmpty();

	~Pagina<TipoDato>();

};



#endif /* PAGINA_H_ */
