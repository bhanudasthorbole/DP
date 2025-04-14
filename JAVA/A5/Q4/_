import java.io.*;
import java.net.*;

public class Q4S {
    public static void main(String[] args) {
        int port = 12345;
        
        try {
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server listening on port " + port);
            
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Connection from: " + clientSocket);
                
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                
                String inputLine = in.readLine();
                int number = Integer.parseInt(inputLine);
                
                if (isPrime(number)) {
                    out.println("Prime");
                } else {
                    out.println("Not Prime");
                }
                
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        
        return true;
    }
}
