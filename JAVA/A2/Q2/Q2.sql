drop table Workload2;
drop table Teacher2;
create table Teacher2(Teacher_Id int primary key,Teacher_Name varchar(30) NOT NULL);
create table Workload2(Subject_code int primary key , Subject_Name varchar(30) NOT NULL,Date DATE NOT NULL,Time TIME NOT NULL,Class varchar(20) NOT NULL,Teacher_Id int  REFERENCES Teacher2(Teacher_Id)on delete cascade);
