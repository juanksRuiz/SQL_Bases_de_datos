/*
 * Tupla.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: lovelace
 */
#include "Tupla.h"

Tupla::Tupla(){
	id = 0;
	nombre = "";
	apellido = "";
	programa = "";
	tamano = 0;
}

Tupla::Tupla(int id, std::string nombre,std::string apellido,std::string programa){
	this->id = id;
	this->nombre = nombre;
	this->apellido = apellido;
	this->programa = programa;
	tamano = sizeof(id)+sizeof(nombre)+sizeof(apellido)+sizeof(programa);
}

Tupla::~Tupla(){
}


int Tupla::getid() const{
	return id;
}
std::string Tupla::getnombre(){
	return nombre;
}
std::string Tupla::getapellido(){
	return apellido;
}
std::string Tupla::getprograma(){
	return programa;
}
int Tupla::gettamano(){
	return tamano;
}

bool Tupla::operator ==(const Tupla &p)
{
    	return (this->id == p.getid());
}

std::string Tupla::toString(){
	return "id=" +std::to_string(id) +" nombre =" +nombre +" apellido=" +apellido +" programa=" + programa;
}

