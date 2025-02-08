import java.util.Scanner;

import javax.swing.JFrame;

import Server.Client;
import Server.Server;

public class Display {

    Scanner kb_input = new Scanner(System.in);

    /**
     * Draws a horizontal line to segment the board with.
     * 
     * @param boardSize size of the board in the X direction used to calculate
     *                  number of squares to draw
     */
    private void drawLine(int boardSize) {
        for (int i = 0; i < boardSize; i++) {
            System.out.print("+-");
        }
        System.out.println("+");
    }

    /**
     * Helper function used for drawing a row of the gamebord
     * 
     * @param gameRow the row of indexes to be drawn
     */
    private void drawRow(char[] gameRow) {
        for (int i = 0; i < gameRow.length; i++) {
            System.out.print("¦" + gameRow[i]);
        }
        System.out.println("¦");
    }

    /**
     * Outputs the gameboard to console
     * 
     * @param gameboard
     */
    public void displayBoard(char[][] gameboard) {
        clearScreen();
        for (int i = 0; i < gameboard.length; i++) {
            drawLine(gameboard[i].length);
            drawRow(gameboard[i]);
        }
        drawLine(gameboard[0].length);
    }

    /**
     * Simple function for clearing screen of all text
     */
    private void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    /**
     * Handles getting next move no matter whos turn it is
     * 
     * @param gameState
     */
    public void nextMove(State gameState) {
        if (gameState.isCurrentTurn()) {
            int[] userPlacement = getUserInput(gameState.getBoard(), gameState.getCurrentTurn());
            gameState.makeMove(userPlacement[0], userPlacement[1]);
        } else {

        }
    }

    public JFrame makeClientServer(String[] args) {
        JFrame clientServer;
        String serverType = chooseServerType(args);

        if (serverType.equals("Client")) {
            if (args.length < 2) {
                clientServer = new Client(getClientIP());
            } else {
                clientServer = new Client(args[1]);
            }
        } else {
            clientServer = new Server();
        }

        return clientServer;
    }

    private String getClientIP() {
        System.out.println("Input Client IP");
        String userInput = kb_input.nextLine();
        return userInput;
    }

    private String chooseServerType(String[] args) {
        String userInput;

        if (args.length >= 1) {
            if (args[0].equals("Server") || args[0].equals("Client")) {
                return args[0];
            }
        }

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
     * Simple Method for getting where the user want there tile placed. with lots of
     * input validation
     * 
     * @param gameboard this is the current gameboard state used to input validate
     *                  size
     * @return user selected coordinate [x, y]
     */
    public int[] getPlayerMove(char[][] gameboard, char currentPlayer) {

        int user_input_X, user_input_Y;

        System.out.println("Player " + currentPlayer + " Turn:");

        do {

            user_input_X = -1;
            user_input_Y = -1;

            System.out.println("\nEnter the X Value to Place");

            while (0 > user_input_X || user_input_X >= gameboard.length) {
                while (!kb_input.hasNextInt()) {
                    System.out.println("Please enter an integer.");
                    kb_input.next();
                }

                user_input_X = kb_input.nextInt();

                if (0 > user_input_X || user_input_X >= gameboard.length) {
                    System.out.println("::INVALID INPUT:: KEEP BETWEEN 0 and " + (gameboard.length - 1));
                }
            }

            System.out.println("\nEnter the Y Value to Place");

            while (0 > user_input_Y || user_input_Y >= gameboard.length) {
                while (!kb_input.hasNextInt()) {
                    System.out.println("Please enter an integer.");
                }

                user_input_Y = kb_input.nextInt();

                if (0 > user_input_Y || user_input_Y >= gameboard.length) {
                    System.out.println("::INVALID INPUT:: KEEP BETWEEN 0 and " + (gameboard.length - 1));
                }
            }
            if (gameboard[user_input_X][user_input_Y] != ' ') {
                System.out.println("::Invalid Placement:: Space Already Taken Please Try Again");
                displayBoard(gameboard);
            }
        } while (gameboard[user_input_Y][user_input_X] != ' ');
        int[] user_input = { user_input_Y, user_input_X };
        return user_input;
    }
}