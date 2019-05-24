// remove from list
#include <iostream>
#include <list>
#include <Tabla.h>

int main ()
{
  Tabla tabla_estudiante;
  Tupla tup1 = Tupla(111,"Miguel","Valencia","MACC");
  Tupla tup2 = Tupla(112,"Camilo","Martínez","MACC");
  Tupla tup3 = Tupla(113,"Daniel","Rambaut","MACC");
  Tupla tup4 = Tupla(114,"Juan Camilo","Ruiz","MACC");
  Tupla tup5 = Tupla(115,"Juan Fernando","Pérez","MACC");
  tabla_estudiante.insertar_tupla(tup1);
  tabla_estudiante.insertar_tupla(tup2);
  tabla_estudiante.insertar_tupla(tup3);
  tabla_estudiante.eliminar_tupla(112);
  tabla_estudiante.insertar_tupla(tup4);
  tabla_estudiante.insertar_tupla(tup5);
  Tupla *tupla = tabla_estudiante.buscar_tupla(111);
  std::cout<< (*tupla).toString()<<std::endl;


  return 0;
}
