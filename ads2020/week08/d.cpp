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


int n, a[N], tmp[N];


int main() {


    scanf("%d", &n);
    int mx1 = -1,
        mx2 = -1,
        mx3 = -1;
    for (int i = 1; i <= n; i++) { // O(n)
        int x;
        scanf("%d", &x);

        if (mx1 <= x) { // O(1)
            mx3 = mx2;
            mx2 = mx1;
            mx1 = x;
        } else if (mx2 <= x) {// O(1)
            mx3 = mx2;
            mx2 = x;
        } else if (mx3 < x) {// O(1)
            mx3 = x;
        }

        long long prod = -1;
        if (i > 2) {
            prod = mx1 * 1ll * mx2 * mx3; // 10^18
        }
        printf("%lld\n", prod);
    }   
    

    return 0;
}



