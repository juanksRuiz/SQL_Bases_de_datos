/*
 * CharStack.h
 *
 * CharStack class
 */

#ifndef _pila_h
#define _pila_h

template <typename DataType>
class Pila {
public:
	/*
	* Constructor: CharStack
	*/
	Pila();

	/*
	 * Copy constructor: PilaChar
	 * Inicializa un objeto PilaChar como una copia profunda del argumento pila
	 */
	Pila(const Pila<DataType> &pila );

	/*
	* Destructor: ~CharStack
	*/

	~Pila();
	/*
	* Returns the number of characters in this stack.
	*/
	int size();
	/*
	* Returns true if this stack contains no characters.
	*/
	bool isEmpty();
	/*
	* Removes all characters from this stack.
	*/
	void clear();
	/*
	* Pushes the character ch onto this stack.
	*/
	void push(DataType ch);
	/*
	* Removes the top character from this stack and returns it.
	*/
	DataType pop();
	/*
	* Returns the value of top character from this stack without
	* removing it. Raises an error if called on an empty stack.
	*/
	char peek();

	/*
	 * Operator: =
	 * Uso: p1 = p2;
	 * Asigna el objeto p2 al objeto p1 tal que las dos copias son independientes.
	 * Esta asignación requiere una copia profunda del arreglo dinámico
	 */
	Pila<DataType>& operator=(const Pila<DataType>& p2);


	private:
		/* Variables de instancia*/
		DataType *arreglo; 	/* Arreglo dinámico de caracteres */
		int capacity; 	/* Allocated size of that array */
		int count;		/* Current count of chars pushed */

		/* Funciones privadas */
		void expandCapacity();

		/*
		 * Copia profunda del argumento pila
		 */
		void copiaProfunda(const Pila<DataType> & pila);
};

#include "Pila.cpp"

#endif
