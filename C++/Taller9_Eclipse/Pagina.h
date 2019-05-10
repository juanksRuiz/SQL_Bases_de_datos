/*
 * Pagina.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include <list>
#include "Tupla.h"


#ifndef PAGINA_H_
#define PAGINA_H_

const std::size_t TAMANO_PAG  = 4096;//fijo
//Cada pagina deberia construirla con un arhivo.dat

// O lista con tuplas o lista de apuntadores con tuplas: lista enlazada
//-- > MAs compacto si arreglo de tuplas
class Pagina{

private:
	// Header
	int count; // # de tuplas en el arreglo
	int espaciosUsados; // metadato - en bytes
	int posLast; // indice,bytes
	//int codigo; // metadato-- cuando el archivo cree una nueva pagina el codigo es el indice

	std::list<Tupla> tupleList;

public:
	Pagina();

	void agregarTupla(Tupla tupla);

	void deleteTupleAt(int idx);

	bool hasSpaceForTuple(Tupla tupla);

	int getEspaciosUsados();

	int getEspacioDisponible();

	bool isEmpty();

	~Pagina();

};


#endif /* PAGINA_H_ */



// PARA CREAR EN DISCO:
	/*
	 * CREAR ARCHIVOS QUE REPRESENTA PAGINA: "nombreTablaIDPag.dat"
	 * archivo de tipo binario
	 * FOTOS
	 *
	 * */

