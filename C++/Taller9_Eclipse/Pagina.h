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

const std::size_t TAMANO = 4000; //KB
template <typename TipoDato>
class Pagina{

private:
	//Creando un apuntador de arreglos TipoDato (aquí tupla)
	TipoDato *pag[TAMANO]; // arreglo dinamico de objetos Tupla
	std::string idPag;
	int espaciosUsados;


public:
	Pagina<TipoDato>();

	void agregarTupla(Tupla tupla);

	void eliminarTupla();

	int getEspaciosUsados();

	~Pagina<TipoDato>();

};



#endif /* PAGINA_H_ */
