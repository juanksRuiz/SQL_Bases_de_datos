/*
 * Implementacion_tupla.cpp
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */
#include <iostream>
#include <string>
#include "Tupla.h"
using namespace std;
// buscar como ponerle varios tipos a un arreglo

Tupla::Tupla(string nombres, string apellidos, std::string miID, string miCarrera){
	Nombres = nombres;
	Apellidos = apellidos;
	ID = miID;
	Carrera = miCarrera;
	size = sizeof(Nombres) + sizeof(Apellidos)+sizeof(ID) + sizeof(Carrera); // Suma de sizeof
}

string Tupla::getNombres(){
	return Nombres;
}

string Tupla::getApellidos(){
	return Apellidos;
}

string Tupla::getID(){
	return ID;
}

string Tupla::getCarrera(){
	return Carrera;
}

int Tupla::getSize(){
	//retorna cantidad de elementos de la tupla
	return size;
}





// Si se tuviera un arreglo de direcciones se borra cada elemento del arreglo
// y luego si se borra el arreglo en memoria



