import javax.swing.*;
import java.awt.*;
import javax.swing.border.MatteBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashSet;
import java.util.Random;

public class SudokuSolverGUI extends JFrame {
    private static final int SIZE = 9;
    private JTextField[][] cells = new JTextField[SIZE][SIZE];
    private int[][] board = new int[SIZE][SIZE];
    private HashSet<Integer>[] rows = new HashSet[SIZE];
    private HashSet<Integer>[] cols = new HashSet[SIZE];
    private HashSet<Integer>[] subgrids = new HashSet[SIZE];
    private volatile boolean stopSolving = false;
    private int delay = 500; // Default delay for slow speed
    private Color[] lightTheme = {Color.BLACK, Color.WHITE, Color.GRAY, Color.GREEN, Color.RED};
    private Color[] darkTheme = {Color.WHITE, Color.BLACK, Color.DARK_GRAY, Color.LIGHT_GRAY, Color.RED};
    private boolean isLightTheme = true;


    private int[][][] puzzles = {
            {
                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
            },
            {
                    {0, 0, 0, 0, 0, 0, 0, 1, 2},
                    {0, 0, 0, 0, 0, 3, 0, 0, 0},
                    {0, 0, 1, 9, 0, 0, 4, 6, 0},
                    {7, 0, 0, 1, 0, 0, 9, 0, 0},
                    {5, 0, 6, 0, 0, 0, 8, 0, 3},
                    {0, 0, 3, 0, 0, 8, 0, 0, 1},
                    {0, 1, 2, 0, 0, 9, 5, 0, 0},
                    {0, 0, 0, 7, 0, 0, 0, 0, 0},
                    {6, 8, 0, 0, 0, 0, 0, 0, 0}
            },
            {
                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 3, 6, 0, 0, 0, 0, 0},
                    {0, 7, 0, 0, 9, 0, 2, 0, 0},
                    {0, 5, 0, 0, 0, 7, 0, 0, 0},
                    {0, 0, 0, 0, 4, 5, 7, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 3, 0},
                    {0, 0, 1, 0, 0, 0, 0, 6, 8},
                    {0, 0, 8, 5, 0, 0, 0, 1, 0},
                    {0, 9, 0, 0, 0, 0, 4, 0, 0}
            }
            // Add more puzzles here
    };

    public SudokuSolverGUI() {
        setTitle("Sudoku Solver");
        setSize(600, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel gridPanel = new JPanel();
        gridPanel.setLayout(new GridLayout(3, 3));
        gridPanel.setBorder(new MatteBorder(2, 2, 2, 2, Color.BLACK));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                JPanel subGrid = new JPanel();
                subGrid.setLayout(new GridLayout(3, 3));
                subGrid.setBorder(new MatteBorder(1, 1, 1, 1, Color.GRAY));

                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        cells[i * 3 + row][j * 3 + col] = new JTextField();
                        cells[i * 3 + row][j * 3 + col].setHorizontalAlignment(JTextField.CENTER);
                        cells[i * 3 + row][j * 3 + col].setFont(new Font("Arial", Font.BOLD, 20));
                        subGrid.add(cells[i * 3 + row][j * 3 + col]);
                    }
                }

                gridPanel.add(subGrid);
            }
        }

        add(gridPanel, BorderLayout.CENTER);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(1, 4));

        JButton loadButton = new JButton("Load Puzzle");
        loadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                loadPuzzle();
            }
        });
        buttonPanel.add(loadButton);

        JButton solveButton = new JButton("Solve");
        solveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                stopSolving = false; // Reset the stop flag
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        solvePuzzle();
                    }
                }).start();
            }
        });
        buttonPanel.add(solveButton);

        JButton stopButton = new JButton("Stop");
        stopButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                stopSolving = true;
            }
        });
        buttonPanel.add(stopButton);

        JComboBox<String> speedSelector = new JComboBox<>(new String[]{"Slow", "Fast", "Superfast", "Flash"});
        speedSelector.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedSpeed = (String) speedSelector.getSelectedItem();
                switch (selectedSpeed) {
                    case "Slow":
                        delay = 500;
                        break;
                    case "Fast":
                        delay = 100;
                        break;
                    case "Superfast":
                        delay = 10;
                        break;
                    case "Flash":
                        delay = 0;
                        break;
                }
            }
        });
        buttonPanel.add(speedSelector);
        add(buttonPanel, BorderLayout.SOUTH);

        JButton changeThemeButton = new JButton("Change Theme");
        changeThemeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                changeTheme();
            }
        });
        buttonPanel.add(changeThemeButton);

        initializeSets();
        loadPuzzle(); // Load a random puzzle on start
    }

    private void initializeSets() {
        for (int i = 0; i < SIZE; i++) {
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            subgrids[i] = new HashSet<>();
        }
    }

    private void loadPuzzle() {
        clearBoard(); // Clear any previous data

        Random rand = new Random();
        int[][] puzzle = puzzles[rand.nextInt(puzzles.length)];

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                board[row][col] = puzzle[row][col];
                if (puzzle[row][col] != 0) {
                    cells[row][col].setText(String.valueOf(puzzle[row][col]));
                    cells[row][col].setEditable(false);
                    cells[row][col].setForeground(Color.BLACK); // Fixed puzzle cells in black
                    rows[row].add(puzzle[row][col]);
                    cols[col].add(puzzle[row][col]);
                    subgrids[(row / 3) * 3 + col / 3].add(puzzle[row][col]);
                } else {
                    cells[row][col].setText("");
                    cells[row][col].setEditable(true);
                    cells[row][col].setForeground(Color.RED); // New puzzle cells in red
                }
            }
        }
    }

    private void solvePuzzle() {
        if (solve()) {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JOptionPane.showMessageDialog(SudokuSolverGUI.this, "Sudoku Solved!", "Success", JOptionPane.INFORMATION_MESSAGE);
                }
            });
        } else {
            SwingUtilities.invokeLater(new Runnable() {
                @Override
                public void run() {
                    JOptionPane.showMessageDialog(SudokuSolverGUI.this, "Sudoku Not Solvable!", "Error", JOptionPane.ERROR_MESSAGE);
                }
            });
        }
    }

    private void changeTheme() {
        isLightTheme = !isLightTheme;
        Color[] theme = isLightTheme ? lightTheme : darkTheme;

        // Change the colors of the cells
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (cells[row][col].isEditable()) {
                    cells[row][col].setForeground(theme[4]); // New puzzle cells
                } else {
                    cells[row][col].setForeground(theme[0]); // Fixed puzzle cells
                }
                cells[row][col].setBackground(theme[1]); // Background color
            }
        }
    }

    private void clearBoard() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                board[row][col] = 0;
                cells[row][col].setText("");
                cells[row][col].setEditable(true);
                cells[row][col].setForeground(Color.RED);
                rows[row].clear();
                cols[col].clear();
                subgrids[(row / 3) * 3 + col / 3].clear();
            }
        }
    }

    private boolean isValid(int row, int col, int num) {
        return !rows[row].contains(num) && !cols[col].contains(num) && !subgrids[(row / 3) * 3 + col / 3].contains(num);
    }

    private boolean solve() {
        if (stopSolving) {
            return false;
        }

        int[] empty = findEmptyCell();
        if (empty == null) {
            return true;
        }
        int row = empty[0];
        int col = empty[1];

        for (int num = 1; num <= SIZE; num++) {
            if (isValid(row, col, num)) {
                board[row][col] = num;
                rows[row].add(num);
                cols[col].add(num);
                subgrids[(row / 3) * 3 + col / 3].add(num);
                updateGUI(row, col, num, isLightTheme); // Valid numbers in green
                delay(delay); // Delay to visualize steps
                if (solve()) {
                    return true;
                }
                board[row][col] = 0;
                rows[row].remove(num);
                cols[col].remove(num);
                subgrids[(row / 3) * 3 + col / 3].remove(num);
                updateGUI(row, col, 0, isLightTheme); // Reset cell color to red for new entries
                delay(delay); // Delay to visualize steps
            }
        }
        return false;
    }

    private int[] findEmptyCell() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    return new int[]{row, col};
                }
            }
        }
        return null;
    }

    private void updateGUI(int row, int col, int num, boolean isValid) {
        Color[] theme = isLightTheme ? lightTheme : darkTheme;
        Color color = isValid ? theme[3] : theme[4];
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                cells[row][col].setText(num == 0 ? "" : String.valueOf(num));
                cells[row][col].setForeground(color);
            }
        });
    }

    private void delay(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                SudokuSolverGUI solver = new SudokuSolverGUI();
                solver.setVisible(true);
            }
        });
    }
}
