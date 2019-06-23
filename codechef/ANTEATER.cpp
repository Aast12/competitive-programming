#include <iostream>
#include <vector>

using namespace std;

struct Entity {
    bool is_ant, del;
    int row, col;
    char direction;
    Entity(int r, int c, char d) : row(r), col(c), direction(d), is_ant(1), del(0) {}
};

int main() {
    int T, rows, cols;  
    char aux;
    cin >> T;

    while (T--) {
        cin >> rows >> cols;
        bool anteaters[rows][cols];
        vector<Entity> entities;
        int pairs = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> aux;
                anteaters[i][j] = 0;
                if (aux == '#') {
                    anteaters[i][j] = 1;
                } else if (aux != '-') {
                    entities.push_back(Entity(i, j, aux));
                }
            }
        }

        while (entities.size() > 0) {
           	for (int i = 0; i < entities.size(); i++) {
        	   switch (entities[i].direction) {
        	       case 'U':
        	           entities[i].row -= 1;
        	           break;
        	       case 'R':
        	           entities[i].col += 1;
        	           break;
        	       case 'D':
        	           entities[i].row += 1;
        	           break;
        	       case 'L':
        	           entities[i].col -= 1;
        	           break;
        	   }
        	   int c = entities[i].col, r = entities[i].row;
        	   if (anteaters[r][c] || r < 0 || c < 0 || r >= rows || c >= cols) {
        	       entities.erase(entities.begin() + i);
        	       i--;
        	   }
            }

        	for (int i = 0; i < entities.size(); ++i) {
        	   for (int j = 0; j < entities.size(); ++j) {
        	         if (i == j) continue;
        	       
        	       if (entities[i].row == entities[j].row && entities[i].col == entities[j].col) {
        	           pairs++;
        	       }      
        	   }
            }
        }

        cout << pairs / 2 << endl;
    }
}
