
public class Controller {
    State gameState;
    Display gameDisplay;

    public Controller(State initialState, Display initial_display) {
        gameState = initialState;
        gameDisplay = initial_display;
    }

    public void playGame() {

        int[] userPlacement;

        while (!gameState.isGameOver()) {
            gameDisplay.displayBoard(gameState.getBoard());
            
            if(gameState.isPlayersTurn()) {
                userPlacement = gameDisplay.getPlayerMove(gameState.getBoard(), gameState.getCurrentTurn());
            }
            else {
                userPlacement = gameState.getServerMove();
            }
            gameState.makeMove(userPlacement[0], userPlacement[1]);
        }
        gameDisplay.displayBoard(gameState.getBoard());
        System.out.println("::GAME OVER::");
    }

}