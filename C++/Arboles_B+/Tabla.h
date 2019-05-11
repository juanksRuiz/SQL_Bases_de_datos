/*
 * Tabla.h
 *
 *  Created on: May 11, 2019
 *      Author: lovelace
 */


#ifndef TABLA_H_
#define TABLA_H_

#include <list>
#include "Tupla.h"
#include "ArbolBMas.h"

class Tabla{
private:
	std::list<Tupla> tabla;

	std:: string nombre;





public:
	int getSize();

	void insertarTupla(Tupla tupla);

	void eliminarTupla(); //Corregir


};



#endif /* TABLA_H_ */
