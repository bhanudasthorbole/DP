import java.io.*;
import java.net.*;

class Q2C {
    public static void main(String args[]) throws Exception {
        String str1, str2;

        System.out.println("Client is running....");

        Socket s = new Socket("localhost", 2101);

        PrintStream ps = new PrintStream(s.getOutputStream());

        BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter the Name of text file : ");
        str1 = br2.readLine();

        ps.println(str1);

        str2 = br1.readLine();
        if (str2.equals("Error: File not found")) {
            System.out.println("Error: File not found");
        } else {
            System.out.println(str2);
        }

        ps.close();
        br1.close();
        br2.close();
    }
}
