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

int n, m, was[N];
vector<int> g[N]; // array of vectors, vector g[v] is adjacency list of v

stack<int> st;

void dfs(int v, int pr=-1) {
    was[v] = 1;
    st.push(v);
    for (int u : g[v]) {
        if (u == pr) continue;
        if (was[u] == 0)
            dfs(u, v);
        else if (was[u] == 1) {
            // extract from u to v
            // vertices of stack
            vector<int> cyc;
            while (st.top() != u) {
                cyc.push_back(st.top());
                st.pop();
            }
            cyc.push_back(u);
            for (int i = 0; i < sz(cyc); i++)
                cout << cyc[i] << ' ';
            cout << "\n";
            exit(0);
        }
    }
    was[v] = 2;
    st.pop();
}

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
        if (!was[i])
            dfs(i);

    return 0;
}



