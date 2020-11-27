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
const int N = (int)105;

const int R = 0;
const int U = 1;
const int L = 2;
const int D = 3;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddd[300];


struct person {
    ll x, y;
    int d;
} p[N];

int n;
int dist(int a, int b) {
    return abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y);
}

typedef pair<int, pair<pii, pii> > event;
vector<event> pr;

ll meet(int a, int b) {
    if (p[a].y > p[b].y) swap(a, b);
    if (p[a].y == p[b].y) {
        if (p[a].x > p[b].x) swap(a, b);
        // a < b
        if (p[a].d == R && p[b].d == L)
            return (p[a].x + p[b].x) / 2;
        return -1;
    }
    if (p[a].d != U || p[b].d != D)
        return -1;
    ll deltax = p[b].x - p[a].x;
    ll deltay = p[b].y - p[a].y;
    if (abs(deltax) != abs(deltay))
        return -1;

    if (p[a].d == U) {
        if ((deltax > 0 && p[b].d == L) || (deltax < 0 && p[b].d == R))
            return abs(deltax);
        return -1;
    } else { // p[b].d 
        if (deltax > 0 && p[b].d)
    }

}

int main() {
    ddd['e'] = 0;
    ddd['n'] = 1;
    ddd['w'] = 2;
    ddd['s'] = 3;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%d %d %c", &p[i].x, &p[i].y, &c);
        p[i].x *= 2;
        p[i].y *= 2;
        p[i].d = ddd[c];
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int t = meet(i, j);
            if (t != -1) {
                pii meetp = mp(p[i].x + dx[p[i].d] * t, p[i].y + dy[p[i].d] * t);
                pr.pb(event(
                    mp(t,
                        mp(
                            meetp,
                            mp(i, j)
                        )
                    )));
            }
        }


    return 0;
}



