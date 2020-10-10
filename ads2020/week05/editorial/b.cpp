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

bool reversed = false;
deque<int> d;

void add(int x) {
    if (reversed) {
        d.push_front(x);
    } else {
        d.push_back(x);
    }
}

void rev() {
   reversed = !reversed; // T -> F, F -> T
}

void out() {
    if (!reversed) {
        while(!d.empty()) {
            cout << d.front() << " ";
            d.pop_front();
        }
    } else {
        while (!d.empty()) {
            cout << d.back() << " ";
            d.pop_back();
        }
    }
    cout << "\n";
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int ty, x;
        scanf("%d", &ty);
        if (ty == 1) {
            scanf("%d", &x);
            add(x);
        } else {
            rev();
        }
    }

    out();

    return 0;
}



