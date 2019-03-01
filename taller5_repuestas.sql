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
language 'plpgsql'volatile;

-- siempre hacer for each row: ejecuta el trigger para cada vez que en este caso se inserte
create trigger triggAgregar
after insert on grupo
for each row
execute procedure triggAgregar();

--insertando
insert into grupo values('000','101','1',2019);
insert into grupo values('333','105','1',2019); --- ERROR:con llave foranea: el curso no ha sido creado
select * from curso;

