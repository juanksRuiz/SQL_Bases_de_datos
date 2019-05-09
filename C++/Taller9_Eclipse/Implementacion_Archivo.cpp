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
template <typename DataType>
Archivo<DataType>::Archivo(){
	header = pagOcupadasCursor  = pagLibresCursor= new CeldaPagina;
	header->frontLink = NULL;
	header ->backLink = NULL;
}

//Para paginas libres
template <typename DataType>
void Archivo<DataType>::moverCursor_Paglibres_Adelante(){
	if(pagLibresCursor->frontLink != NULL){
		pagLibresCursor = pagLibresCursor->frontLink;
	}
}

template <typename DataType>
void Archivo<DataType>::moverCursor_Paglibres_Atras(){
	if (pagLibresCursor->backLink != header){
		pagLibresCursor = pagLibresCursor->backLink;
	}
}

template <typename DataType>
void Archivo<DataType>::moverCursor_PagLibres_AlFinal(){
	while(pagLibresCursor->frontLink != NULL){
		pagLibresCursor = pagLibresCursor->frontLink;
	}
}

template <typename DataType>
void Archivo<DataType>::moverCursor_PagLibres_AlInicio(){
	pagLibresCursor = header;
}

//---------------------------------
//Para paginas ocupadas
template<typename DataType>
void Archivo<DataType>::moverCursor_PagOcupadas_Adelante(){
	if(pagOcupadasCursor->backLink != NULL){
		pagOcupadasCursor = pagOcupadasCursor->backLink;
	}
}

template <typename DataType>
void Archivo<DataType>::moverCursor_PagOcupadas_Atras(){
	if(pagOcupadasCursor->frontLink != header){
		pagOcupadasCursor = pagOcupadasCursor->frontLink;
	}
}

template <typename DataType>
void Archivo<DataType>::moverCursor_PagOcupadas_AlInicio(){
	pagOcupadasCursor = header;
}

template <typename DataType>
void Archivo<DataType>::moverCursor_PagOcupadas_AlFinal(){
	while(pagOcupadasCursor->backLink != NULL){
		pagOcupadasCursor = pagOcupadasCursor->backLink;
	}
}

//Crear Pagina
template <typename DataType>
void Archivo<DataType>::crearPagina(){
	//Crea una pagina en la celda de parametro
	//moverCursor_PagLibres_AlFinal();
	CeldaPagina *cp = new CeldaPagina;
	DataType pg;
	cp->pag = pg;
	cp->frontLink = NULL;
	cp->backLink = pagLibresCursor;
	pagLibresCursor->frontLink = cp;
	pagLibresCursor = cp;
}

//Insertar y eliminar tuplas
template <typename DataType>
void Archivo<DataType>::insertarTupla(Tupla tupla){
	//suponiendo que el cursor está en la ultima pagina
	if(pagLibresCursor == header){
		crearPagina();
		pagLibresCursor->pag.agregarTupla(tupla);
		return;
	}else{
		pagLibresCursor = header->frontLink;
		while(pagLibresCursor->frontLink != NULL){
			if(pagLibresCursor->pag.hasSpaceForTuple(tupla)){
				pagLibresCursor->pag.agregarTupla(tupla);
				return;
			}else{
				pagLibresCursor = pagLibresCursor->frontLink;
			}
		}
		crearPagina();
		pagLibresCursor->pag.agregarTupla(tupla);
	}

}


