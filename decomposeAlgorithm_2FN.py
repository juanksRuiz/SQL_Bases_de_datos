#Determinar si dependencia está en 2FN (si es super llave o es trivial):
#guardar en una lista aparte los atributos visitados para compararlos con todos los de R
def is_in_2FN(dep,R):
    for k in dep.keys():
	for val in dep[k]:
	    for key in k:
	        if key in dep[k]:
		    print "se encontró el atributo %s en la dependencia: " %key
		    print k,dep[k]		
#diccionario: dependencias funcionales
def Decompose(R,dep):
    result = {R}


R = ['curso_cod','nombre_curso','num_creditos','grupo_id','unid_acad',
'ano','edificio','salon','capacidad','hora']

dep = {('curso_cod'):('nombre_curso','unid_acad','num_creditos'),
       ('edificio','salon'):('capacidad'),
       ('curso_cod','grupo_id','ano'):('edificio','salon','hora')
	}
