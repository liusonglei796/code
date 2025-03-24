#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string TARGET_STRING = "yizhong";
const int DX[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int DY[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool checkString(const vector<string>& grid, int x, int y, int direction, int gridSize) {
    for (int i = 0; i < TARGET_STRING.length(); ++i) {
        int nextX = x + i * DX[direction];
        int nextY = y + i * DY[direction];
        if (nextX < 0 || nextX >= gridSize || nextY < 0 || nextY >= gridSize || grid[nextX][nextY] != TARGET_STRING[i]) {
            return false;
        }
    }
    return true;
}

void markString(vector<vector<bool>>& visited, int x, int y, int direction) {
    for (int i = 0; i < TARGET_STRING.length(); ++i) {
        int nextX = x + i * DX[direction];
        int nextY = y + i * DY[direction];
        visited[nextX][nextY] = true;
    }
}

int main() {
    int gridSize;
    cin >> gridSize;

    vector<string> grid(gridSize);
    vector<vector<bool>> visited(gridSize, vector<bool>(gridSize, false));

    for (int i = 0; i < gridSize; ++i) {
        cin >> grid[i];
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (grid[i][j] == 'y') {
                for (int direction = 0; direction < 8; ++direction) {
                    if (checkString(grid, i, j, direction, gridSize)) {
                        markString(visited, i, j, direction);
                    }
                }
            }
        }
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (visited[i][j]) {
                cout << grid[i][j];
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}