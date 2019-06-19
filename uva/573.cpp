#include <iostream>

using namespace std;

int main() {
    int height = 1, slide_dist, fatigue, day_count, climb_dist;
    double n_climb_dist, curr_height;
    while (height != 0) {
        cin >> height >> climb_dist >> slide_dist >> fatigue;
        if (!height) break;
        bool success = true;
        day_count = 0, curr_height = 0.0, n_climb_dist = climb_dist;
        while (success) {
            day_count++;
            
            curr_height += n_climb_dist;
            if (curr_height > (double) height) break;
            
            curr_height -= slide_dist;
            
            if (curr_height < (double) 0) success = false;
            n_climb_dist = max((double) 0, n_climb_dist - ((double) fatigue / 100) * climb_dist);
        }
        cout << ((success) ? "success" : "failure") << " on day " << day_count << endl;
    }

}