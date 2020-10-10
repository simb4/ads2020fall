#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
using namespace std;
const int N = (int)3e5 + 5;

int n;
int p[N], k;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            p[k++] = i;
            cout << i << "\n";
        }
    }
    int cnt = 0;
    // type x = p * q
    // if I know p[i], i want find
    // lagest j : p[i] * p[j] <= n
    //  p[j] <= n / p[i]

    /*
        0 1 2 3 4
        2,3,5,7,8
        n = 10
        p[i] = 3
        j = 2, p[j] = 5, p[i]*p[j] = 15 > 10
    */
    for (int i = 0; i < k; i++) {
        int j = upper_bound(p, p + k, n / p[i]) - p;

        cnt += min(i, j);
    }
    // type x = p^3
    for (int i = 0; i < k; i++) {
        if (p[i] * p[i] * p[i] <= n)
            cnt++;
    }

    cout << cnt << "\n";


    return 0;
}



