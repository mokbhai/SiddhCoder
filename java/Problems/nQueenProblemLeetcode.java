/**
 * nQueen
 * print n queens in nxn board
 */
public class nQueenProblemLeetcode {
    public static void main(String[] args) {
        // int n = 4;
        fileTaker ft = new fileTaker();
        int n = Integer.parseInt(ft.input());
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
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                queen(board, row + 1);
                board[row][j] = 'X';
            }
        }
    }

    public static boolean isSafe(char board[][], int row, int col) {
        // vertically up
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // digonally left up
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // digonally right up
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    public static void printBoard(char board[][]) {
        // System.out.println("-- Chess Board --");
        filePrinter fp = new filePrinter();
        fp.print("-- Chess Board --");
        String s;
        for (int i = 0; i < board.length; i++) {
            s = "";
            for (int j = 0; j < board.length; j++) {
                // System.out.print(board[i][j] + " ");
                s += board[i][j] + " ";
            }
            // System.out.println();
            fp.print(s);
        }
    }

}