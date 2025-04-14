import java.io.*;
import java.net.*;
import java.util.*;

public class Q3S
{
	private static final int TQ = 10;

	private static final Map<String,String> questionBank = new HashMap<>();
	static{
		questionBank.put("What is Your Name?","Dinesh");
		questionBank.put("What is Surname?","Katke");
		questionBank.put("What is Capital of India?","Delhi");
		questionBank.put("What is 6+1","7");
		questionBank.put("What is Square root of 225","15");
		questionBank.put("WHat is the argest planet on solar system ","Jupiter");
		questionBank.put("WHat is chemical symbol of water","H2O");
		questionBank.put("How many sides does a hexagon have?","6");
		questionBank.put("Who discovered gravity?","Newton");
		questionBank.put("What is 12/3","4");
		questionBank.put("What is capital of Japan","Tokyo");
	}

	public static void main(String []args) throws IOException{
		try(ServerSocket serverSocket = new ServerSocket(2101)){
			System.out.println("Server started.Waiting for a client");
		
			try(Socket socket = serverSocket.accept();
			    BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			    PrintWriter output = new PrintWriter(socket.getOutputStream(),true)){
			    	System.out.println("Client COnnected");

				List<String> questions = new ArrayList<>(questionBank.keySet());
				Collections.shuffle(questions);
				List<String> selectedQuestions = questions.subList(0,TQ);

				int score = 0;

				for(String question : selectedQuestions){
					output.println(question);
					String clientAnswer = input.readLine();
					String correctAnswer = questionBank.get(question);

					if(clientAnswer != null && clientAnswer.equalsIgnoreCase(correctAnswer)){
						score++;
					}
				}

			output.println("Your final score is :"+score+"/"+TQ);
			System.out.println("Test COmpleted.Final Score sent to CLient");
			    }
		 }catch(IOException e){
		 	e.printStackTrace();
		 }

	}
}
