create table token (
	id integer,
	text varchar(5),
	category text[],
	primary key (id)
);
insert into token values(1,'lol',array['txt_1','txt_2']);
---------------
create type inventory_item as (
	name text,
	supplier_id integer,
	price numeric
);
create table on_hand(
	item inventory_item,
	count integer
);

insert into on_hand values(row('fuzzy dice',42,1.99),100);
