public class Client implements MessageSender {

  public static void main(String[] args) {
    Client client = new Client();
    Server server = new Server(client);
  
    server.sendMessage("Hello world");
  }

  @Override
  public void onMessageSend(String message) {
    System.err.println("Server Response " + message);
  }
}
