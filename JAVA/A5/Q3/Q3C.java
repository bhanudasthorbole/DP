import java.io.*;
import java.net.*;
import java.util.*;

public class Q3C
{
	public static void main(String []args) throws IOException{
		try(Socket socket = new Socket("localhost",2101);
		    BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		    PrintWriter output = new PrintWriter(socket.getOutputStream(),true);
	 	    Scanner sc = new Scanner(System.in)){
		    	System.out.println("Connected to the server.Online test Started.\n");

			for(int i=0;i<10;i++){
				String question = input.readLine();
				System.out.println("Question" +(i+1)+":"+question);

				System.out.print("Your Answer:");
				String answer = sc.nextLine();
				output.println(answer);
			}

			String finalScore = input.readLine();
			System.out.println("\n"+finalScore);

		    }catch(IOException e){
		    	e.printStackTrace();
		    }
	}
}

