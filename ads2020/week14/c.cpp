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

int n, m, f[N][N], a[N][N];

int main() {
    /* Problem:
        Floyd algorithm
    */

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] > 0 || i == j)
                f[i][j] = a[i][j];
            else
                f[i][j] = inf;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
    for (int i = 1; i <= n; i++, cout << "\n")
        for (int j = 1; j <= n; j++)
            cout << (f[i][j] < inf ? f[i][j] : -1) << ' ';


    return 0;
}



