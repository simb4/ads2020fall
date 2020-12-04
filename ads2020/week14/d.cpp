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

int n, m, pr[N];
int mt[N]; // mt[v] = min edge from current spanning tree
vector< pair<int,int> > g[N];

int main() {
    /* Problem:
        Given weighted oriented graph.
        Find the shortest path between vertex 1 and vertex n
        \
        DIJKSTRA algorithm in O(M logN)
    */

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }
        

    for (int i = 1; i <= n; i++)
        mt[i] = inf;
    mt[1] = 0;
    pr[1] = -1;


    // priority queue of (-d[v], v)
    // -d[v] because we want to store mininmums instaed of maximums
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(-mt[1], 1));
    while(!pq.empty()) {

        // pick up v with min d[v]
        pair<int,int> pp = pq.top();
        int mtv = -pp.first; // dv > 0
        int v = pp.second;
        pq.pop();

        if (mtv > mt[v]) continue;

        // realaxition
        // iterate over neighbours of v
        for (auto [u, w] : g[v]) { 
            // consider edge (v, u) with weight w
            if (mt[u] > w) {
                mt[u] = w;
                pr[u] = v;
                pq.push(make_pair(-mt[u], u));
            }
        }
    }
    int mst = 0;
    vector<pair<int,int> > E;
    for (int i = 1; i <= n; i++) {
        mst += mt[i];
        if (mt[i] != 0) {
            E.push_back(mp(i, pr[i]));
        }
    }
    cout << mst << "\n";
    for (auto [u, v] : E) {
        cout << u << ' ' << v << "\n";
    }

    return 0;
}



