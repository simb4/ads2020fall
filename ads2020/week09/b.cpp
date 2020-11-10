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
const int p = 31;
// mod = 2^32
int n;
int pw[N], h[N];


int main() {

    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int m = t.length();

    // calc the powers of hash base
    pw[0] = 1;
    pw[1] = p;
    for (int i = 2; i <= n; i++) {
        pw[i] = pw[i-1] * p; // casting to long long since 10^9 * p > 2^31
    }

    // calc prefix hashes of s
    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i-1] + (s[i-1] - 'a' + 1) * pw[i-1];
    }

    //  calc hash of T
    int T = 0;
    for (int i = 0; i < m; i++) {
        T = T + (t[i] - 'a' + 1) * pw[i];
    }

    // searching t in s
    int cnt = 0;
    for (int i = 0; i <= n - m; i++) {
        // compare string s[i,i+m) with t
        int hash_s = h[i + m] - h[i]; // hash(s[i,i+m)) * p^i
        int hash_t = T * pw[i];
        if (hash_s == hash_t) {
            cout << "+1 occuerence at index " << i << "\n";
            cnt++;
        }
    }


    return 0;
}



