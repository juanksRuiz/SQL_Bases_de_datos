create table author(
	name varchar(20) not null,
	address varchar(20),,
	URL varchar(100),
	primary key (name)
);
 --deberia ser formato date el año ?
 --numeric: digitos antes y despues de la coma
create table book(
	ISBN integer,
	title varchar(20),
	year  varchar(20),
	price numeric(5,2)
	primary key (ISBN)
);

create table publisher (
	name varchar(20),
	);