/**
 * nQueen
 * print n queens in nxn board
 */
public class nQueen {
    public static void main(String[] args) {
        int n = 5;
        char board[][] = new char[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 'X';
            }
        }
        queen(board, 0);
    }

    public static void queen(char board[][], int row) {
        if (row == board.length) {
            printBoard(board);
            return;
        }

        for (int j = 0; j < board.length; j++) {
            board[row][j] = 'Q';
            queen(board, row + 1);
            board[row][j] = 'X';
        }
    }

    public static void printBoard(char board[][]) {
        System.out.println("-- Chess Board --");
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

}