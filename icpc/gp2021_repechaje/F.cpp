#include <iostream>

using namespace std;

int main() {
    while (true) {
        int rows, cols, entrance;
        cin >> rows >> cols >> entrance;
        cin.ignore();
        if (rows == 0 && cols == 0 && entrance == 0) {
            return 0;
        }
        char map[rows][cols];
        int visitedIndex[rows][cols];
        int prevSteps[rows][cols];
        for (int y = 0; y < rows; y++) {
            string line;
            cin >> line;
            cin.ignore();
            for (int x = 0; x < cols; x++) {
                map[y][x] = line[x];
                visitedIndex[y][x] = 0;
                prevSteps[y][x] = 0;
            }
        }
        int currX = entrance - 1;
        int currY = 0;
        int pathLength = 0;
        int loopLength = 0;
        while (true) {
            if (currX < 0 || currX >= cols || currY < 0 || currY >= rows) {
                break;
            }
            if (visitedIndex[currY][currX] != 0) {
                loopLength = pathLength + 1 - visitedIndex[currY][currX];
                break;
            } else {
                prevSteps[currY][currX] = pathLength;
                pathLength++;
                visitedIndex[currY][currX] = pathLength;
            }

            char current = map[currY][currX];

            if (current == 'N') {
                currY = currY - 1;
            } else if (current == 'S') {
                currY = currY + 1;
            } else if (current == 'W') {
                currX = currX - 1;
            } else if (current == 'E') {
                currX = currX + 1;
            }
        }
        if (loopLength == 0) {
            cout << pathLength << " step(s) to exit" << endl;
        } else {
            cout << prevSteps[currY][currX] << " step(s) before a loop of "
                 << loopLength << " step(s)" << endl;
        }
    }
}