import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class GameGrid extends JPanel {
    protected JButton[][] gameBoard = new JButton[3][3];

    ImageIcon xIcon = new ImageIcon("pics/XShape.png");
    ImageIcon oIcon = new ImageIcon("pics/OShape.png");
    ImageIcon emptyIcon = new ImageIcon("pics/EmptySquare.png");

    Model currentState;
    View gameDisplay;

    /**
     * Action Listener for buttons sends signal to client with move
     */
    public class MoveAction implements ActionListener {
        final int thisX;
        final int thisY;
        Model gameState;
        View gameDisplay;

        /**
         * Basic constructor
         * 
         * @param newGameState
         * @param newGameDisplay
         * @param X
         * @param Y
         */
        public MoveAction(Model newGameState, View newGameDisplay, int X, int Y) {
            thisX = X;
            thisY = Y;
            gameState = newGameState;
            gameDisplay = newGameDisplay;
        }

        /**
         * Actual action attempts to make move and updates board visuals
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            gameState.makePlayerMove(thisX, thisY);
            updateGameGrid(gameState);
            if (gameState.isGameOver()) {
                gameDisplay.endGame();
            }
        }
    }

    /**
     * Game grid object relates to all cisuals part of the game board
     * 
     * @param gameState
     * @param newGameView
     */
    public GameGrid(Model gameState, View newGameView) {

        currentState = gameState;

        setLayout(new GridLayout(3, 3));

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {

                gameBoard[x][y] = new JButton();
                gameBoard[x][y].setIcon(emptyIcon);

                gameDisplay = newGameView;

                gameBoard[x][y].addActionListener(new MoveAction(gameState, gameDisplay, x, y));
                add(gameBoard[x][y]);
            }
        }

    }

    /**
     * upfates board visuals to givven state
     * 
     * @param gameState
     */
    public void updateGameGrid(Model gameState) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                char symbol = gameState.getBoard()[x][y];
                if (symbol == ' ')
                    gameBoard[x][y].setIcon(emptyIcon);
                else if (symbol == 'X') {
                    gameBoard[x][y].setIcon(xIcon);
                } else {
                    gameBoard[x][y].setIcon(oIcon);
                }

            }
        }
    }
}