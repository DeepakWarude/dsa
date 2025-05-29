#include <iostream>
#include <iomanip>
using namespace std;

class KnightTour {
private:
    int n;
    int board[8][8];
    int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

public:
    KnightTour() : n(8) {
        // Initialize the board with -1 to mark unvisited cells
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = -1;
    }

    bool isSafe(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
    }

    // Count the number of valid moves for a given position
    int countOnwardMoves(int x, int y) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];
            if (isSafe(nextX, nextY))
                count++;
        }
        return count;
    }

    // Warnsdorff's rule to select the next move
    bool nextMove(int &x, int &y) {
        int minDegreeIndex = -1, minDegree = 9; // 9 is larger than any possible moves
        int nextX, nextY;

        for (int i = 0; i < 8; i++) {
            int curX = x + moveX[i];
            int curY = y + moveY[i];
            int degree = countOnwardMoves(curX, curY);

            if (isSafe(curX, curY) && degree < minDegree) {
                minDegreeIndex = i;
                minDegree = degree;
            }
        }

        // If no valid move found, return false
        if (minDegreeIndex == -1)
            return false;

        // Update knight's position
        x += moveX[minDegreeIndex];
        y += moveY[minDegreeIndex];
        return true;
    }

    // Solve the Knight's Tour using Warnsdorff's heuristic
    bool solveTour(int startX, int startY) {
        int x = startX, y = startY;
        board[x][y] = 1; // Starting position with first move count

        // Move to next positions following Warnsdorff's rule
        for (int move = 2; move <= n * n; move++) {
            if (!nextMove(x, y))
                return false;
            board[x][y] = move;
        }

        return true;
    }

    // Display the board with the solution
    void displayBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Adjust spacing for each cell to align columns
                if (board[i][j] == -1)
                    cout << "  - "; // Unvisited cell placeholder
                else
                    cout << " " << (board[i][j] < 10 ? " " : "") << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    KnightTour knightTour;

    int startX, startY;
    cout << "Enter starting X (0-7): ";
    cin >> startX;
    cout << "Enter starting Y (0-7): ";
    cin >> startY;

    if (knightTour.solveTour(startX, startY)) {
        cout << "Knight's tour completed successfully!" << endl;
        knightTour.displayBoard();
    } else {
        cout << "No solution exists for the given starting position." << endl;
    }

    return 0;
}
