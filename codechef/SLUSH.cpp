#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Customer {
    int fav, max_p, min_p;
    Customer(int d, int f, int b) : fav(d), max_p(f), min_p(b) {} 
};

int main(int argc, char *argv[]) {
    int T; 
    cin >> T;
    while (T--) {
        int cust_n, flav_n, d, f, b, sum = 0;
        stack<int> answer;
        cin >> cust_n >> flav_n;
        vector<Customer> customers;
        int mins[cust_n];
        int flav_c[flav_n];    
        for (int i = 0; i < flav_n; i++) {
            cin >> flav_c[i];
        }
        
        for (int i = 0; i < cust_n; i++) {
            cin >> d >> f >> b;
            customers.push_back(Customer(d - 1, f, b));
        }
        int min_i = 0, min_v = 0;
        for (int i = cust_n - 1; i >= 0; i--) {
            if (i == cust_n - 1 || customers[i].max_p < min_v) {
                min_i = i;
                min_v = customers[i].max_p;
            }
            mins[i] = min_i;
        }

        for (int i = 0; i < cust_n; i++) {
            if (flav_c[customers[i].fav]) {
                sum += customers[i].max_p;
                flav_c[customers[i].fav]--;
                answer.push(customers[i].fav + 1);
            } else {
                int j = i;
                while (true) {
                    if (mins[j]) {
                        sum += customers[i].max_p;
                        flav_c[customers[mins[j]].fav]--;
                        answer.push(customers[mins[j]].fav + 1);
                    }
                    j++;
                    if (j >= flav_n) {
                        int maxi = 0, maxi_v = 0;
                        for (int k = 0; k < flav_n; k++) {
                            if (flav_c[k] > maxi_v) {
                                maxi = k;
                                maxi_v = flav_c[k];
                            }
                        }
                        sum += customers[i].min_p;
                        flav_c[maxi]--;
                        answer.push(maxi + 1);
                        break;
                    }
                }
            }
        }

        cout << sum << endl;
        while(!answer.empty()) {
            cout << answer.top() << " ";
            answer.pop();
        }
        cout << endl;


    }
    return 0;
}
