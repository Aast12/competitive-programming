#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int students;
    while (cin >> students) {
        if (students == 0) break;
        
        long costs[students], sum = 0, dollars, pennies;
        for (int i = 0; i < students; i++) {
            pennies = 0;
            scanf("%ld.%ld", &dollars, &pennies);
            costs[i] = dollars * 100 + pennies;
            sum += costs[i];
        }

        long average = sum / students, max_c = 0, curr = 0, remain = sum % students, min_c = 0;
        for (int i = 0; i < students; i++) {
            if (costs[i] > average) {
                curr += costs[i] - average;
                if (remain > 0) {
                    curr--;
                    remain--;
                }
            } 
            if (costs[i] < average) min_c += average - costs[i];
            if (curr > max_c) max_c = curr;
        }   

        long total = max_c + remain - (curr - min_c);
        
        printf("$%ld.%02ld\n", total / 100, total % 100);

    }

}