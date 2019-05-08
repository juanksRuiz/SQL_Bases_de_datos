/*
 * ejemploListaEnlazada.cpp
 */



#include <iostream>

#include "ListaEnlazada.h"
using namespace std;

int main(){
	ListaEnlazada lista;

	lista.insertarCaracter('j');
	lista.insertarCaracter('u');
	lista.insertarCaracter('a');
	lista.insertarCaracter('n');
	lista.mostrarContenido();

	lista.moverCursorAtras();
	lista.mostrarContenido();
	lista.moverCursorAtras();
	lista.mostrarContenido();

	lista.insertarCaracter('l');
	lista.insertarCaracter('i');
	lista.mostrarContenido();

	lista.eliminarCaracter();
	lista.mostrarContenido();
	lista.eliminarCaracter();
	lista.mostrarContenido();
	lista.eliminarCaracter();
	lista.mostrarContenido();

	return 0;
}


