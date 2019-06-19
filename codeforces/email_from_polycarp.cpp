#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string word, e_word;
        bool answer = true;
        cin >> word >> e_word;
        
        if (e_word.size() < word.size()) {
            cout << "NO\n";
            continue;
        }

        int char_count = 0, e_char_count = 0, curr_ei = 0, i, j, total_c = 0;
        char curr_c, curr_ec;
        for (i = 0; i < word.size(); i++) {
            curr_c = word[i];
            
            j = i;
            while (word[j++] == curr_c) char_count++;
            i += char_count - 1;
            
            curr_ec = e_word[curr_ei];
            if (curr_ec != curr_c) {
                answer = false;
                break;
            }

            j = curr_ei;
            while (e_word[j++] == curr_c) e_char_count++;
            curr_ei += e_char_count;
            total_c += e_char_count;
            if (e_char_count < char_count) {
                answer = false;
                break;
            }

            char_count = 0;
            e_char_count = 0;
        }

        if (total_c < e_word.size()) answer = false;

        cout << (answer ? "YES" : "NO") << endl;
    }
}