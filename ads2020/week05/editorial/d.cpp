#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
const int N = (int)3e5 + 5;

int n, a[N];

int main() {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        a[i] = max(x2, y2);
    }
    sort(a, a + n);;
    printf("%d\n", a[k-1]);


    return 0;
}



