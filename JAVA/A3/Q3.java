import java.io.*;

class Prime extends Thread
{
	public void run()
	{
		int i=0,num=0;
		String primeNumbers="";
		for(i=1;i<=100;i++)
		{
			int counter=0;
			for(num=i;num>=1;num--)
			{
				if(i%num==0)
				{
					counter=counter+1;
				}
			}
			if(counter==2)
			{
				primeNumbers=primeNumbers + i + "\n";
			}
		}
		System.out.println("\n Prime numbers from 1 to 100:\n"+primeNumbers);
		System.out.println("\n");
	}
}

class Palindrome extends Thread
{
	public void run()
	{
		int n,b,rev=0;
		int N=100;
		System.out.println("\n Palindrome numbers from 1 to 100:\n");
		for(int i=10;i<=N;i++)
		{
			n=i;
			while(n>0)
			{
				b=n%10;
				rev=rev*10+b;
				n=n/10;
			}
			if(rev==i)
			{
				System.out.println(i+" ");
			}
			rev=0;
		}
	}
}

class Q3
{
	public static void main(String args[])
	{
		Prime p1 = new Prime();
		Palindrome p2 = new Palindrome();

		Thread m1 = new Thread(p1);
		Thread m2 = new Thread(p2);

		m1.start();
		m2.start();

		try
		{
			m1.join();
			m2.join();
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
	}
}
