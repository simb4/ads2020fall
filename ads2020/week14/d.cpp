#include <bits/stdc++.h>
#include <chrono>
#include <cassert>
#include <typeinfo>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int N = (int)1e3 + 5;
const int inf = (int)1e9;

int n, m, pr[N], used[N];
int min_e[N]; // min_e[v] = min edge from current spanning tree
vector< pair<int,int> > g[N];

int main() {
    /* Problem:
        Given weighted oriented graph.
        Find minimal spanning tree (MST).
        \
        MST, Prim algorithm in O(M logN)
    */

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }
        

    for (int i = 1; i <= n; i++)
        min_e[i] = inf;
    min_e[1] = 0;
    pr[1] = -1;


    // priority queue of (-min_e[v], v)
    // -min_e[v] because we want to store mininmums instaed of maximums
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(-min_e[1], 1));

    int mst = 0;
    while(!pq.empty()) {
        // pick up v with min min_e[v]
        auto [min_ev, v] = pq.top();
        min_ev = -min_ev; // min_ev > 0
        pq.pop();

        // skip if not up-to-date info about v
        if (min_ev > min_e[v]) {
            continue;
        }
        // cout << v << ' ' << min_e[v] << "\n";
        // vertex v now the member of the mst
        used[v] = 1;
        mst += min_e[v];
        // do realaxition:
        // iterate over neighbours of v
        for (auto [u, w] : g[v]) { 
            // consider edge (v, u) with weight w
            if (!used[u] && min_e[u] > w) {
                min_e[u] = w;
                pr[u] = v; // remeber edge (v, u)

                pq.push(make_pair(-min_e[u], u));
            }
        }
    }
    
    cout << mst << "\n";
    for (int i = 1; i <= n; i++) {
        if (min_e[i] != 0) {
            cout << i << ' ' << pr[i] << "\n";
        }
    }

    return 0;
}



