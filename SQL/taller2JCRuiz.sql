--Taller 2
--2)
select * from estudiante
where nombres like '%a%';

--3)
select * from estudiante
where nombres like '___';
--4)
select * from estudiante
where nombres like 'A%';

----a)
select nombres, apellidos, curso_cod
from (
select * from estudiante
where nombres like 'A%'
) as A join estCursos
on A.id = estcursos.estid;

----b)
select nombres, apellidos, curso_cod
from (
select * from estudiante
where nombres like 'A%'
) as A join estcursos
on A.id = estCursos.estid
where nota < 3.0

--5)
--a
(select * from curso) union all (select * from curso2)
order by curso_cod;

--b
(select * from curso) union (select * from curso2)
order by curso_cod;

--c
(select * from curso) intersect (select * from curso2)
order by curso_cod;

--d
(select * from curso) except (select * from curso2)
order by curso_cod;

--e
(select * from curso2) except (select * from curso)
order by curso_cod;

--f (diferencia simetrica)
((select * from curso) except (select * from curso2))
union ((select * from curso2) except (select * from curso));

--g
-- o select count(A.nombre), por ejemplo
select count(*)
from (
((select * from curso) except(select * from curso2))
 union ((señect * from curso2) except (select * from curso))
) as A;

------------------------------------------------------------
--Punto 3 taller 2
--2)
select * from curso
where nombre_unid = 'MACC' and nombre like '%it%';

----3)
--a)
select inst_id, curso_cod
from dicta;

--b)
select curso.nombre, dicta.inst_id
from dicta join curso
on dicta.curso_cod = curso-curso_cod;

--c)
------ayuda
select curso.nombre as Nombre_curso, dicta.inst_id as ID_instructor
from dicta join curso
on dicta.curso_cod = curso.curso_cod;
---------------

select nombre_curso, nombre as nombre_instructor, apellidos
from (
	select curso.nombre as Nombre_curso, dicta.inst_id as ID instructor
	from dicta join curso
	on dicta.curso_cod = curso.curso_cod)
as A join instructor
on A.id_instructor = instructor.inst_id ;

----4)
select avg(creditos)
from curso
where nombre_unid = 'MACC';

----5)
--a)
select nombre_unid, avg(creditos) as Prom_creditos
from curso
group by nombre_unid
order by nombre_unid;

--b)
select A.prom_creditos
from
(select nombre_unid, avg(creditos) as prom_creditos
from curso
group by nombre_unid
order by nombre_unid) as A
where A.prom_creditos <= 4.0 ;

----6)
select nombre_unid, avg(salario) as prom_salario, min(salario) as min_salario, max(salario) as max_salario
from instructor
group by nombre_unid;












