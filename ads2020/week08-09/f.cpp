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

void merge(int *a, int n, int *b, int m, int *c) {
    int l = 1, r = 1, k = 0;
    while (l <= n || r <= m) {
        if (l <= n && r <= m) {
            if (a[l] <= b[r])
                tmp[++k] = a[l], l++;
            else
                tmp[++k] = b[r], r++;
        } else if (l > n) {
            tmp[++k] = b[r], r++;
        } else { // r > m
            tmp[++k] = a[l], l++;
        }
    }
    for (int i = 1; i <= k; i++)
        c[i] = tmp[i];
}

void merge_sort(int *a, int n) {
    // a[1],a[2],...,a[n]
    if (n == 1) return;
    int m = (n + 1) / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, m, a + m, n - m, a);
}

void out(int l, int r, int *a) {
    // [l    ] mid [    r]
    int mid = (l + r) / 2;
    printf("%d ", a[mid]);
    if (l != r) {
        out(l, mid - 1, a);
        out(mid + 1, r, a);
    }
}

int main() {


    scanf("%d", &n);
    int N = (1 << n) - 1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", a + i);
    }
    merge_sort(a, N);

    out(1, N, a);
    puts("");



    return 0;
}



