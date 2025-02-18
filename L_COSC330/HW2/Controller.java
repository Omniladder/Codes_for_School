import java.util.Scanner;

/**
 * Handles the actual game functionality and calls functions approiately based
 * on rules
 */
public class Controller {
    State gameState;
    View gameDisplay;
    String[] args;
    Scanner kb_input = new Scanner(System.in);

    public Controller(State initialState, View initialDisplay, String[] initialArgs) {
        gameState = initialState;
        gameDisplay = initialDisplay;
        args = initialArgs;
        makeClientServer();
    }

    /**
     * Functionality for running the game more or less the main function of the
     */
    public void playGame() {
        int[] movePlacement;

        while (!gameState.isGameOver()) {
            gameDisplay.displayBoard();
            movePlacement = gameState.getServerMove();
            gameState.makeServerMove(movePlacement[0], movePlacement[1]);
        }
        gameDisplay.displayBoard();
        gameDisplay.endGame();
        gameState.closeGame();
    }

    // Section Dedicated to Creation of Server

    /**
     * Handles creation of Clietn and sserver with Console Prompting in case user
     * has forgotten
     */
    private void makeClientServer() {

        String serverType;

        if (args.length >= 1) {
            if (args[0].equals("Server") || args[0].equals("Client")) {
                serverType = args[0];
            } else {
                serverType = chooseServerType();
            }
        } else {
            serverType = chooseServerType();
        }

        if (serverType.equals("Client")) {
            Client gameClient;
            if (args.length < 2) {
                gameClient = new Client(getClientIP());
            } else {
                gameClient = new Client(args[1]);
            }
            gameState.assignClient(gameClient);
        } else {
            Server gameServer;
            gameServer = new Server();
            gameState.assignServer(gameServer);
        }
    }

    /**
     * 
     * Function dedicated to prompting of user to get desired Server type
     * 
     * @param args List of commandline arguments allowing for faster intiation of
     *             program
     * @return Users Desired Server type
     */
    private String chooseServerType() {
        String userInput;

        while (true) {
            System.out.println("Type 'Server' to run as a server or 'Client' to connect to a server:");
            userInput = kb_input.nextLine();
            if (userInput.equals("Server") || userInput.equals("Client")) {
                return userInput;
            }
            System.out.println("Invalid input Please type Server or Client");
        }
    }

    /**
     * Handles the Prompting and handling of grabbing players hostname
     * 
     * @return String HostName
     */
    private String getClientIP() {
        System.out.println("Input Client IP");
        String userInput = kb_input.nextLine();
        return userInput;
    }
}