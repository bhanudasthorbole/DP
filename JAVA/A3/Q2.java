import java.io.*;

public class Q2 extends Thread
{
	static int n;
	public void run()
	{
		if((this.getName()).equals("1"))
		{
			for(int i=0;i<n;i++)
			{
				System.out.println("\nWelcome to FY\n");
				try
				{
					Thread.sleep(10000);
				}
				catch(Exception e)
				{
					System.out.println(e);
				}
			}
		}
		else if((this.getName()).equals("2"))
                {
                        for(int i=0;i<n;i++)
                        {
                                System.out.println("\nWelcome to SY\n");
                                try
                                {
                                        Thread.sleep(10000);
                                }
                                catch(Exception e)
                                {
                                        System.out.println(e);
                                }
                        }
                }
		else if((this.getName()).equals("3"))
                {
                        for(int i=0;i<n;i++)
                        {
                                System.out.println("\nWelcome to TY\n");
                                try
                                {
                                        Thread.sleep(10000);
                                }
                                catch(Exception e)
                                {
                                        System.out.println(e);
                                }
                        }
                }
	}

	public static void main(String a[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the value of n:");
		n=Integer.parseInt(br.readLine());
		Q2 t1=new Q2();
		t1.setName("1");
		Q2 t2=new Q2();
		t2.setName("2");
		Q2 t3=new Q2();
		t3.setName("3");
		t1.start();
		t2.start();
		t3.start();
	}

}
