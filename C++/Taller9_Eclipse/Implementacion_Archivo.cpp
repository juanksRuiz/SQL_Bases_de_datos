/*
 * Implementacion_Archivo.cpp
 *
 *  Created on: May 8, 2019
 *      Author: lovelace
 */
#include <iostream>
#include "Archivo.h"
#include "Pagina.h"
#include "Tupla.h"

//Paginas ocupadas a la izquierda, paginas con espacio a la derecha
using namespace std;


Archivo::Archivo(){
	header = pagOcupadasCursor  = pagLibresCursor= new CeldaPagina;
	header->frontLink = NULL;
	header ->backLink = NULL;
}

Archivo::~Archivo(){
	//Verificar
	moverCursor_PagLibres_AlFinal();
	CeldaPagina *cpl = pagLibresCursor;
	while(cpl != header->frontLink){
		CeldaPagina *bf = cpl->backLink;
		delete cpl;
		cpl = bf;
		}
	//Se queda en header->frontLink
	moverCursor_PagOcupadas_AlFinal();
	CeldaPagina *cpo = pagOcupadasCursor;
	while(cpo != header->backLink){
		CeldaPagina *a = cpo->frontLink;
		delete cpo;
		cpo = a;
		}
	delete cpl;
	delete cpo;
	delete header;
	// Se queda en header->backLink


}

//Para paginas libres
void Archivo::moverCursor_Paglibres_Adelante(){
	if(pagLibresCursor->frontLink != NULL){
		pagLibresCursor = pagLibresCursor->frontLink;
	}
}

void Archivo::moverCursor_Paglibres_Atras(){
	if (pagLibresCursor->backLink != header){
		pagLibresCursor = pagLibresCursor->backLink;
	}
}

void Archivo::moverCursor_PagLibres_AlFinal(){
	while(pagLibresCursor->frontLink != NULL){
		pagLibresCursor = pagLibresCursor->frontLink;
	}
}

void Archivo::moverCursor_PagLibres_AlInicio(){
	pagLibresCursor = header;
}

//---------------------------------
//Para paginas ocupadas
void Archivo::moverCursor_PagOcupadas_Adelante(){
	if(pagOcupadasCursor->backLink != NULL){
		pagOcupadasCursor = pagOcupadasCursor->backLink;
	}
}

void Archivo::moverCursor_PagOcupadas_Atras(){
	if(pagOcupadasCursor->frontLink != header){
		pagOcupadasCursor = pagOcupadasCursor->frontLink;
	}
}

void Archivo::moverCursor_PagOcupadas_AlInicio(){
	pagOcupadasCursor = header;
}

void Archivo::moverCursor_PagOcupadas_AlFinal(){
	while(pagOcupadasCursor->backLink != NULL){
		pagOcupadasCursor = pagOcupadasCursor->backLink;
	}
}


//Insertar y eliminar tuplas
void Archivo::insertarTupla(Tupla tupla){
	//suponiendo que el cursor est� en la ultima pagina
	if(pagLibresCursor == header){
		crearPagina();
		pagLibresCursor->pag
		return;
	}else{
		pagLibresCursor = header->frontLink;
		while(pagLibresCursor->frontLink != NULL){
			if(pagLibresCursor->pag.hasSpaceForTuple(tupla)){
				pagLibresCursor->pag.agregarTupla(tupla);
				if(pagLibresCursor->pag.getEspacioDisponible() == 0){
						moverPaginaOcupada();
					}
				return;
			}else{
				pagLibresCursor = pagLibresCursor->frontLink;
			}
		}
		crearPagina();
		pagLibresCursor->pag.agregarTupla(tupla);
	}
	if(pagLibresCursor->pag.getEspacioDisponible() == 0){
		moverPaginaOcupada();
	}

}

//Necesario ?
/*
template <typename DataType>
void Archivo<DataType>::eliminarTupla(){

}
*/


//----------------
//Metodos privados

//Crear Pagina
void Archivo::crearPagina(){
	//Crea una pagina en la celda de parametro
	//moverCursor_PagLibres_AlFinal();
	CeldaPagina *cp = new CeldaPagina;
	cp->pag = NULL;
	cp->frontLink = NULL;
	cp->backLink = pagLibresCursor;
	cp->idPag = idPag + 1;
	this->idPag++;
	pagLibresCursor->frontLink = cp;
	pagLibresCursor = cp;
}

template <typename DataType>
void Archivo<DataType>::moverPaginaOcupada(){
	CeldaPagina *oldCelda = pagLibresCursor;
	if(pagLibresCursor->frontLink != NULL){
		(pagLibresCursor->frontLink)->backLink = pagLibresCursor->backLink;
		(pagLibresCursor->backLink)->frontLink = pagLibresCursor->frontLink;



	}else{
		(pagLibresCursor->backLink)->frontLink = NULL;

	}
	pagLibresCursor = oldCelda->backLink;
	moverCursor_PagLibres_AlFinal();
	moverCursor_PagOcupadas_AlFinal();
	pagOcupadasCursor->backLink = oldCelda;
	oldCelda->frontLink = pagOcupadasCursor;
	oldCelda->backLink = NULL;
	pagOcupadasCursor = pagOcupadasCursor->backLink;
}
