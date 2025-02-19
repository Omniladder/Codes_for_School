
/**
 * Object relating to the user prompting and game board display
 */

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.BorderLayout;

public class View extends JFrame {

    Model gameState;
    GameGrid gameGrid;
    JLabel gameOverLabel;

    /**
     * Constructor for Entire View Page Contains separate object for board
     * 
     * @param newGameState
     */
    public View(Model newGameState) {
        super("Tic Tac Toe");
        gameState = newGameState;

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setSize(800, 800);
        // Create and set up the content pane.
        gameGrid = new GameGrid(gameState, this);
        gameGrid.setOpaque(true); // content panes must be opaque

        add(gameGrid);

        gameOverLabel = new JLabel("", SwingConstants.CENTER);
        gameOverLabel.setFont(new java.awt.Font("Arial", java.awt.Font.BOLD, 20));
        add(gameOverLabel, BorderLayout.SOUTH);

        setVisible(true);

    }

    /**
     * Handles UI and Ends game
     * 
     * @param gameState
     */
    public void endGame() {
        char winner = gameState.getWinner();

        if (winner == '_') {
            gameOverLabel.setText("Game is a Draw");
        } else {
            gameOverLabel.setText("Player " + winner + " Won");
        }

    }

    // Section Dedicated to Board Display

    /**
     * Outputs the gameboard to console
     * 
     * @param gameboard
     */
    public void displayBoard() {
        gameGrid.updateGameGrid(gameState);
    }

}