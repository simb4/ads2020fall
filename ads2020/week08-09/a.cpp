#include <iostream>
using namespace std;
const int N = (int)1e5 + 5;

void heapify_down(int *a, int n, int v) {
    int l = 2 * v;
    int r = 2 * v + 1;
    // taking the max among a[v],a[2v],a[2v+1]
    int cand = v;
    if (l <= n && a[l] > a[cand])
        cand = l;
    if (r <= n && a[r] > a[cand]) 
        cand = r;

    swap(a[v], a[cand]);
    if (cand != v)
        heapify_down(a, n, cand);
}

int get_max(int *a, int n) {
    return a[1];
}

void decr_max(int *a, int n) {
    a[1]--;
    heapify_down(a, n, 1);
}

void build_heap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--)
            heapify_down(a, n, i);
}



int a[N], n, x;

int main() {

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build_heap(a, n);

    long long ans = 0;
    for (int i = 1; i <= x; i++) {
        int mx = get_max(a, n);
        decr_max(a, n);
        ans += mx;
    }
    cout << ans << "\n";


        
    return 0;
}