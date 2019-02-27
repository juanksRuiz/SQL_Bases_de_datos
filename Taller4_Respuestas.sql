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
--¿Qué hace la vista?,
----R: es una consulta de la relacion de con la cual se crea la vista, se actualiza con modificaciones
-----------------------------

create view vista_presupuesto as
select avg(presupuesto) as prom_presupuesto, min(presupuesto) as min_presupuesto, max(presupuesto) as max_presupuesto, stddev(presupuesto) as desv_estandar_presup
from unid_acad;

----6)


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
--Vista materializada: guarda en memoria una vista que se crea. hasta que se refresque (VER PUNTO C) no se actualiza
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

----8) TRANSACCIONES
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
--R:  on delete cascade: 	Si se borra un registro con un nombre en  la relacion 'curso'
-- se borran todos los registros en los cuales aparece el nombre en la tabla 'examen'
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

--c) 
insert into examen values('1910','programacion','2019-05-01','07:00:00','09:00:00');
insert into examen values('1911','arquitectura','2019-05-02','11:00:00','13:00:00');
insert into examen values('1912','algoritmos','2019-05-03','09:00:00','11:00:00');

--d)
update curso
	set nombre = 'prog computadores'
	where nombre = 'programacion';

--e)
-- si se quiere operar con fechas  y EXTRAER datos
select curso_nombre, hora_inicio, extract (hour from hora_fin - hora_inicio)
from examen;

-- si se quiere solo OPERAR CON FECHAS
/*
select curso_nombre, hora_inicio, hora_fin - hora_inicio
from examen;
*/

create view duracionExamenes as
	select curso_nombre, extract (hour from hora_inicio) as hora, hora_fin - hora_inicio as duracion
	from examen;
	
----10)
--CREANDO DOMINIOS (TIPOS CREADOS)
create domain credito as
	int check(value > 0);
	
--Modificando tipo de dato de una olumna
alter table curso
	alter column creditos type credito;
	
-- 11) AUTORIZACIONES DE ACCESO
-- PARA CREAR USUARIOS Y ROLES : 1) DESCONECTARSE Y CONECTARSE COMO POSTGRES, 2) CREAR USUARIOS/ ROLES EN  LA TERMINAL
--a)
--creando usuarios
create user ramon with password 'ramon';
grant select on unid_acad;

--b)
select * from unid_acad;
-- no se va a poder, PERMISOS DENEGADOS
insert into unid_acad values('FILO','Cabal',1250);

--c)
-- Creando roles ,es decir, 'grupos' de usuarios
create role planeacion;
grant insert on unid_acad to ramon;
--Otorgando permisos de rol a rol
grant planeacion to ramon;

insert into unid_acad values('ADMIN','Norte',1700);





	

	
