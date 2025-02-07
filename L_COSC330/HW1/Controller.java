
public class Controller {
    State gameState;
    Display gameDisplay;

    public Controller(State initialState, Display initial_display) {
        gameState = initialState;
        gameDisplay = initial_display;
    }

    public void playGame() {

        while (!gameState.isGameOver()) {
            gameDisplay.displayBoard(gameState.getBoard());
            int[] userPlacement = gameDisplay.getUserInput(gameState.getBoard(), gameState.getCurrentTurn());
            gameState.makeMove(userPlacement[0], userPlacement[1]);
        }
        gameDisplay.displayBoard(gameState.getBoard());
        System.out.println("::GAME OVER::");
    }

}