#include <iostream>
#include <vector>

using namespace std;

struct Record {
    int time, team;

    Record(int time, int team) : time(time), team(team) {}
};

int main() {
    int n, t, m, time, team;
    char problem;
    string status;
    cin >> n >> t >> m;

    vector<vector<bool> > team_solves(t, vector<bool>(n, 0));
    vector<Record> last_blood(n, Record(-1, 0));
    for (int i = 0; i < m; i++) {
        cin >> time >> team >> problem >> status;
        team--;

        if (status == "Yes") {
            int pid = problem - 'A';
            if (!team_solves[team][pid]) {
                last_blood[pid] = Record(time, team);
                team_solves[team][pid] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        Record lb = last_blood[i];

        if (lb.time == -1)
            cout << char(i + 'A') << " - -" << endl;
        else
            cout << char(i + 'A') << " " << lb.time << " " << lb.team + 1
                 << endl;
    }
}