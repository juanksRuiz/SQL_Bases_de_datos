/*
 * Tabla.h
 *
 *  Created on: May 11, 2019
 *      Author: lovelace
 */

#ifndef TABLA_H_
#define TABLA_H_

#include <string>
#include <list>
#include "Tupla.h"
#include "ArbolB.h"

class Tabla{
	private:
		std::list<Tupla> tuplas;
		ArbolB indice;

		std::string identificador; //nombre

		int ID;
		std::string Nombre;
		std::string Apellido;
		std::string Programa;

	public:
		Tabla(std::string nombre);
		~Tabla();
		void insertar_tupla(Tupla tup);
		void eliminar_tupla(int ID);
		Tupla* buscar_tupla(int ID);
};

#endif /* TABLA_H_ */
