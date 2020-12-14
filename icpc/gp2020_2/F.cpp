
#include <iostream>

using namespace std;

int main() {
    string game;
    int server = 0, winner = -1, score[] = {0, 0}, wins[] = {0, 0};
    cin >> game;

    for (auto &ch : game) {
        if (score[0] > score[1]) {
            if ((score[0] - 2 >= score[1] && score[0] >= 5) || score[0] == 10) {
                score[0] = score[1] = 0;
                server = 0;
                wins[0]++;
                if (wins[0] >= 2) winner = 0;
            }
        }
        else if (score[1] > score[0]) {
            if ((score[1] - 2 >= score[0] && score[1] >= 5) || score[1] == 10) {
                score[0] = score[1] = 0;
                server = 1;
                wins[1]++;
                if (wins[1] >= 2) winner = 1;
            }
        }
        
        if (ch == 'S') {
            score[server]++;
        }
        else if (ch == 'R') {
            score[(server + 1) % 2]++;
            server = (server + 1) % 2;
        }
        else if (ch == 'Q') {
            if (winner != -1) {
                cout << wins[0]
                    << ((winner == 0) ?  " (winner)" : "") 
                    << " - " << wins[1]
                    << ((winner == 1) ?  " (winner)" : "") << endl;
            } else {
                cout << wins[0]
                    << " (" << score[0] << ((server == 0) ? "*" : "") <<")" 
                    << " - " 
                    << wins[1]
                    << " (" << score[1] << ((server == 1) ? "*" : "") <<")"  << endl;
            }
        }

    }
}