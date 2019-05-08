/*
 * Tupla.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

// Los objetos tupla que representan una entidad se pueden tratar como clases "usuales"
#include <iostream>


#ifndef TUPLA_H_
#define TUPLA_H_
class Tupla{
private:
	std::string Nombres;
	std::string Apellidos;
	std::string ID;
	std::string Carrera;
	int size;

public:
	Tupla(std::string Nombres, std::string Apellidos, std::string ID, std::string Carrera);

	std::string getNombres();

	std:: string getApellidos();

	std::string getID();

	std::string getCarrera();

	int getSize();

	std::string toString();
// destructor hace falta si se usa memoria dinamica: en este caso no;
	//~Tupla();
};



#endif /* TUPLA_H_ */
