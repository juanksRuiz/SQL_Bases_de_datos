/*
 * Archivo.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

//En memoria es un objeto, si se desconecta se pierde
// En disco: se mantiene

// En memoria
//1) Representar en memoria la tabla
//2) Almacenar en disco la m

//Metadatos
//- ID Archivo / nombre tabla
//- Campos:
//		tipos, nombres, variables, fijos
#include <iostream>
#include <list>
#include "Tupla.h"
#include "Pagina.h"

#ifndef ARCHIVO_H_
#define ARCHIVO_H_
//archivo es una listaenlazada que además tiene un directorio
//No reconoce la clase Pagina
//Pensar en como incluir los metadatos

class Archivo {
public:
	Archivo(std::string id, std::list<std::string> misNombres, std::list<std::string> misTipos, std::list<bool> myIsFixedArray);

	~Archivo();

	void moverCursor_Paglibres_Adelante();

	void moverCursor_Paglibres_Atras();

	void moverCursor_PagLibres_AlFinal();

	void moverCursor_PagLibres_AlInicio();

	//void moverCursoraPaginaEncabezado();

	void moverCursor_PagOcupadas_Adelante();

	void moverCursor_PagOcupadas_Atras();

	void moverCursor_PagOcupadas_AlFinal();

	void moverCursor_PagOcupadas_AlInicio();

	Pagina& getPagina(Pagina *pg);

	void deletePagina(Pagina *pg);

	void insertarTupla(Tupla tupla);

	void eliminarTupla(std::string idTupla);

	void printArchivo();

private:
	// Estructura para almacenar cada pagina en una celda
	std::string idArchivo; // Dado por el usuario
	std::list<std::string> nombres;
	std::list<std::string>  tipos ;
	std::list<bool> isFixedArray;
	int idxPL;


	struct CeldaPagina{
			Pagina pg = Pagina();
			int idpag;
			CeldaPagina *frontLink;
			CeldaPagina *backLink;
		};

		CeldaPagina *header;
		CeldaPagina *pagOcupadasCursor;
		CeldaPagina *pagLibresCursor;

	void crearPagina();
	void moverPaginaOcupada();
};

#endif /* ARCHIVO_H_ */


