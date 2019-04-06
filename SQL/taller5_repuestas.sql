----TRIGGERS
--2)
-- TRIGGERS QUE PERMITAN QUE AL CREAR/ELIMINAR GRUPOS ( EN LA RELACION GRUPO) el registro asiciado en la relacioni curso sea actualizado,
-- aumentando o reduciendo el numero de grupos que corresponden al curso

--primero la funcion

-- new es todo el registro nuevo: se usa cuando se agrega algo
-- old es todo el registro viejo que se quita: se usa cuando se quita algo.
create or replace function triggAgregar()
returns trigger as $$
begin
	update curso
		set num_grupos = num_grupos + 1
		where curso_cod = new.curso_cod;
	return new;
end;
$$
language 'plpgsql' volatile;

-- siempre hacer for each row: ejecuta el trigger para cada vez que en este caso se inserte
create trigger triggAgregar
after insert on grupo
for each row
execute procedure triggAgregar();

--insertando
insert into grupo values('000','101','1',2019);
insert into grupo values('333','105','1',2019); --- ERROR:con llave foranea: el curso no ha sido creado
select * from curso;
--eliminando
create trigger triggEliminar
after delete on grupo
for each row
execute procedure triggEliminar();


create or replace function triggEliminar()
returns trigger as
$$
begin
	update curso
		set num_grupos = num_grupos -1
		where curso_cod = old.curso_cod;
	return new;
end;
$$
language 'plpgsql' volatile;

--Pruebas
select * from curso;
select * from grupo;

delete from grupo
where curso_cod = '000';


----3)
--TRIGGERS QUE ACTUALICEN EL CAMPO carga_creditos de los registros
--en la relacion instructor cuando se creen o eliminen registros en la relacion dicta
--El campo carga_creditos debe reflejar el numero de creditos que actualmente dicta el instructor

select * from instructor;
select * from dicta;
select creditos from curso;

-- agregando creditos
create or replace function agregarCreditos()
returns trigger as
$$
begin
	update instructor
	set carga_creditos = carga_creditos +  
		(select creditos from curso
		where curso_cod = new.curso_cod)
		where instructor.inst_id = new.inst_id;
	return new;
end;
$$
language 'plpgsql' volatile;

create trigger agregarCreditos
after insert on dicta
for each row
execute procedure agregarCreditos();

--insertando en dicta
--				inst_id |curso_cod|grupo_cod|semestre|ano
insert into dicta values('1','000','101','1',2019);

select * from curso;
select * from grupo;
select * from instructor;
select * from dicta;

-- eliminando en dicta
create or replace function bajarCreditos()
returns trigger as
$$
begin
	update instructor
		set carga_creditos = carga_creditos - (
			select creditos from curso
			where curso_cod = old.curso_cod)
			where instructor.inst_id = old.inst_id;
	return new;		
			
end;
$$
language 'plpgsql' volatile;

--TRIGGER
create trigger bajarCreditos
after delete on dicta
for each row
execute procedure bajarCreditos();

--drop trigger bajarCreditos;

delete from dicta
where curso_cod = '000';

