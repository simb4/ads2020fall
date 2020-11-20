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
const int N = (int)105;

int n;
int a[N][N];
vector<int> g[N]; // array of vectors

int was[N];

void dfs(int v) {
    was[v] = 1;
    for (int u : g[v]) { // iterate over the neighbours
        if (!was[u]) {
            dfs(u);
        }
    }
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (a[i][j]) {
                g[i].push_back(j);
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j : g[i])
            if (i < j) {
                cout << i << ' ' << j << "\n";
            }
    }


    return 0;
}



