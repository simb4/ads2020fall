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
const int N = (int)1e5 + 5;
const int inf = (int)1e9;

int n, m;
vector<int> g[N]; // array of vectors, vector g[v] is adjacency list of v

int d[N]; // array of shortest distances

int main() {
    /* Problem:
        Given graph.
        Find the shortest path between vertex 1 and vertex n
    */

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[1] = 0;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        // relaxation
        for (int u : g[v]) {
            if (d[u] == inf) {
                // go to v + use edge (v, u)
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    cout << d[n] << "\n";


    return 0;
}



