--2 : SQL PROCEDIMENTAL
-- BEGIN NO TIENE COMA
-- ¿VOLATILE STABLE IMMUTABLE?
----2)
create or replace function totalMaterias()
returns int as
$$
declare
	resultado int;
	i record;
begin
	resultado:= 0;
	select into resultado count(*) from curso;
	return resultado;
end;
$$
language 'plpgsql' immutable;

select totalMaterias();

------------------
--Si necesito seleccionar 2 o más atributos el int del loop es RECORD, sino es int
create or replace function totalMateriasCreditos()
returns int as
$$
declare
	resultado int;
	i int;
begin
	resultado:= 0;
	for i in
		select creditos from curso where creditos > 0
	loop
		resultado:= resultado + i;
	end loop;
	return resultado;
end;
$$
language 'plpgsql' immutable;

-------------------
create or replace function totalMateriasCreditos2()
returns int as
$$
declare
	resultado int;
	i record;
begin
	resultado:= 0;
	for i in
		select * from curso where creditos > 0
	loop
		resultado := resultado + i.creditos;
	end loop;
	return resultado;
end;
$$
language 'plpgsql' immutable;

select totalMAteriasCreditos2();

-------------------
create or replace function totalMateriasCreditos3(numcreditos integer)
returns int as
$$
declare
	resultado int;
	i record;
begin
	resultado := 0;
	for i in 
		select * from curso where creditos > 0
	loop
		if i.creditos > numcreditos then
			resultado:= resultado + i.creditos;
		else
			resultado:= resultado - 1;
		end if;
	end loop;
	return resultado;
end;
$$
language 'plpgsql' immutable;

select totalMateriasCreditos3(4);

------------------------------
 
 
 --si se quiere retornar una tabla

create or replace function reporteCursos()
returns table (
	codigo_curso varchar,
	nombre_curso varchar
	) as
$$
begin
	return query
		select curso_cod as codigo_curso, nombre as nombre_curso
		from curso;
end;
$$
language 'plpgsql' immutable;

--EJECUTANDO LA FUNCION
SELECT reporteCursos();

----3)
--select into resultado count(*) from curso;
--> ASIGNANDO VALOR count(*) de curso a variable resultado

create or replace function razonGruposProf()
returns float as
$$
declare
	numGrupos bigint;
	numProf bigint;
	resultado float(10);
begin
	resultado:= 0;
	select into numGrupos count(*) from grupo;
	select into numProf count(*) from instructor;
	resultado := numGrupos/numProf;
	return resultado;
end;
$$
language 'plpgsql' immutable;

select razonGruposProf();

----5)  (el 4 es similar)
create or replace function textRazon()
returns varchar as
$$
declare
	texto varchar(30);
	frac float(10);
begin
	frac:= razonGruposProf();
	if frac < 2 then
		texto:= 'Razón inferior a 2';
	else
		texto:= 'Razón igual o superior a 2';
	end if;
	return texto;
end;
$$
language 'plpgsql' immutable;

select textRazon();

----6)
--funcion que retorne table con el nombre de cada unidad y el numero de cursos ofrecidos por cada unidad
create or replace function unidAcadCurso()
returns table (
	nombre_unid_acad varchar,
	numCursos bigint) as
$$
begin
	return query
		select curso.nombre_unid as nombre_unid_acad, count(curso.nombre_unid) as numCursos
		from unid_acad left outer join curso
		on unid_acad.nombre_unid = curso.nombre_unid
		group by curso.nombre_unid
end;
$$
language 'plpgsql' immutable;

select unidAcadCurso();
select * from unid_acad;
select * from curso;

------
select  curso.nombre_unid , count(*)
		from unid_acad left outer join curso
		on unid_acad.nombre_unid = curso.nombre_unid
		group by curso.nombre_unid;

select  curso.nombre_unid , count(*)
		from unid_acad natural join curso
		group by curso.nombre_unid;


