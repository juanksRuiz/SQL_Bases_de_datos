/*
 * Taller9.h
 *
 *  Created on: Apr 26, 2019
 *      Author: lovelace
 */

#ifndef TUPLA_H_
#define TUPLA_H_

#include <iostream>
#include <string>

class Tupla{
	private:
		int id;
		std::string nombre;
		std::string apellido;
		std::string programa;
		int tamano;
	public:
		Tupla();
		Tupla(int id, std::string nombre,std::string apellido,std::string programa);
		~Tupla();
		int getid() const;
		std::string getnombre();
		std::string getapellido();
		std::string getprograma();
		int gettamano();
		std::string toString();
		bool operator ==(const Tupla &p1);
};

#endif /* TUPLA_H_ */
