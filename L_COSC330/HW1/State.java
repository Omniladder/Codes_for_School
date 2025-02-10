
public class State {

    char[][] gameBoard;
    final int BOARD_SIZE;

    // Player Related Data
    final char[] PLAYER_ICONS;
    char playerIcon;
    int currentTurn = 0;
    int numPlayers;

    Server gameServer;
    Client gameClient;

    String serverType;

    public State(int NEW_BOARD_SIZE, char[] players, String[] args) {

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

    public void assignServer(Server newServer) {
        gameServer = newServer;
        gameServer.runServer();
        serverType = "Server";
        playerIcon = PLAYER_ICONS[0];
    }

    public void assignClient(Client newClient) {
        gameClient = newClient;
        gameClient.runClient();
        serverType = "Client";
        playerIcon = PLAYER_ICONS[1];
    }

    public void makeMove(int x, int y) {
        gameBoard[x][y] = PLAYER_ICONS[currentTurn];
        if (isPlayersTurn())
            sendMove(x, y, PLAYER_ICONS[currentTurn]);
        currentTurn = (currentTurn + 1) % numPlayers;
    }

    public int[] getServerMove() {
        int[] serverMove = new int[2];
        String serverInput;

        if (serverType.equals("Client")) {
            serverInput = gameClient.readData();
        } else {
            serverInput = gameServer.readData();
        }

        String[] splitString = serverInput.split("|");

        System.out.println("First Split String" + splitString[2]);

        serverMove[0] = Integer.parseInt(splitString[0]);
        serverMove[1] = Integer.parseInt(splitString[2]);

        return serverMove;
    }

    private void sendMove(int x, int y, char playerIcon) {
        String dataString = x + "|" + y + "|" + playerIcon;
        if (serverType.equals("Client")) {
            gameClient.sendData(dataString);
        } else {
            gameServer.sendData(dataString);
        }
    }

    public char[][] getBoard() {
        return gameBoard;
    }

    public char getCurrentTurn() {
        return PLAYER_ICONS[currentTurn];
    }

    public boolean isPlayersTurn() {
        return PLAYER_ICONS[currentTurn] == playerIcon;
    }

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