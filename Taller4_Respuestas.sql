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
--Se puede hacer una subconsulta para insertar todo un bloque de datos simpre que tenga sentido con los atributos
insert into curso_all
select * from curso;

--b)
insert into curso_all
(select * from curso2) except (select * from curso);

----4)
--a) 
update unid_acad
set presupuesto = presupuesto + 0.03*presupuesto;

--b)
--Si se quiere modificar un atributo con el atributo de otra relacion:
-- igualar atributo que se modifica a la relación (valor) que se necesite
update unid_acad
set presupuesto = 
presupuesto + (select min(presupuesto)
from unid_acad);


----5)
--stddev(atributo): desviacion estandar
--¿Qué hace la vista?, ejemplo en el que muestre como se actualiza
-----------------------------

create view vista_presupuesto as
select avg(presupuesto) as prom_presupuesto, min(presupuesto) as min_presupuesto, max(presupuesto) as max_presupuesto, stddev(presupuesto) as desv_estandar_presup
from unid_acad;

----6)
-- ¿Al hacer un join on atributos iguales, como accedo a los atributos que se repiten?
-- ¿tabs son necesarios en sintaxis?

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

----8) TRANSACCIONES --EN QUÉ ORDEN FUNCIONA COMMIT Y ROLLBACK DESDE CONSOLA/ EN PGADMIN4 ?
--Si se ejecuta las instrucciones sin commit o nada hay una modificación.
-- ANTES DE REALIZAR LA CONFIRMACIÓN:COMMIT: confirma la modificacion/ ROLLBACK: revierte la modificacion
--a)
begin;
update unid_acad
	set presupuesto = presupuesto + (select min(presupuesto) from unid_acad)
	where presupuesto = (select min(presupuesto) from unid_acad);
--rollback;
commit;

--b)
begin;
update unid_acad
	set presupuesto = presupuesto + (select min(presupuesto) from unid_acad)
	where presupuesto = (select max(presupuesto) from unid_acad);
commit;

----9)
--a)
--modificando curso para que el nombre sea unico
alter table curso
add constraint nombresUnicos unique (nombre);
---------------- nombre restriccion

--b)
--Como funciona on MODIFICACION cascade?
create table examen
(examen_cod varchar(7),
curso_nombre varchar(20),
fecha date not null,
hora_inicio time,
hora_fin time,
primary key (examen_cod),
foreign key (curso_nombre) references curso (nombre)
 on delete cascade
 on update cascade
 );
 
insert into examen values('1910','programacion','2019-05-01','07:00:00','09:00:00');
insert into examen values('1911','arquitectura','2019-05-02','11:00:00','13:00:00');
insert into examen values('1912','algoritmos','2019-05-03','09:00:00','11:00:00');

