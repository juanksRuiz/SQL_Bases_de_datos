/*
 * ListaEnlazada.h
 *
 */

#ifndef LISTAENLAZADA_H_
#define LISTAENLAZADA_H_

class ListaEnlazada {
public:

ListaEnlazada();

~ListaEnlazada();

void moverCursorAdelante();

void moverCursorAtras();

void moverCursorAlInicio();

void moverCursorAlFinal();

void insertarCaracter(char ch);

void eliminarCaracter();

void mostrarContenido();

private:
	/*
	* Tipo: Celda
	* ----------
	* Estructura para almacenar cada celda de la lista.
	*/

	struct Celda {
		char ch;
		Celda *link;
	};


	/* Atributos */
	Celda *start; 	/* Apuntador a la primera posicion */
	Celda *cursor;  /* Apuntador a la celda justo antes del cursor  */
};

#endif /* LISTAENLAZADA_H_ */
