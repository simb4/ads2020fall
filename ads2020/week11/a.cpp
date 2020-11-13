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

int n, p[N];

void prefix_f(string s, int *p) {
    int n = s.length();
    if (n == 0) return;
    p[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[j] != s[i])
            j = p[j-1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
}

int main() {

    string s;
    cin >> s;
    prefix_f(s, p);

    for (int i = 0; i < (int)s.length(); i++)
        cout << p[i] << ' ';
    cout << "\n";


    return 0;
}



