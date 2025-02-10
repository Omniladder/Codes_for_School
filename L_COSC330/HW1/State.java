/**
 * This is the Tic Tac Toe game state
 * 
 * This Object handles all backend functionality and manages the variables
 * relating to the tic tac toe board and game.
 * 
 */

public class State {

    // Game Board based Data
    char[][] gameBoard;
    final int BOARD_SIZE;

    // Player Related Data
    final char[] PLAYER_ICONS;
    char playerIcon;
    int currentTurn = 0;
    int numPlayers;

    // Server Based Data
    Server gameServer;
    Client gameClient;
    String serverType;

    /**
     * Constructor method for game State
     * 
     * @param NEW_BOARD_SIZE - Size of the board allowing for theortically larger or
     *                       smaller board SUGGEST: 3
     * @param players        - A Char Array for Player Tokens allowing for different
     *                       usage.
     */
    public State(int NEW_BOARD_SIZE, char[] players) {

        BOARD_SIZE = NEW_BOARD_SIZE;
        gameBoard = new char[BOARD_SIZE][BOARD_SIZE];

        PLAYER_ICONS = players;
        numPlayers = PLAYER_ICONS.length;

        for (int x = 0; x < BOARD_SIZE; x++) {
            for (int y = 0; y < BOARD_SIZE; y++) {
                gameBoard[x][y] = ' ';
            }
        }
    }

    /**
     * More or less a setter method for the server variables also handles some other
     * elements relating to server
     * 
     * @param newServer - Server to be set too.
     */
    public void assignServer(Server newServer) {
        gameServer = newServer;
        gameServer.runServer();
        serverType = "Server";
        playerIcon = PLAYER_ICONS[0];
    }

    /**
     * More or less a setter method for the server variables also handles some other
     * elements relating to Cleint
     * 
     * @param newClient - New Client to be set too
     */
    public void assignClient(Client newClient) {
        gameClient = newClient;
        gameClient.runClient();
        serverType = "Client";
        playerIcon = PLAYER_ICONS[1];
    }

    /**
     * Closes all Server Connections for when game is over.
     */
    public void closeGame() {
        if (serverType.equals("Server")) {
            gameServer.closeConnection();
        } else {
            gameClient.closeConnection();
        }
    }

    /**
     * Handles updating board and relevant information based on a inputted move.
     * 
     * @param x - X posistion to set
     * @param y - Y posistion to set
     */
    public void makeMove(int x, int y) {
        gameBoard[x][y] = PLAYER_ICONS[currentTurn];
        if (isPlayersTurn()) {
            sendMove(x, y);
        }
        currentTurn = (currentTurn + 1) % numPlayers;
    }

    /**
     * Queries the Server and waits for a new move to be sent from Client/Server
     * 
     * @return Server Move [x,y] the X and Y coordinates of the new placed tile.
     */
    public int[] getServerMove() {
        int[] serverMove = new int[2];
        String serverInput;

        if (serverType.equals("Client")) {
            serverInput = gameClient.readData();
        } else {
            serverInput = gameServer.readData();
        }

        String[] splitString = serverInput.split("|");

        serverMove[0] = Integer.parseInt(splitString[0]);
        serverMove[1] = Integer.parseInt(splitString[2]);

        return serverMove;
    }

    /**
     * Helper method that sends data across server to other player
     * 
     * @param x - X posistion of Move
     * @param y - Y posistion of Move
     */
    private void sendMove(int x, int y) {
        String dataString = x + "|" + y;
        if (serverType.equals("Client")) {
            gameClient.sendData(dataString);
        } else {
            gameServer.sendData(dataString);
        }
    }

    /**
     * Getter method for current board state
     * 
     * @return Game Board
     */
    public char[][] getBoard() {
        return gameBoard;
    }

    /**
     * Returns the charcter of the player whos move it currently is
     * 
     * @return Current Player Token Char
     */
    public char getCurrentTurn() {
        return PLAYER_ICONS[currentTurn];
    }

    /**
     * Identifies if it currently is or isnt this players turn
     * 
     * @return True or False
     */
    public boolean isPlayersTurn() {
        return PLAYER_ICONS[currentTurn] == playerIcon;
    }

    /**
     * Determines if the game has been one or if all tiles are full such that it is
     * a draw.
     * 
     * @return
     */
    public boolean isGameOver() {

        boolean currentCondition = true;

        // Checks the board condition of if its full
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int column = 0; column < BOARD_SIZE; column++) {
                if (gameBoard[row][column] == ' ') {
                    currentCondition = false;
                    break;
                }
            }
        }
        if (currentCondition == true) {
            return true;
        }

        // This section checks all rows for a win condition

        for (int row = 0; row < BOARD_SIZE; row++) {
            currentCondition = true;
            for (int column = 1; column < BOARD_SIZE; column++) {
                if (gameBoard[row][column - 1] != gameBoard[row][column]) {
                    currentCondition = false;
                    break;
                }
                if (gameBoard[row][column] == ' ') {
                    currentCondition = false;
                    break;
                }
            }
            if (currentCondition == true) {
                return true;
            }
        }

        // This section checks all columns for a win condition
        for (int column = 0; column < BOARD_SIZE; column++) {
            currentCondition = true;
            for (int row = 1; row < BOARD_SIZE; row++) {
                if (gameBoard[row][column] != gameBoard[row - 1][column]) {
                    currentCondition = false;
                    break;
                }
                if (gameBoard[row][column] == ' ') {
                    currentCondition = false;
                    break;
                }
            }

            if (currentCondition == true) {
                return true;
            }
        }

        // This section checks Left to Right Diagonal for Win
        currentCondition = true;
        for (int currentIndex = 1; currentIndex < BOARD_SIZE; currentIndex++) {
            if (gameBoard[currentIndex][currentIndex] != gameBoard[currentIndex - 1][currentIndex - 1]) {
                currentCondition = false;
                break;
            }
            if (gameBoard[currentIndex][currentIndex] == ' ') {
                currentCondition = false;
                break;
            }
        }
        if (currentCondition == true) {
            return true;
        }

        // This section checks Right to Left Diagonal for Win
        currentCondition = true;
        for (int currentIndex = 1; currentIndex < BOARD_SIZE; currentIndex++) {
            if (gameBoard[(BOARD_SIZE - 1) - currentIndex][currentIndex] != gameBoard[(BOARD_SIZE - 1)
                    - (currentIndex - 1)][currentIndex - 1]) {
                currentCondition = false;
                break;
            }
            if (gameBoard[currentIndex][currentIndex] == ' ') {
                currentCondition = false;
                break;
            }
        }
        if (currentCondition == true) {
            return true;
        }

        return false;
    }

}