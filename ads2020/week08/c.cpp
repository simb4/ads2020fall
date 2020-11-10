#include <bits/stdc++.h>


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

int n;
char s[N];

int cnt[26];

int main() {


    scanf("%d", &n);
    scanf("%s", s);

    string ord = "aeioubcdfghjklmnpqrstvwxyz";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == ord[i])
                cout << s[j];
        }
    }
    cout << "\n";

    for (int i = 0; i < n; i++) // O(Sigma)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < 26; i++) // O(sigma + n)
        for (int j = 0; j < cnt[ord[i]]; j++)
            cout << (char)('a' + i);


    return 0;
}



