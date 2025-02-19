/**
 * Main Method Object Creates proper objects and begins game
 */
public class run {
    public static void main(String[] args) {

        final char[] PLAYER_ICONS = { 'X', 'O' };
        final int BOARD_SIZE = 3;

        Model gameState = new Model(BOARD_SIZE, PLAYER_ICONS);
        View uiDisplay = new View(gameState);

        Controller ticTacToe = new Controller(gameState, uiDisplay, args);

        ticTacToe.playGame();
    }
}