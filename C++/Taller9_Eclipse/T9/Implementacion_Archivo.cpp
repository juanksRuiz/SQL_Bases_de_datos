/*
 * Implementacion_Archivo.cpp
 *
 *  Created on: May 8, 2019
 *      Author: lovelace
 */
#include <iostream>
#include <list>
#include <string>
#include "Archivo.h"
#include "Pagina.h"
#include "Tupla.h"

//Paginas ocupadas a la izquierda, paginas con espacio a la derecha
using namespace std;


Archivo::Archivo(string id, list<string> misNombres, list<string> misTipos, list<bool> myisFixedArray){
	header = pagOcupadasCursor  = pagLibresCursor= new CeldaPagina;
	crearPagina();
	header ->backLink = NULL;
	//La pagina dek geader y el id del header no se asignan a nada ?
	idArchivo = id;
	nombres = misNombres;
	tipos = misTipos;
	isFixedArray = myisFixedArray;
	idxPL = 0;


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
	pagLibresCursor = header->frontLink;
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
	pagOcupadasCursor = header->backLink;
}

void Archivo::moverCursor_PagOcupadas_AlFinal(){
	while(pagOcupadasCursor->backLink != NULL){
		pagOcupadasCursor = pagOcupadasCursor->backLink;
	}
}


//Insertar y eliminar tuplas
void Archivo::insertarTupla(Tupla tupla){
	//suponiendo que el cursor est� en la ultima pagina
	pagLibresCursor = header->frontLink;
	while(pagLibresCursor->frontLink != NULL){
		if(pagLibresCursor->pg.hasSpaceForTuple(tupla)){
			pagLibresCursor->pg.insertarTupla(tupla);
			if(pagLibresCursor->pg.getEspacioDisponible() == 0){
					moverPaginaOcupada();
				}
			return;
		}else{
			pagLibresCursor = pagLibresCursor->frontLink;
		}
	}
	if(pagLibresCursor->pg.hasSpaceForTuple(tupla)){
		pagLibresCursor->pg.insertarTupla(tupla);
}
	if(pagLibresCursor->pg.getEspacioDisponible() == 0){
		moverPaginaOcupada();
	}

}



//Se tiene acceso a cualquier tupla
void Archivo::eliminarTupla(string idTupla){
	//imprimir mensaje de error si no hay tupla alguna con ese id

	pagLibresCursor = header->frontLink;
	while(pagLibresCursor != NULL){
		if(pagLibresCursor->pg.isTupleInside(idTupla)){
			cout << "Tupla encontrada: " << pagLibresCursor->pg.isTupleInside(idTupla);
			pagLibresCursor->pg.eliminarTupla(idTupla);
			return;
		}
	}
	pagLibresCursor = pagLibresCursor->backLink;

	pagOcupadasCursor = header->backLink;
	while(pagOcupadasCursor != NULL){
			if(pagOcupadasCursor->pg.isTupleInside(idTupla)){
				pagOcupadasCursor->pg.eliminarTupla(idTupla);
				return;
			}
		}
	pagOcupadasCursor = pagOcupadasCursor->frontLink;
	cerr << "No se encontr� la tupla con el id especificado." << endl;
	return;
}

void Archivo::printArchivo(){
	for(std::list<string>::iterator it = nombres.begin(); it != nombres.end(); it++){
		cout << *it << '|';
	}
	cout << '\n' << endl;
	pagLibresCursor = header->frontLink;
	while(pagLibresCursor != NULL){
		pagLibresCursor->pg.toString();
		pagLibresCursor = pagLibresCursor->frontLink;
	}
}
/*
Pagina& Archivo::getPagina(Pagina *p){
	pagLibresCursor = header->frontLink;
	if(&(pagLibresCursor->pg) == p){
		return p;
	}else{
		pagLibresCursor = pagLibresCursor->frontLink;
	}
	cout << "ERROR" << endl;
}
*/


//--------------------------------------------------------------------------------------------------------------------
//Metodos privados

//Crear Pagina
void Archivo::crearPagina(){
	//Crea una pagina en la celda de parametro
	//moverCursor_PagLibres_AlFinal();
	CeldaPagina *cp = new CeldaPagina;
	/*
	Pagina pg = Pagina();
	cp->pag = Pagina();
	*/
	cp->frontLink = NULL;
	cp->backLink = pagLibresCursor;
	idxPL++;
	cp->idpag = idxPL;
	pagLibresCursor->frontLink = cp;
	pagLibresCursor = cp;
}

void Archivo::moverPaginaOcupada(){
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
	if(pagLibresCursor == header){
		crearPagina();
	}
}

