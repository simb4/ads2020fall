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

int vn = 1;
int to[26][N];
int cnt[N];
// vn = vertex number, intially root exist 
// to[c][v] is index of vertex that is transition from v by letter c
// cnt[v] = number of strings passed vertex v of trie

void add(string &s) {
    int n = s.length();
    int v = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i] - 'a';
        if (to[c][v] == 0) {
            to[c][v] = ++vn;
        }
        v = to[c][v]; // do transition
        cnt[v]++;
    }
}

int find(string &t) {
    int m = t.length();
    int v = 1;
    for (int i= 0; i < m; i++) {
        char c = t[i] - 'a';
        if (to[c][v] == 0)
            return 0;
        v = to[c][v];
    }
    return cnt[v];
}

int main() {

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        add(s);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        cout << find(t) << "\n";
    }

    return 0;
}



