import java.io.*;
import java.util.*;
class q1
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		HashMap<String,String>hm=new HashMap<>();
		System.out.println("\n how many persons: ");
		int n=sc.nextInt();

		for(int i=0;i<n;i++)
		{
			System.out.println("enter "+(i+1)+"person name: ");
			String pname=sc.next();
			System.out.println("enter "+(i+1)+"person phone no.: ");
			String pno=sc.next();
			hm.put(pname,pno);

		}
		System.out.println(hm.keySet());
		
		System.out.println("enter a name to get phone number: ");
		String getname=sc.next();

		if(hm.containsKey(getname))
		{
		       	System.out.println(hm.get(getname));

		}
		else
		{
			System.out.println("person not present in hashtable");

		}


	}
}
