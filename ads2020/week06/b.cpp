#include <iostream>
using namespace std;
const int N = (int)1e5 + 5;

int a[N], n;

void heapify_up(int v) {
    while (v > 1 && a[v / 2] < a[v]) {
        swap(a[v/2], a[v]);
        v = v / 2; // go to parent
    }
}

void heapify_down(int v) {
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
        heapify_down(cand);
}

void insert(int x) {
    n++;
    a[n] = x;
    heapify_up(n);
}

int get_max() {
    return a[1];
}

int remove_max() {
    int mx = a[1];
    swap(a[1], a[n]);
    n--;
    heapify_down(1);
    return mx;
}

void print(int v, int tab = 0) {
    if (v > n) return;
    for (int i = 0; i < tab; i++)
        cout << "  ";
    cout << a[v] << "\n";
    print(2 * v, tab + 1);
    print(2 * v + 1, tab + 1);
}

void build() {
    for (int i = n / 2; i >= 1; i--)
        heapify_down(i);
}

void heap_sort() {
    build(); // build from array
}

int main() {

    int q, x;
    char ch;
    cin >> q;
    for (int i = 0; i < q; i++) {
        // +, g, -
        cin >> ch;
        if (ch == '+') {
            cin >> x;
            insert(x);
        } else if (ch == 'g') {
            cout << get_max() << "\n";
        } else { // del x
            cout << remove_max() << "\n";
        }
        cout << "Tree:\n";
        print(1);
    }


}