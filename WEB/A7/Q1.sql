
drop table movie_actor cascade;
drop table movie cascade;
drop table actor cascade;





create table movie(movie_no int primary key, movie_name varchar(30), release_year int);
insert into movie values (1,'M1',2011);
insert into movie values (2,'M2',1993);
insert into movie values (3,'M3',1986);
insert into movie values (4,'M4',2023);
insert into movie values (5,'M5',2015);
insert into movie values (6,'M6',2000);






create table actor(actor_no int primary key, name varchar(30));
insert into actor values(101,'A1');
insert into actor values(102,'B1');
insert into actor values(103,'C1');
insert into actor values(104,'D1');
insert into actor values(105,'E1');
insert into actor values(106,'F1');




create table movie_actor(movie_no int references movie(movie_no) on delete cascade, actor_no int references actor(actor_no ) on delete cascade, rate int);
insert into movie_actor values(1,101,500);
insert into movie_actor values(2,102,400);
insert into movie_actor values(3,103,300);
insert into movie_actor values(4,104,200);
insert into movie_actor values(5,105,100);
insert into movie_actor values(6,106,50);

SELECT * FROM movie;
SELECT * FROM actor;
SELECT * FROM movie_actor;
