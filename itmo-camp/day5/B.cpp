#include <iostream>
#include <queue>
#include <vector>

#define INF 10000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> Coord;

vector<Coord> moves;

struct Trace {
    Coord from, to;
    int dist = -1;

    Trace() {}
    Trace(Coord f, Coord t, int d) : from(f), to(t), dist(d) {}
};

int main() {
    moves.push_back(make_pair(2, 1));
    moves.push_back(make_pair(2, -1));
    moves.push_back(make_pair(-2, 1));
    moves.push_back(make_pair(-2, -1));
    moves.push_back(make_pair(1, 2));
    moves.push_back(make_pair(1, -2));
    moves.push_back(make_pair(-1, 2));
    moves.push_back(make_pair(-1, -2));

    int n, x;
    Coord source, target;
    cin >> n;

    cin >> source.first >> source.second;
    cin >> target.first >> target.second;
    source.first--;
    source.second--;
    target.first--;
    target.second--;

    vector<vector<Trace> > dist(n, vector<Trace>(n));

    queue<Coord> bfs_q;
    dist[source.first][source.second] = Trace(source, source, 0);
    bfs_q.push(source);
    while (!bfs_q.empty()) {
        Coord curr = bfs_q.front();
        bfs_q.pop();

        if (curr.first == target.first && curr.second == target.second) break;

        for (Coord move : moves) {
            Coord newpos =
                make_pair(curr.first + move.first, curr.second + move.second);
            if (newpos.first < n && newpos.first >= 0 && newpos.second < n &&
                newpos.second >= 0) {
                int new_dist = dist[curr.first][curr.second].dist + 1;
                if (dist[newpos.first][newpos.second].dist == -1) {
                    dist[newpos.first][newpos.second] = Trace(
                        curr, newpos, dist[curr.first][curr.second].dist + 1);
                    bfs_q.push(newpos);
                }
            }
        }
    }

    Trace curr = dist[target.first][target.second];
    vector<Coord> trace;
    trace.push_back(target);

    while (
        !(curr.to.first == source.first && curr.to.second == source.second)) {
        Coord from = curr.from;
        trace.push_back(from);

        curr = dist[from.first][from.second];
    }

    cout << trace.size() << endl;
    for (int i = trace.size() - 1; i >= 0; i--) {
        Coord node = trace[i];
        cout << node.first + 1 << " " << node.second + 1 << endl;
    }
    cout << endl;
}
