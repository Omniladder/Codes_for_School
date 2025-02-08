
public class State {

    char[][] gameBoard;
    final int BOARD_SIZE;

    // Player Related Data
    final char[] PLAYER_ICONS;
    char playerIcon;
    int currentTurn;
    int numPlayers;

    public State(int NEW_BOARD_SIZE, char[] players, int first_player) {

        BOARD_SIZE = NEW_BOARD_SIZE;
        gameBoard = new char[BOARD_SIZE][BOARD_SIZE];

        PLAYER_ICONS = players;
        numPlayers = PLAYER_ICONS.length;

        currentTurn = first_player;

        for (int x = 0; x < BOARD_SIZE; x++) {
            for (int y = 0; y < BOARD_SIZE; y++) {
                gameBoard[x][y] = ' ';
            }
        }
    }

    public void makeMove(int x, int y) {
        gameBoard[x][y] = PLAYER_ICONS[currentTurn];
        currentTurn = (currentTurn + 1) % numPlayers;
        //TODO: Send Board through Server
    }

    public int[] getServerMove(){
        int[] serverMove = new int[2];
        //TODO: Get server Input
        currentTurn = (currentTurn + 1) % numPlayers;
        return serverMove;
    }

    public char[][] getBoard() {
        return gameBoard;
    }

    public char getCurrentTurn() {
        return PLAYER_ICONS[currentTurn];
    }

    public boolean isPlayersTurn(){
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