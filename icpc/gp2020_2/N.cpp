// PENDING

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;

ull binpow(ull a, ull b) {
    ull res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<ull> prime_factorization(ull n) {
    vector<ull> factorization;
    for (ull d = 2; d * d <= n; d++) {
        bool first = 1;
        while (n % d == 0) {
            if (first)
            {
                factorization.push_back(d);
                first = 0;
            }
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

struct MNode {
    ull value = 0;
    set<ull> n_nodes;

    void assign(ull n) {
        n_nodes.insert(n);
    }
};

struct NNode {
    ull value, index;
    set<ull> m_nodes;
    map<ull, ull> edges;
    NNode(ull v) : value(v) {}

    void assign(ull m, ull d)
    {
        m_nodes.insert(m);
        edges[m] = d;
    }
};

int sieve[1000];

int main() {
    ull M, N, k, m, n, d, v;
    cin >> M >> N >> k;
    vector<NNode> n_nodes;
    vector<MNode> m_nodes(M);

    for (ull i = 0; i < N; i++)
    {
        cin >> v;
        n_nodes.push_back(NNode(v));
    }

    for (ull i = 0; i < k; i++)
    {
        cin >> m >> n >> d;
        n_nodes[n - 1].assign(m, d);
        m_nodes[m - 1].assign(n);
    }

    for (int i = 0; i < N; i++)
    {
        auto first = n_nodes[i];

        if (first.value == 1)
            continue;

        vector<ull> factors = prime_factorization((ull)(first.value));

        ull curr = 0;
        for (auto &m : n_nodes[i].m_nodes)
        {
            ull p = factors[curr++];
            m_nodes[m - 1].value = p;

            for (auto &n : m_nodes[m - 1].n_nodes)
            {
                ull initial = n_nodes[n - 1].value;

                initial /= binpow(p, n_nodes[n - 1].edges[m - 1]);

                n_nodes[n - 1].value = initial;
                if (n - 1 != i)
                    n_nodes[n - 1].m_nodes.erase(m);
            }
        }
    }

    for (auto &m_node : m_nodes) {
        cout << m_node.value << " ";
    }

    cout << endl;
}