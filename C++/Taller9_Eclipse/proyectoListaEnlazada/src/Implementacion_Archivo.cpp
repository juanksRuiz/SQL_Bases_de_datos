/*
 * Implementacion_Archivo.cpp
 *
 *  Created on: May 8, 2019
 *      Author: lovelace
 */
#include <iostream>
#include "Archivo.h"
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

//Insertar y eliminar tuplas
template <typename DataType>
void Archivo<DataType>::insertarTupla(Tupla tupla){
	//verificacion del espacio disponible desde header
	moverCursor_PagLibres_AlInicio();
	if(pagLibresCursor->frontLink == NULL){
		CeldaPagina *cp = new CeldaPagina;
		cp->backLink = pagLibresCursor->frontLink;
		pagLibresCursor->frontLink = cp;
		pagLibresCursor = cp;
		//Verificar sintaxis
		cp->pag.agregarTupla(tupla);
	}

}


