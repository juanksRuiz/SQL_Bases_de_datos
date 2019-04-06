--Conjubntos de entidades
create table avion(
	ID_avion varchar(10),
	modelo text,
	primary key(ID_avion)
);

create table ciudad(
	nombre varchar(20),
	primary key (nombre)
);
--DUDA SOBRE ATRIBUROS: origen, destino
create table vuelo(
	cod_vuelo varchar(10),
	origen varchar(20),
	destino varchar(20),
	primary key (cod_vuelo),
	foreign key (origen) references ciudad(nombre),
	foreign key (destino) references ciudad(nombre)
);

create table usuario (
	ID varchar(10),
	nombres varchar(20),
	apellidos varchar(20),
	edad int,
	primary key(ID)
);

--Cojuntos de relaciones
create table atiende(
	ID_avion varchar(10),
	cod_vuelo varchar(10),
	primary key(ID_avion,cod_vuelo),
	foreign key (ID_avion) references avion(ID_avion),
	foreign key (cod_vuelo) references vuelo(cod_vuelo)
);

create table reserva(
	ID varchar(10),
	cod_vuelo varchar(10),
	silla text,
	primary key(ID,cod_vuelo),
	foreign key (ID) references usuario(ID),
	foreign key (cod_vuelo) references vuelo(cod_vuelo)
);

create table se_dirige_a(
	cod_vuelo varchar(10),
	nombre varchar(20),
	primary key(cod_vuelo,nombre),
	foreign key (cod_vuelo) references vuelo(cod_vuelo),
	foreign key (nombre) references ciudad(nombre)
);