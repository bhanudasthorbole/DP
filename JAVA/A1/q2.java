import java.io.*;
import java.util.*;
class q2
{
	public static void main(String args[]) throws IOException
	{
		LinkedList l1=new LinkedList();
		LinkedList l2=new LinkedList();
	        LinkedList l3=new LinkedList();
	        LinkedList l4=new LinkedList();

		int n,t,t1;
		String ch;
		Scanner sc=new Scanner(System.in);

		System.out.println("\n enter how many number for Linkedlist 1: ");
		t=sc.nextInt();
		for(int i=0;i<t;i++)
		{
			System.out.println("enter the number: ");
			n=sc.nextInt();
			while(l1.contains(n)==true)
			{
				System.out.println("duplaicate values are not allowed");
				n=sc.nextInt();
			}
			l1.add(n);
		}
		System.out.println("\n enter how many number for Linkedlist 2: ");
		t1=sc.nextInt();
                for(int i=0;i<t1;i++)
                {
                        System.out.println("enter the number: ");
                        n=sc.nextInt();
                        while(l2.contains(n)==true)
                        {
                                System.out.println("duplaicate values are not allowed");
                                n=sc.nextInt();
                        }
                        l2.add(n);

                }
		System.out.println("LinkedList 1:"+l1+"\n");
		System.out.println("LinkedList 2:"+l2+"\n");

		for(int i=0;i<l1.size();i++)
		{
			l3.add(l1.get(i));
		}
		for(int i=0;i<l2.size();i++)
                {
                        if(l3.contains(l2.get(i))==false)
				l3.add(l2.get(i));
                }
		for(int i=0;i<l1.size();i++)
                {
                        l4.add(l1.get(i));
                }
		l4.retainAll(l2);
		System.out.println("union :"+l3+"\n");
                System.out.println("intersection:"+l4+"\n");
	}
}
