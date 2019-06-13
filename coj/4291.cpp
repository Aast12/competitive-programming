//PENDING
#include <stdio.h>
#include <string>
using namespace std;

int main() {
    string t_type, n_type;
    char ti_type[15], ni_type[15];
    int t_quant, n_quant;
    while(scanf("%s %d %s %d", ti_type, &t_quant, ni_type, &n_quant)) {
        t_type = string(ti_type);
        n_type = string(ni_type);
        if (t_type == n_type && n_quant == t_quant) {
            printf("Draw\n");
        }
        else if (t_quant >= 2 * n_quant) {
            printf("Tobby\n");
        }
        else if (n_quant >= 2 * t_quant) {
            printf("Naebbirac\n");
        }
        else if ((t_type == "Cruisers" && n_type == "Battleships") ||
                (t_type == "Battleships" && n_type == "Destroyers") ||
                (t_type == "Destroyers" && n_type == "Cruisers")){
                printf("Tobby\n");
        } 
        else {
            printf("Naebbirac\n");
        }
    }
}