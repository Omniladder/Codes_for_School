
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
            gameDisplay.nextMove(gameState);
        }
        gameDisplay.displayBoard(gameState.getBoard());
        System.out.println("::GAME OVER::");
    }

}