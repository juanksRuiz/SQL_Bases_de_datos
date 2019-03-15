create table author(
	name varchar(20) not null,
	address varchar(20),
	URL varchar(100),
	primary key (name)
);
 --deberia ser formato date el año ?
 --numeric: digitos totales y despues de la coma
 -- si la relacion solo tiene un atributo ese es l llave primaria
create table book(
	ISBN integer,
	title varchar(20),
	year  varchar(20),
	price numeric(5,2),
	primary key(ISBN)
);

create table publisher (
	name varchar(20),
	address varchar (20),
	phone varchar(20),
	URL varchar(20),
	primary key(name)
	);

create table customer (
	email varchar(20),
	name varchar(20),
	address varchar (20),
	phone varchar(20),
	primary key (email)
);

create table shopping_basket(
	basket_id varchar (20),
	primary key (basket_id)
);

create table warehouse (
	code varchar(8),
	address varchar(20),
	phone varchar(20),
	primary key (code)
);

--Creacion de relaciones
--Binarias

create table basket_of (
	email varchar (20),
	basket_id varchar(20),
	primary key(email,basket_id),
	foreign key (email) references customer(email),
	foreign key (basket_id) references shopping_basket
	);
	
create table written_by(
	name varchar (20),
	ISBN integer,
	primary key (name,ISBN),
	foreign key(name) references author(name),
	foreign key (ISBN) references book(ISBN) 
	);
	
create table published_by (
	name varchar(20),
	ISBN integer,
	primary key (name,ISBN),
	foreign key (name) references publisher(name),
	foreign key (ISBN) references book(ISBN)
);

create table contains(
	ISBN integer,
	basket_id varchar(20),
	number integer,
	primary key (ISBN,basket_id),
	foreign key (ISBN) references book(ISBN),
	foreign key (basket_id) references shopping_basket(basket_id)
);

create table stocks (
	ISBN integer,
	code varchar (20),si
	number integer,
	primary key(ISBN,code),
	foreign key(ISBN) references book(ISBN),
	foreign key(code) references warehouse(code)
);

