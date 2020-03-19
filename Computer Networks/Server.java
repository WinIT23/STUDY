import java.net.*; 
import java.io.*; 

class Server 
{ 
        Thread t = Thread.currentThread(); 


	private Socket socket = null; 
	private ServerSocket server = null; 
	private DataInputStream in	 = null; 
	private DataOutputStream out	 = null; 
private DataInputStream input = null; 

	public Server(int port) 
	{
		try
		{ 
			server = new ServerSocket(port); 
			System.out.println("Server started"); 
			System.out.println("Waiting for a client ..."); 
			socket = server.accept(); 
			System.out.println("Client accepted"); 
			input = new DataInputStream(System.in); 
			out = new DataOutputStream(socket.getOutputStream()); 
			in = new DataInputStream( 
				new BufferedInputStream(socket.getInputStream())); 
		        ChildThread ct = new ChildThread(); 
			ct.start();
			String line = "";  
			while (!line.equals("Over")) 
			{ 
				try
				{ 
					line = in.readUTF(); 
					System.out.println(line); 
				} 
				catch(IOException i) 
				{ 
					System.out.println(i); 
					break;
				} 
				
			} 
			System.out.println("Closing connection");
			socket.close(); 
			in.close(); 
			
			
		} 
		catch(IOException i) 
		{ 
			System.out.println(i); 
		} 
	} 
	
	class ChildThread extends Thread 
	{ 
		String line="";
    		@Override
    		public void run()  
    		{
			while(!line.equals("Over"))
			{
				try
				{ 
					line = input.readLine(); 
					out.writeUTF(line); 
				} 
				catch(IOException i) 
				{ 
					System.out.println(i); 
					break;
				}
			}
			
			try
			{ 
				input.close(); 		
				out.close();
			} 
			catch(IOException i) 
			{ 
				System.out.println(i);
			}
			
		}
	}

	public static void main(String args[]) 
	{ 
		Server server = new Server(5000); 
	} 
} 

