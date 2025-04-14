drop table student_comp cascade;
drop table student cascade;
drop table competition cascade;




--student(id,name,class)
create table student( stud_id int primary key, name varchar(30), class varchar(20));
insert into student values(1,'OM','1st');
insert into student values(2,'Dinesh','2nd');



--competition(no,name,type)
create table competition(c_no int primary key, c_name varchar(30), type varchar(20));
insert into competition values(1001,'ludo','Indoor');
insert into competition values(1002,'cricket','Outdoor');




--manyTOmany
create table student_comp(stud_id int references student(stud_id) on delete cascade, c_no int references competition(c_no) on delete cascade, rank varchar(20), year int);
insert into student_comp values(2,1002,'1st', 2020);
insert into student_comp values(1,1001,'2nd', 2021);



SELECT * FROM student;
SELECT * FROM competition;
SELECT * FROM student_comp;
