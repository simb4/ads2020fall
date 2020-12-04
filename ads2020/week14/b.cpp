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

int n, m;
int d[N]; // array of shortest distances
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
    }
        

    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[1] = 0;

    // priority queue of (-d[v], v)
    // -d[v] because we want to store mininmums instaed of maximums
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(-d[1], 1));
    while(!pq.empty()) {

        // pick up v with min d[v]
        pair<int,int> pp = pq.top();
        int dv = -pp.first; // dv > 0
        int v = pp.second;
        pq.pop();

        if (dv > d[v]) continue;

        // realaxition
        // iterate over neighbours of v
        for (auto [u, w] : g[v]) { 
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                // remove old d[u] from pq and new one
                pq.push(make_pair(-d[u], u));
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
    cout << "\n";


    return 0;
}



