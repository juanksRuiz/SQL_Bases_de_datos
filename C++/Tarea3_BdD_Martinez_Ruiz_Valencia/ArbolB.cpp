//#include "ArbolB.h"
#ifdef ARBOLB_H_

template<typename TipoDato>
ArbolB<TipoDato>::ArbolB(int n){
	this->n = n;
	raiz = nullptr;
	raiz->numllaves = 0;
	raiz->numtuplas = 0;
	raiz->numhijos = 0;

}

template<typename TipoDato>
ArbolB<TipoDato>::~ArbolB(){//??????????????
	delete [] raiz;
	raiz = nullptr;
	//delete [] *llaves;
	//delete [] *tuplas;
	//delete [] *hijos;

}


/* Returns leaf node C and index i such that C.Pi points to first record
* with search key value V */
template<typename TipoDato>
Tupla* ArbolB<TipoDato>::buscar(TipoDato llave){ // retornar C,i
	NodoB *C;
	C = raiz; // apuntador
	while(C->esHoja == false){
		for (int i = 0; i < n-1; i++){
			if (llave == C->llaves[i]){
				C = C->hijos[i+1];// no importa el i+1 pues hijos hay n ??? va e asterisco??
				break;
			}else if(llave < C->llaves[i]) {
				C = C->hijos[i];
				break;
			}
			if (llave > C->llaves[i]){//????????????????????? si llave es mayor y que mas??? que hay en el arreglo??
				for (int j = i+1; j < C->numllaves; j++){
					if(llave < C->llaves[j]){
						C = C->hijos[j];
						break;
					}
				}
				C = C->hijos[i+1];
			}
		}
	}
	/* C is a leaf node */
	for (int i = 0; i < n-1; i++){
		if (llave == C->llaves[i]){
			return C->tuplas[i];
		}
	}
	return nullptr;
}

template<typename TipoDato>
ArbolB<TipoDato>::NodoB* ArbolB<TipoDato>::buscar_en_hoja(TipoDato llave){ // retornar C,i
	NodoB *C;
	C = raiz; // apuntador
	while(C->esHoja == false){
		for (int i = 0; i < n-1; i++){
			if (llave == C->llaves[i]){
				C = C->hijos[i+1];// no importa el i+1 pues hijos hay n ??? va e asterisco??
				break;
			}else if(llave < C->llaves[i]) {
				C = C->hijos[i];
				break;
			}
			if (llave > C->llaves[i]){//????????????????????? si llave es mayor y que mas??? que hay en el arreglo??
				for (int j = i+1; j < C->numllaves; j++){
					if(llave < C->llaves[j]){
						C = C->hijos[j];
						break;
					}
				}
				C = C->hijos[i+1];
				break;
			}
		}
	}
	/* C is a leaf node */
	return C;
}

template<typename TipoDato>
void ArbolB<TipoDato>::insertar(TipoDato K,Tupla* P){
	NodoB *L;
	if(raiz==nullptr){//(tree is empty) create an empty leaf node L, which is also the root
		raiz = new NodoB; /// raiz es un apuntador a o es un nodo???? new BodoB es una direccion??
		raiz->esHoja = true;
		raiz->llaves = new TipoDato[n-1];
		raiz->tuplas = new Tupla*[n-1]; // con next da n apuntadores a tuplas
		raiz->next = nullptr;
		raiz->numllaves = 0;
		raiz->numtuplas = 0;
		raiz->numhijos = 0;
		//NodoB *L;
		L= raiz;
	}else{//Find the leaf node L that should contain key value K
		//NodoB* L;
		L=buscar_en_hoja(K);
	}
	if(L->llaves < n-1){//(L has less than n − 1 key values)
		insertar_en_hoja(L,K,P);//insert in leaf (L, K, P) (node L, value K, pointer P)
	}else{/* L has n − 1 key values already, split it */
		//Create node L'

		NodoB* Lp;
		Lp = new NodoB; /// ?
		Lp->esHoja = true; ////???? es hoja????
		Lp->llaves = new TipoDato[n-1];
		Lp->tuplas = new Tupla*[n-1]; // con next da n apuntadores a tuplas
		Lp->next = nullptr;
		Lp->numllaves = 0;
		Lp->numtuplas = 0;
		Lp->numhijos = 0;

		TipoDato keytemp [n];
		Tupla* aptuplas [n];
		for(int i = 0; i<n-1;i++){
			keytemp[i]=(L->llaves[i]);
			aptuplas[i]=(L->tuplas[i]);
		}
		if(K < keytemp[0]){
			for(int i = L->numllaves; i > 0; i--){
				(keytemp[i])=(L->llaves[i-1]);
				(aptuplas[i])=(L->tuplas[i-1]);
			}
			keytemp[0]=K;
			aptuplas[0]=P;
		}else{
			TipoDato tempi=0;
			for (int i = 0; i < L->numllaves; i++){
				if(L->llaves[i] > K){
					tempi = i;
					break;
				}
			}
			for(int i = L->numllaves; i > tempi; i--){
				(keytemp[i])=(keytemp[i-1]);
				(aptuplas[i])=(aptuplas[i-1]);
			}
			keytemp[tempi]=K;
			aptuplas[tempi]=P;
		}

		Lp->next = L->next;
		L->next= Lp;

		L->numllaves = 0;
		L->numtuplas = 0;

		for(int i = 0; i < n/2; i++){
			(L->llaves[i])=(keytemp[i]);
			(L->tuplas[i])=(aptuplas[i]);
			L->numllaves+=1;
			L->numtuplas+=1;
		}
		for(int i = n/2+1; i < n; i++){
			(Lp->llaves[i-(n/2+1)])=(keytemp[i]);
			(Lp->tuplas[i-(n/2+1)])=(aptuplas[i]);
			Lp->numllaves+=1;
			Lp->numtuplas+=1;
		}

		TipoDato Kp = Lp->llaves[0];

		insertar_en_padre(L,Kp,Lp);
	}
}
template <typename TipoDato>
void ArbolB<TipoDato>::insertar_en_hoja(NodoB* L,TipoDato K, Tupla* P){//(node L, value K, pointer P)
	if(K < L->llaves[0]){
		//insert P, K into L just before L.P1
		for(int i = L->llaves; i > 0; i--){
			(L->llaves[i])=(L->llaves[i-1]);
			(L->tuplas[i])=(L->tuplas[i-1]);
		}
		L->llaves[0]=K;
		L->tuplas[0]=P;
		L->numllaves+=1;
		L->numtuplas+=1;
	}else{
		/*Let Ki be the highest value in L that is less than K
		Insert P, K into L just after T.Ki*/
		int tempi=0;
		for (int i = 0; i < L->numllaves; i++){
			if(L->llaves[i] > K){
				tempi = i;
				break;
			}
		}
		for(int i = L->numllaves; i > tempi; i--){
			(L->llaves[i])=(L->llaves[i-1]);
			(L->tuplas[i])=(L->tuplas[i-1]);
		}
		L->llaves[tempi]=K;
		L->tuplas[tempi]=P;
		L->numllaves+=1;
		L->numtuplas+=1;
	}
}

template <typename TipoDato>
void ArbolB<TipoDato>::insertar_en_padre(NodoB* N,TipoDato Kp, NodoB* Np){ //(node N, value K', node N')
	if(N == raiz){//N is the root of the tree)
		/*Create a new node R containing N, K', N' /* N and N' are pointers */
		NodoB* R;
		R = new NodoB; /// ?
		R->esHoja = false;
		R->llaves = new TipoDato[n-1];
		R->hijos = new NodoB*[n]; //?????
		R->llaves[0]=Kp;
		R->hijos[0]=N;
		R->hijos[1]=Np;

		R->numllaves = 1;
		R->numtuplas = 0;
		R->numhijos = 2;
		raiz = R; /*Make R the root of the tree return*/
		return;
	}
	//Let P = parent (N)????????????????????????????
	NodoB* P;
	P = buscar_padre(N);
	if(P->numhijos < n){
		//insert (K', N') in P just after N
		if(Kp < P->llaves[0]){
			for(int i = N->numllaves; i > 0; i--){
				(P->llaves[i])=(P->llaves[i-1]);
				(P->hijos[i])=(P->hijos[i-1]);
			}
			P->llaves[0]=Kp;
			P->hijos[0]=Np;
			P->numllaves+=1;
			P->numhijos+=1;
		}else{
			int tempi=0;
			for (int i = 0; i < P->numhijos; i++){
				if(P->hijos[i] == N){
					tempi = i;
					break;
				}
			}
			for(int i = P->numhijos; i > tempi; i--){
				(P->llaves[i])=(P->llaves[i-1]);
				(P->hijos[i])=(P->hijos[i-1]);
			}
			P->llaves[tempi]=Kp;
			P->hijos[tempi]=Np;
			P->numllaves+=1;
			P->numhijos+=1;
		}

		P->numllaves = 0;
		P->numhijos = 0;
	}else{/* Split P */
		/*Copy P to a block of memory T that can hold P and (K', N')
		Insert (K', N') into T just after N
		Erase all entries from P; Create node P'
		Copy T.P1 ... T.P|n/2| into P
		Let K'' = T.K|n/2|
		Copy T.P|n/2|+1 ... T.Pn+1 into P'
		insert_in_parent(P, K'', P')*/
		TipoDato keytemp [n+1];
		Tupla* aphijos [n+1];
		int j = 0;
		for(j = 0; j<n-1;j++){
			keytemp[j]=(P->llaves[j]);
			aphijos[j]=(P->hijos[j]);
		}
		j++;
		aphijos[j]=(P->hijos[j]);

		if(Kp < keytemp[0]){
			for(int i = N->numllaves; i > 0; i--){
				(keytemp[i])=(P->llaves[i-1]);
				(aphijos[i])=(P->hijos[i-1]);
			}
			keytemp[0]=Kp;
			aphijos[0]=Np;
		}else{
			int tempi=0;
			for (int i = 0; i < P->numhijos; i++){
				if(P->hijos[i] == N){
					tempi = i;
					break;
				}
			}
			for(int i = P->numhijos; i > tempi; i--){
				(keytemp[i])=(keytemp[i-1]);
				(aphijos[i])=(aphijos[i-1]);
			}
			keytemp[tempi]=Kp;
			aphijos[tempi]=Np;
		}

		P->numllaves = 0;
		P->numhijos = 0;

		NodoB* Pp;
		Pp = new NodoB; /// ?
		Pp->esHoja = false;
		Pp->llaves = new TipoDato[n-1];
		Pp->hijos = new NodoB*[n]; //?????

		for(int i = 0; i < n/2; i++){
			(P->llaves[i])=(keytemp[i]);
			(P->hijos[i])=(aphijos[i]);
			P->numllaves+=1;
			P->numhijos+=1;
		}
		TipoDato Kpp = keytemp[n/2];

		for(int i = n/2+1; i < n+1; i++){ //i<n+1?????
			(Pp->llaves[i-(n/2+1)])=(keytemp[i]);
			(Pp->hijos[i-(n/2+1)])=(aphijos[i]);
			Pp->numllaves+=1;
			Pp->numhijos+=1;
		}

		insertar_en_padre(P,Kpp,Pp);
	}

}


template<typename TipoDato>
ArbolB<TipoDato>::NodoB* ArbolB<TipoDato>::buscar_padre(NodoB* N, NodoB* P){
	bool bandera = true;
	for(int i = 0; i < P->numhijos; i++){
		for(int j = 0; j < P->numllaves; j++){
			if(N->llaves[i] != P->hijos[j]->llaves[i]) bandera = false;
		}
		if(bandera) return P;

	}
	for(int h = 0; h < P->numllaves; h++){
		if(N->llaves[N->numllaves] < P->llaves[h]) return buscar_padre(N,P->hijos[h]);
	}
	return buscar_padre(N, P->hijos[P->numllaves]);
}

template<typename TipoDato>
ArbolB<TipoDato>::NodoB* ArbolB<TipoDato>::buscar_padre(NodoB* N){
	return buscar_padre(N,raiz);
}


template<typename TipoDato>
void ArbolB<TipoDato>::eliminar(TipoDato llave, Tupla*p){
	NodoB* hoja = buscarNodoHoja(llave);
	eliminarRegistro(hoja,llave,p);
}
// Metodo privado (interno)
template <typename TipoDato>
void ArbolB<TipoDato>::eliminarRegistro(NodoB* L, TipoDato llave, Tupla*p){
	// eliminando llave de nodo hoja + creacion de nueva hoja
	TipoDato llavesActuales[] = L->llaves;
	L->llaves = new TipoDato[L->numllaves];
	int idx;
	for(int i = 0; i < L->numllaves; i++){
		if(L->llaves[i] == llave){
			idx = i;
			TipoDato deletedKey = L->llaves[idx];
			break;
		}
		if(idx == 0){
			for(int i = 1; i < L->numllaves; i++){
				L->llaves[i-1] = llavesActuales[i];
			}
			L->numllaves--;;
		}else if(idx == (L->numllaves)-1){
			for(int i = 0; i < L->numllaves-1; i++){
				L->llaves[i] = llavesActuales[i];
			}
		}else{
			for(int i = 0; i < idx; i++){
				L->llaves[i] = llavesActuales[i];
			}
			for(int j = idx + 1; j < L->numllaves; j++){
				L->llaves[j-1] = llavesActuales[j];
			}
		}
		L->numllaves--;
		//===========================================================================
		// con deletedKey Buscar el apuntador asociado para eliminarlo
	}
}



#endif
