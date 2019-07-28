#include <iostream>
#include <queue>

using namespace std;

int main() {
    char command;
    int m, n;
    char grid[250][250];
    bool finished = false;
    while (cin >> command) {
        if (command == 'I'){
            cin >> m >> n;
            for (int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    grid[i][j] = 'O';
        }
        else if (command == 'C') {
            for (int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    grid[i][j] = 'O';
        }
        else if (command == 'L') {
            int x, y;
            char c;
            cin >> x >> y >> c;
            grid[y - 1][x - 1] = c;
        }
        else if (command == 'V') {
            int x, y1, y2;
            char c;
            cin >> x >> y1 >> y2 >> c;
            if (y1 > y2) swap(y1, y2);
            for (int i = y1 - 1; i <= y2 - 1; i++)
                grid[i][x - 1] = c;
        }
        else if (command == 'H') {
            int x1, x2, y;
            char c;
            cin >> x1 >> x2 >> y >> c;
            if (x1 > x2) swap(x1, x2);
            for (int i = x1 - 1; i <= x2 - 1; i++)
                grid[y - 1][i] = c;
        }
        else if (command == 'K') {
            int x1, x2, y1, y2;
            char c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            for (int i = y1 - 1; i <= y2 - 1; i++)
                for (int j = x1 - 1; j <= x2 - 1; j++)
                    grid[i][j] = c;
        }
        else if (command == 'F') {
            int x, y;
            char ch, current;
            cin >> x >> y >> ch;
            current = grid[y - 1][x - 1];

            queue<pair<int, int>> fill_cells;
            if (current != ch) fill_cells.push({y -1 , x - 1});
            while (!fill_cells.empty()) {
                int r = fill_cells.front().first, c = fill_cells.front().second;
                grid[r][c] = ch;
                if (r + 1 < n && grid[r + 1][c] == current) {
                    grid[r + 1][c] = ch;
                    fill_cells.push({r + 1, c});
                }
                if (c + 1 < m && grid[r][c + 1] == current) {
                    grid[r][c + 1] = ch;
                    fill_cells.push({r, c + 1});
                }
                if (r - 1 >= 0 && grid[r - 1][c] == current) {
                    grid[r - 1][c] = ch;
                    fill_cells.push({r - 1, c});
                }
                if (c - 1 >= 0 && grid[r][c - 1] == current) {
                    grid[r][c - 1] = ch;
                    fill_cells.push({r, c - 1});
                }
                fill_cells.pop();
            }
        }
        else if (command == 'S') {
            string name;
            cin >> name;
            cout << name << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
        }
        else if (command == 'X') {
            break;
        }
    }
}

