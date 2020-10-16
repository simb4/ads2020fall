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


int remove_max(int *a, int &n) {
    int mx = a[1];
    swap(a[1], a[n]);
    n--;
    heapify_down(a, n, 1);
    return mx;
}

void build_heap(int *a, int n) {
    for (int i = n / 2; i >= 1; i--)
            heapify_down(a, n, i);
    }

void heap_sort(int *a, int n) {
    build_heap(a, n); // build heap from arbitrary array

    while(n > 0)
        remove_max(a, n);
}


int b[N], m;

int main() {

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    heap_sort(b, m);

    for (int i = 1; i <= m; i++)
        cout << b[i] << ' ';
    cout << "\n";

        
    return 0;
}