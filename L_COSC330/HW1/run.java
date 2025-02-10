/**
 * Main Method Object
 */
public class run {
    public static void main(String[] args) {

        final char[] PLAYER_ICONS = { 'X', 'O' };
        final int BOARD_SIZE = 3;

        Display uiDisplay = new Display();
        State gameState = new State(BOARD_SIZE, PLAYER_ICONS);
        uiDisplay.makeClientServer(gameState, args);

        Controller ticTacToe = new Controller(gameState, uiDisplay);

        ticTacToe.playGame();
    }
}