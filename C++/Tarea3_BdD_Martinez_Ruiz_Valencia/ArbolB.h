#ifndef ARBOLB_H_
#define ARBOLB_H_

#include <string>
#include <list>
#include "Tupla.h"

template <typename TipoDato>

class ArbolB{
private:

	int n; //orden del arbol, numero max de punteros en un nodo
	struct NodoB {
		bool esHoja;
		TipoDato *llaves;//arreglo de llaves dinamico
		int numllaves;
		Tupla** tuplas;// para nodo hoja, arreglo de apuntadores a tuplas dinamico
		int numtuplas;
		NodoB* next;// para nodo hoja, apuntador a nodo hoja siguinte

		NodoB** hijos; //para nodo intermedio y raiz, arreglo de apuntadores a nodos hijos dinamico
		int numhijos;
	};
	NodoB* raiz; //apuntador a la raiz;

public:
	ArbolB(int n);
	~ArbolB();				//Tupla &t
	void insertar(TipoDato K,Tupla* P ); // K: llave   P: apuntador atupla asociada
	void insertar_en_hoja(NodoB* L,TipoDato K, Tupla* P); // L: nodo hoja  K: llave   P: apuntador atupla asociada
	void insertar_en_padre(NodoB* N,TipoDato Kp, NodoB* Np);
	void eliminar(TipoDato llave, Tupla *p);

	Tupla* buscar(TipoDato llave);
	NodoB* buscarNodoHoja(TipoDato llave);
	NodoB* buscar_en_hoja(TipoDato llave);
	NodoB* buscar_padre(NodoB*, NodoB* P);
	NodoB* buscar_padre(NodoB* N);

private:
	void eliminarRegistro(NodoB* L,TipoDato K,Tupla* p); // L: nodo hoja  K: llave   P: apuntador atupla asociada

};

#include "ArbolB.cpp"
#endif /* ARBOLB_H_ */
