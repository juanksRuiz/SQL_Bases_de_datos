/*
 * ArchivoDir.h
 *
 *  Created on: May 15, 2019
 *      Author: lovelace
 */

#include <iostream>
#include <list>
#include "Tupla.h"
#include "Pagina.h"

#ifndef ARCHIVODIR_H_
#define ARCHIVODIR_H_


class ArchivoDir {
public:
	ArchivoDir(std::string id, std::list<std::string> misNombres,
			std::list<std::string> misTipos, std::list<bool> myisFixedArray);

	~ArchivoDir();

	std::string getIdArchivo();

	std::list<std::string> getNombres();

	std::list<std::string> getTipos();

	std::list<bool> getIsFixedArray();

	Pagina getPagina(Pagina *pg);

	void deletePagina(Pagina *pg);






private:
	std::string idArchivo; // Dado por el usuario
	std::list<std::string> nombres;
	std::list<std::string>  tipos ;
	std::list<bool> isFixedArray;
	Pagina **arregloPaginas;
};




#endif /* ARCHIVODIR_H_ */
