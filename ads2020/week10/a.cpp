#include <iostream>
#include <stdio.h>
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
// const int mod = (int)1e9 + 7;

int n;
int pw[N], h[N]; // unisigned int


int main() {
    print("ababcab");

    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int m = t.length();

    pw[0] = 1;
    pw[1] = p;
    for (int i = 2; i <= n; i++)
        pw[i] = pw[i-1] * p;

    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = h[i-1] + (s[i-1] - 'a' + 1) * pw[i-1];

    int T = 0;
    for (int i = 0; i < m; i++) {
        T += (t[i] - 'a' + 1) * pw[i];
    }


    for (int i = 0; i <= n - m; i++) {
        int hash = h[i + m] - h[i]; // hash[l,r) * p^i
        if (hash == T * pw[i]) {
            cout << "occurence at position " << i << "\n";
        }
    }


    return 0;
}



