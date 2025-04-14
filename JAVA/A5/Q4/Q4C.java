import java.io.*;
import java.net.*;

public class Q4C {
    public static void main(String[] args) {
        String host = "127.0.0.1";
        int port = 12345;
        
        try {
            Socket socket = new Socket(host, port);
            
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter a number: ");
            String numberStr = userInput.readLine();
            out.println(numberStr);
            
            String response = in.readLine();
            System.out.println("Server response: " + response);
            
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
