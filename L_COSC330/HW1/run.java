public class run {
    public static void main(String[] args) {

        final char[] PLAYER_ICONS = { 'X', 'O' };
        final int BOARD_SIZE = 3;

        Display uiDisplay = new Display();
        State gameState = new State(BOARD_SIZE, PLAYER_ICONS, 1);

        Controller ticTacToe = new Controller(gameState, uiDisplay);

        ticTacToe.playGame();
    }
}