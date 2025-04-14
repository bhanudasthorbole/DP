import java.io.*;
import java.util.*;
class Student
{
	int rollno;
	String name;
	int age;
	Student(int rollno,String name,int age)
	{
		this.rollno=rollno;
		this.name=name;
		this.age=age;

	}
}
class NameComparator implements Comparator<Student>
{
	public int compare(Student s1,Student s2)
	{
		return s1.name.compareTo(s2.name);
	}
}
class AgeComparator implements Comparator<Student>
{
        public int compare(Student s1,Student s2)
        {
                return s1.age-s2.age;
        }
}

class q4
{
	public static void main(String args[])
	{
		ArrayList<Student>students=new ArrayList<>();
		students.add(new Student(50,"a",10));
		students.add(new Student(53,"c",28));
                students.add(new Student(63,"u",26));
                students.add(new Student(54,"k",20));

		System.out.println("");
		Collections.sort(students,new NameComparator());
		System.out.println("Sorted by name: ");
		for(Student s:students)
		{
			System.out.println(s.rollno+"\t"+s.name+"\t"+s.age);
		}
		
		System.out.println("");
                Collections.sort(students,new AgeComparator());
                System.out.println("Sorted by Age: ");
                for(Student s:students)
                {
                        System.out.println(s.rollno+"\t"+s.name+"\t"+s.age);
                }


	}
}

