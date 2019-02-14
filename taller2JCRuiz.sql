--Taller 2
--2)
select * from estudiante
where nombres like '%a%';

--3)
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






