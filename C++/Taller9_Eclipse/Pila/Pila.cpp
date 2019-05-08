/*
 * PilaChar.cpp
 *
 * Implementaci�n de la clase PilaChar
 *
 */

#ifdef _pila_h

#include "Pila.h"

#include <iostream>
using namespace std;

/*
* Constante: CAPACIDAD_INICIAL
* --------------------------
* Define capacidad inicial de la pila. Si la pila se llena, se duplica su tama�o.
*
*/
const int CAPACIDAD_INICIAL = 10;

/*
* Constructor
* -------------------------------------------
* Inicializa la pila y otros atributos.
*/
template <typename DataType>
Pila<DataType>::Pila() {
	capacity = CAPACIDAD_INICIAL;
	arreglo = new DataType[capacity];
	count = 0;
}

/**
 * Copy constructor
 */
template <typename DataType>
Pila<DataType>::Pila(const Pila& pila) {
	copiaProfunda(pila);
}

/*
* Destructor
* --------------------------------
* Libera memoria en el heap: arreglo.
*/
template <typename DataType>
Pila<DataType>::~Pila() {
	delete[] arreglo; //
}

template <typename DataType>
int Pila<DataType>::size() {
	return count;
}

template <typename DataType>
bool Pila<DataType>::isEmpty() {
	return count == 0;
}

template <typename DataType>
void Pila<DataType>::clear() {
	count = 0;
}

template <typename DataType>
void Pila<DataType>::push(DataType ch) {
	if (count == capacity) expandCapacity();
	arreglo[count++] = ch;
}

template <typename DataType>
DataType Pila<DataType>::pop() {
	if (isEmpty()) cerr << "Error. pop: Intenta eliminar un elemento de una pila vacia";
	return arreglo[--count];
}

template <typename DataType>
char Pila<DataType>::peek() {
	if (isEmpty()) cerr  << "Error. peek: Intenta acceder a un elemento de una pila vacia";
	return arreglo[count - 1];
}

template <typename DataType>
void Pila<DataType>::expandCapacity() {
	DataType *oldArreglo = arreglo;
	capacity *= 2;
	arreglo = new DataType[capacity];
	for (int i = 0; i < count; i++) {
		arreglo[i] = oldArreglo[i];
	}
	delete[] oldArreglo;
}

template <typename DataType>
Pila<DataType>& Pila<DataType>::operator=(const Pila<DataType>& p2){
	if(this != &p2){
		delete[] arreglo;
		copiaProfunda(p2);
	}
	return *this;
}

template <typename DataType>
void Pila<DataType>::copiaProfunda(const Pila<DataType>& pila){
	arreglo = new DataType[pila.count];
	for(int i = 0; i < pila.count; i++){
		arreglo[i] = pila.arreglo[i];
	}
	this->count = pila.count;
	this->capacity = pila.capacity;

}


#endif
