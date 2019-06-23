#include <iostream>

using namespace std;

int main() {
    int T, N, score = 0;
    cin >> T;
    
    string chef, answers;
    bool previous_wrong = false;

    while (T--) {
        previous_wrong = false;
        score = 0;
        cin >> N  >> answers >> chef;
            
        for (int i = 0; i < N; ++i) {
            if (chef[i] == 'N' || previous_wrong) {
               previous_wrong = false; 
            } else {
                if (chef[i] == answers[i]) {
                    score++;
                } else {
                    previous_wrong = true;                    
                }
            }
        }

        cout << score << endl;

    }
}
