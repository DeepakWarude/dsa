#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class DrunkenCockroach {
private:
    int n, m;
    int totalMoves;
    int visitedTiles;
    int startX, startY;
    bool visited[25][25]; // To keep track of visited tiles
    int posX, posY;

public:
    DrunkenCockroach(int rows, int cols, int start_x, int start_y)
        : n(rows), m(cols), startX(start_x), startY(start_y), totalMoves(0), visitedTiles(0) {
        
        // Initialize visited grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }
        
        // Set starting position
        posX = startX;
        posY = startY;
        visited[posX][posY] = true;
        visitedTiles = 1;
        srand(time(0));
    }

    // Check if all tiles have been visited
    bool allTilesVisited() {
        return visitedTiles == n * m;
    }

    // Display the current state of the grid
    void displayGrid() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == posX && j == posY)
                    cout << " C "; // Current position of the cockroach
                else if (visited[i][j])
                    cout << " . "; // Visited tile
                else
                    cout << " - "; // Unvisited tile
            }
            cout << endl;
        }
        cout << "Moves so far: " << totalMoves << endl;
    }

    // Perform a random move
    void randomMove() {
        int moveX[8] = {1, 1, 1, 0, -1, -1, -1, 0};  // Movement in the x direction
        int moveY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};  // Movement in the y direction

        while (!allTilesVisited()) {
            int direction = rand() % 8;
            int newX = posX + moveX[direction];
            int newY = posY + moveY[direction];

            // Check if new position is within bounds
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                posX = newX;
                posY = newY;
                totalMoves++;

                // Mark tile as visited if it was unvisited
                if (!visited[posX][posY]) {
                    visited[posX][posY] = true;
                    visitedTiles++;
                }

                displayGrid();
            }
        }
    }

    int getTotalMoves() const {
        return totalMoves;
    }
};

int main() {
    int rows, cols, startX, startY;
    cout << "Enter the room dimensions (rows and columns): ";
    cin >> rows >> cols;
    cout << "Enter the starting position of the cockroach (X and Y): ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= rows || startY < 0 || startY >= cols) {
        cout << "Invalid starting position!" << endl;
        return 1;
    }

    DrunkenCockroach cockroach(rows, cols, startX, startY);
    cockroach.randomMove();

    cout << "The cockroach visited all tiles in " << cockroach.getTotalMoves() << " moves." << endl;

    return 0;
}
