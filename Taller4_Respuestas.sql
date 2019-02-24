--Taller 3 
----2)
delete from curso2
where nombre like '%4';

----3)
create table curso_all
(curso_cod varchar (7),
nombre varchar (50),
nombre_unid varchar (20),
creditos numeric (2,0),
primary key (curso_cod),
foreign key (nombre_unid) references unid_acad);

--a)
--Se puede hacer una subconsulta para insertar todo un bloque de datos
 simpre que tenga sentido con los atributos
insert into curso_all
select * from curso;

--b)
insert into curso_all
(select * from curso2) except (select * from curso);

----4)
--a) update unid_acad
set presupuesto = presupuesto + 0.03*presupuesto;

--b)
--Si se quiere modificar un atributo con el atributo de otra relacion:
-- igualar atributo que se modifica a la relaci�n (valor) que se necesite
update unid_acad
set presupuesto = 
presupuesto + (select min(presupuesto)
from unid_acad);


----5)
--stddev(atributo): desviacion estandar
--�Qu� hace la vista?, ejemplo en el que muestre como se actualiza
-----------------------------

create view vista_presupuesto as
select avg(presupuesto) as prom_presupuesto, min(presupuesto) as min_presupuesto, max(presupuesto) as max_presupuesto, stddev(presupuesto) as desv_estandar_presup
from unid_acad;

----6)
-- �Al hacer un join on atributos iguales, como accedo a los atributos que se repiten?
-- �tabs son necesarios en sintaxis?

-------------------

create view resumenGruposUnidad as
	select nombre_unid, nombre, grupo_cod, ano, semestre 
	from grupo join curso
	on grupo.curso_cod = curso.curso_cod;

--a)
insert into grupo values('003', '1', '1', 2018);
insert into grupo values('003', '2', '1', 2018);

--b) Verificando resumenGruposUnidad aparecieron las dos inserciones anteriores de BIOL

----7)
--Vista materializada: guarda en memoria (?) una vista que se crea.
create materialized view instructorUbic as (
	select nombres,apellidos,edificio
	from instructor join unid_acad
	on instructor.nombre_unid = unid_acad.nombre_unid
);

--a)
insert into instructor values('5', 'Camilo', 'Ramirez', 'ECON', 200);

--b)
-- Si se verifica el registro no aparece

--c)
--Refrescando para que se actualice la vista:
refresh materialized view instructorUbic;

--d) Si se verifica aparece el nuevo registro insertado en el literal a)