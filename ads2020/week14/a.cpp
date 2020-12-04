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

int n, m, a[N][N];
int d[N], used[N]; // array of shortest distances

int main() {
    /* Problem:
        Given weighted oriented graph.
        Find the shortest path between vertex 1 and vertex n
        DIJKSTRA algorithm in O(n^2)
    */

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[1] = 0;

    for (int s = 1; s <= n; s++) {
        // pick up the unporcessed vertex v
        // with smallest d[v] value
        int v = -1;
        for (int i = 1; i <= n; i++)
            if (!used[i] && (v == -1 || d[i] < d[v]))
                v = i;

        if (v == -1) break;
        used[v] = 1;

        for (int u = 1; u <= n; u++)
            if (a[v][u] > 0)
                d[u] = min(d[u], d[v] + a[v][u]);
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
    cout << "\n";


    return 0;
}



