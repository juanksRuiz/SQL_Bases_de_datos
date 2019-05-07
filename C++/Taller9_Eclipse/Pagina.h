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

const std::size_t TAMANO_ARREGLO = 1000;
template <typename TipoDato>
class Pagina{

private:
	//Creando un arreglo de apuntadores
	TipoDato *pag[TAMANO_ARREGLO]; // arreglo dinamico de objetos Tupla
	//int idPag;

	// # de elementos en el arreglo
	int count;
	const int capacity;


public:
	Pagina<TipoDato>();

	void agregarTupla(Tupla tupla);

	void eliminarTupla();

	int getEspaciosUsados();

	int getEspacioDisponible();

	~Pagina<TipoDato>();

};



#endif /* PAGINA_H_ */
