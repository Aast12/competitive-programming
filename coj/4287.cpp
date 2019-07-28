#include <cstdio>
#include <set>
#include <queue>
#include <utility>

typedef long long lli;

using namespace std;

struct Invader {
  lli x, y, hour;
  Invader(lli _x, lli _y, lli _hour){
      x = _x;
      y = _y;
      hour = _hour;
  }
};

int main() {
    lli N, M, T, first, second, counter = 0, end_c = 0;
    scanf("%lld %lld %lld", &N, &M, &T);
    queue<Invader> ends;
    queue<set<pair<lli, lli>>> end_queue;
    set<pair<lli, lli>> n_ends;
    set<pair<lli, lli>> iflowers; 
    
    for (lli i = 0; i < N; i++) {
        scanf("%lld %lld", &first, &second);
        ends.push(Invader(first, second, 0));
        n_ends.insert(make_pair(first, second));
        end_c++;
    }

    end_queue.push(n_ends);

    for (lli i = 0; i < M; i++) {
        scanf("%lld %lld", &first, &second);
        iflowers.insert(make_pair(first, second));
    }

    for (lli i = 0; i < T; i++) {
        set<pair<lli, lli>> ni_ends;
        while (!ends.empty()) {
            if (ends.front().hour > i) break;
            
            pair<lli, lli> current = make_pair(ends.front().x, ends.front().y);
            ni_ends.insert(current);
            ends.pop();
            
            pair<lli, lli> pr = make_pair(current.first + 1, current.second),
                    pl = make_pair(current.first - 1, current.second ),
                    pu = make_pair(current.first, current.second + 1),
                    pd = make_pair(current.first, current.second - 1);

            if (iflowers.find(pr) == iflowers.end() &&
                ni_ends.find(pr) == ni_ends.end() &&
                end_queue.front().find(pr) == end_queue.front().end()) {
                    counter++;
                    ends.push(Invader(pr.first, pr.second, i + 1));
            }

            if (iflowers.find(pl) == iflowers.end() &&
                ni_ends.find(pl) == ni_ends.end() &&
                end_queue.front().find(pl) == end_queue.front().end()) {
                    counter++;
                    ends.push(Invader(pl.first, pl.second, i + 1));
            }
            
            if (iflowers.find(pu) == iflowers.end() &&
                ni_ends.find(pu) == ni_ends.end() &&
                end_queue.front().find(pu) == end_queue.front().end()) {
                    counter++;
                    ends.push(Invader(pu.first, pu.second, i + 1));
            }

            if (iflowers.find(pd) == iflowers.end() &&
                ni_ends.find(pd) == ni_ends.end() &&
                end_queue.front().find(pd) == end_queue.front().end()) {
                    counter++;
                    ends.push(Invader(pd.first, pd.second, i + 1));
            }
        }
        end_queue.push(ni_ends);
        end_queue.pop();
    }
    printf("%lld\n", counter);
}