#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
const int N = (int)1e5 + 5;

int n, a[N];

int get(int l, int r) {
    if (l > r) return 0;
    int il = lower_bound(a, a + n, l) - a;
    // mostleft index i: l <= a[i]
    int ir = upper_bound(a, a + n, r) - a;
    // mostleft index i: r > a[i]
    return ir - il;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        int lc = max(l1, l2);
        int rc = min(r1, r2);
        int ans = get(l1, r1) + get(l2, r2) - get(lc, rc);
        printf("%d\n", ans);
    }


    return 0;
}



