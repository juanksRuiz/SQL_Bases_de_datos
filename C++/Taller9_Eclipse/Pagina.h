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

template <typename TipoDato>
class Pagina{

private:
	//numero de espacios incluye encabezado ?
	//Creando un arreglo de apuntadores a tuplas
	//con getTuplePosition se obtendrá el indice
	TipoDato *positionArray[];
	// VARIA

	//Tiene encabezado: # de espacios usados (funcion), codigo, capacidad

	int count; // # de tuplas en el arreglo
	int espaciosUsados; // metadato
	const int capacity; // metadato
	std::string codigo; // metadato



	//arreglo de posiciones: la ultima de cada uno;

	Tupla  arreglo[1000] ; // arreglo fijo SUFICIENTEMENTE GRANDE para almacenar tuplas
	// NO EFICIENTE EN MEMORIA , 1000 elegido al comienzo arbitrariamente
	// CORREGIR PARA HACER MÁS EFICIENTE

	void expandCapacity();

public:
	Pagina<TipoDato>(std::string cod);

	void agregarTupla(Tupla tupla);

	void eliminarTupla();

	int getEspaciosUsados();

	int getEspacioDisponible();

	~Pagina<TipoDato>();

};



#endif /* PAGINA_H_ */
