import java.net.*; 
import java.io.*; 

class Client 
{
	private Socket socket		 = null; 
	private DataInputStream input = null; 
	private DataOutputStream out	 = null; 
	private ServerSocket server = null; 
	private DataInputStream in	 = null;

	public Client(String address, int port) 
	{
		try
		{ 
			socket = new Socket(address, port); 
			System.out.println("Connected"); 
			input = new DataInputStream(System.in); 
			out = new DataOutputStream(socket.getOutputStream()); 

			in = new DataInputStream( 
				new BufferedInputStream(socket.getInputStream())); 


		} 
		catch(UnknownHostException u) 
		{ 
			System.out.println(u); 
		} 
		catch(IOException i) 
		{ 
			System.out.println(i); 
		} 

		String line = ""; 
		ChildThread ct = new ChildThread(); 
		ct.start();
			 
		while (!line.equals("Over")) 
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

	class ChildThread extends Thread 
	{ 
		String line="";
    		@Override
    		public void run()  
    		{ 
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
			try
			{
				socket.close(); 
				in.close();
			}

			catch(IOException i) 
			{ 
				System.out.println(i); 
			} 
				
		}
	}

	public static void main(String args[]) 
	{ 
		Client client = new Client("127.0.0.1", 5000); 
	} 
} 

