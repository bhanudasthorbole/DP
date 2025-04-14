import java.io.*;

class PrintText extends Thread
{
	String text;
	int n;
	PrintText(String t,int times)
	{
		text=t;
		n=times;
	}
	public void run()
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(text);
			try
			{
				Thread.sleep(1000);
			}
			catch(Exception e)
			{
				System.out.println(e);
			}
		}
	}
}

public class Q4
{
	public static void main(String args[])throws IOException
	{
		int n;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("\n Enter N:");
		n=Integer.parseInt(br.readLine());
		PrintText t1 = new PrintText("First",n);
		t1.start();
		PrintText t2 = new PrintText("Second",n);
		t2.start();
		PrintText t3 = new PrintText("Third",n);
		t3.start();
	}
}
