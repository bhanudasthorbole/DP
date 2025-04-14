import java.io.*;
import java.net.*;

class Q1S
{
  public static void main(String args[])throws Exception
  {
   String str1,str2;

   ServerSocket ss = new ServerSocket(2101);

   System.out.println("Server is Running.....");

   Socket s = ss.accept();

   System.out.println("Connection is Successfully established...");
  }
}
