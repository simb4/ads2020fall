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
    int l = 1; // pointer to left part
    int r = 1; // pointer to right part
    int k = 0; // pointer to common array

    while (l <= n || r <= m) { // can be replaced with for loop (1..n+m)
        if (l <= n && r <= m) {
            // comparing 2 candidates
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
    // split into 2 parts
    int m = (n + 1) / 2; // n/2 - floor of (n/2), (n+1)/2 - ceil of (n/2)
    
    // sort left part
    merge_sort(a, m);

    // sort right part
    merge_sort(a + m, n - m);
    
    // merge 2 parts
    merge(a, m, a + m, n - m, a);
}

int main() {


    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    merge_sort(a, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}



