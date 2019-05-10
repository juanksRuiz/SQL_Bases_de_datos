/*
 * ListaEnlazada.cpp
 */



#include <iostream>
#include "ListaEnlazada.h"
using namespace std;


ListaEnlazada::ListaEnlazada() {
	start = cursor = new Celda;
	start->link = NULL;
}


ListaEnlazada::~ListaEnlazada() {
	Celda *cp = start;
	while (cp != NULL) {
		Celda *next = cp->link;
		delete cp;
		cp = next;
	}
}

void ListaEnlazada::moverCursorAdelante() {
	if (cursor->link != NULL) {
		cursor = cursor->link;
	}
}

void ListaEnlazada::moverCursorAtras() {
	Celda *cp = start;
	if (cursor != start) {
		while (cp->link != cursor) {
			cp = cp->link;
		}
		cursor = cp;
	}
}

void ListaEnlazada::moverCursorAlInicio() {
	cursor = start;
}

void ListaEnlazada::moverCursorAlFinal() {
	while (cursor->link != NULL) {
		cursor = cursor->link;
	}
}

void ListaEnlazada::insertarCaracter(char ch) {
	Celda *cp = new Celda;
	cp->ch = ch;
	cp->link = cursor->link;
	cursor->link = cp;
	cursor = cp;
}

void ListaEnlazada::eliminarCaracter() {
	if (cursor->link != NULL) {
		Celda *oldCelda = cursor->link;
		cursor->link = cursor->link->link;
		delete oldCelda;
	}
}


void ListaEnlazada::mostrarContenido() {
	for (Celda *cp = start->link; cp != NULL; cp = cp->link) {
		cout << ' ' << cp->ch;
	}
	cout << endl;

	for (Celda *cp = start; cp != cursor; cp = cp->link) {
		cout << "  ";
	}
	cout << '^' << endl;
}
