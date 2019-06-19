#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int seq_num = 0, n_devices = 1, n_operations = 1, capacity = 1;
    cin >> n_devices >> n_operations >> capacity;
    while (!(n_devices == 0 && n_operations == 0 && capacity == 0)) {
        seq_num++;
        
        int devices[n_devices], index, power = 0, max_pow = 0;
        bool switches[n_devices], blown = false;
        
        for (int i = 0; i < n_devices; i++) {
            cin >> devices[i];
            switches[i] = 0;
        }

        for (int i = 0; i < n_operations; i++) {
            cin >> index;
            if (blown) continue;
            index--;
            switches[index] = !switches[index];
            if (switches[index]) {
                power += devices[index];
                if (power > capacity) blown = true;
                if (power > max_pow) max_pow = power;
            } else {
                power -= devices[index];
            }
        }

        cout << "Sequence " << seq_num  << "\nFuse was" << ((blown) ? " " : " not ") << "blown.\n";
        if (!blown) cout << "Maximal power consumption was " << max_pow << " amperes.\n";
        cout << endl;

        cin >> n_devices >> n_operations >> capacity;
    }

}