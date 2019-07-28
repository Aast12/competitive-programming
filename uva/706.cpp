#include <iostream>

using namespace std;

int main() {
    bool setup[10][7] =  { {1, 1, 1, 1, 1, 1, 0}, //0
                        {0, 1, 1, 0, 0, 0, 0}, //1
                        {1, 1, 0, 1, 1, 0, 1}, //2
                        {1, 1, 1, 1, 0, 0, 1}, //3
                        {0, 1, 1, 0, 0, 1, 1}, //4
                        {1, 0, 1, 1, 0, 1, 1}, //5
                        {1, 0, 1, 1, 1, 1, 1}, //6
                        {1, 1, 1, 0, 0, 0, 0}, //7
                        {1, 1, 1, 1, 1, 1, 1}, //8
                        {1, 1, 1, 1, 0, 1, 1}  //9
    };
    
    int n = 1;
    string num = "a";

    while (n != 0 || num != "0") {
        cin >> n >> num;
	if (n == 0 && num == "0") break;
        char answer[n * 2 + 3][(n + 2) * num.size() + num.size() - 1];
        for (int i = 0; i < n * 2 + 3; i++) {
            for (int j = 0; j < (n + 2) * num.size() + (num.size() - 1); j++) {
                answer[i][j] = ' ';
            }
        }

        int col = 0;
        for (int i = 0; i < num.size(); i++) {
            int num_v = num[i] - 48;
            if (setup[num_v][0]) {
                for (int j = col + 1; j < col + n + 1; j++) {
                    answer[0][j] = '-';
                }
            }
            if (setup[num_v][1]) {
                for (int j = 0; j < n; j++) {
                    answer[j + 1][col + n + 1] = '|';
                } 
            }
            if (setup[num_v][2]) {
                for (int j = 0; j < n; j++) {
                    answer[j + n + 2][col + n + 1] = '|';
                } 
            }
            if (setup[num_v][3]) {
                for (int j = col + 1; j < col + n + 1; j++) {
                    answer[n * 2 + 2][j] = '-';
                }
            }
            if (setup[num_v][4]) {
                for (int j = 0; j < n; j++) {
                    answer[j + n + 2][col] = '|';
                } 
            }
            if (setup[num_v][5]) {
                for (int j = 0; j < n; j++) {
                    answer[j + 1][col] = '|';
                } 
            }
            if (setup[num_v][6]) {
                for (int j = col + 1; j < col + n + 1; j++) {
                    answer[n + 1][j] = '-';
                }
            }
            col += n + 2;


        }

        for (int i = 0; i < n * 2 + 3; i++) {
            int count = 0;
            for (int j = 0; j < (n + 2) * num.size() + (num.size() - 1); j++) {
                count++;
                cout << answer[i][j];
                if (count == n * num.size() + num.size() * 2) break;
                if (count % (n + 2) == 0) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


}

