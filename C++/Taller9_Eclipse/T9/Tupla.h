/*
 * Tupla.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

// Los objetos tupla que representan una entidad se pueden tratar como clases "usuales"
#include <iostream>

//En este caso la tupla es fija
#ifndef TUPLA_H_
#define TUPLA_H_
//Representacion en memoria
class Tupla{
private:
	std::string Nombres;
	std::string Apellidos;
	std::string ID;
	std::string Carrera;
	int size;
	std::string idTupla;

public:
	Tupla(std::string Nombres, std::string Apellidos, std::string ID, std::string Carrera);

	std::string getNombres();

	std:: string getApellidos();

	std::string getID();

	std::string getCarrera();

	std::string getIDTupla();

	int getSize();

	std::string toString();
// destructor hace falta si se usa memoria dinamica: en este caso no;
	//~Tupla();
};



#endif /* TUPLA_H_ */

// en genral la representacion en Disco es un arreglo de bytes

//Representacion en disco
//Arreglo de bytes
/*
 *
 * */
