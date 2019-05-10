/*
 * Archivo.h
 *
 *  Created on: May 3, 2019
 *      Author: lovelace
 */

#include <iostream>
#include "Tupla.h"
#include "Pagina.h"
#ifndef ARCHIVO_H_
#define ARCHIVO_H_
//archivo es una listaenlazada que además tiene un directorio
//No reconoce la clase Pagina
//Pensar en como incluir los metadatos
template <typename DataType>
class Archivo {
public:
	Archivo();

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

	void insertarTupla(Tupla tupla);

	void eliminarTupla();

private:
	// Estructura para almacenar cada pagina en una celda
	struct CeldaPagina{
		DataType pag; // No reconoce la clase pagina
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


