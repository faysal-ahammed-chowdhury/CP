#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

void solve() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    bool done = false;
    while (n--) {
        if (!done) {
            cin.ignore();
            done = true;
        }
        string s; getline(cin, s);

        if (s.length() < 5) {
            cout << "OMG>.< I don't know!\n";
            continue;
        }

        int len = s.length() - 5;

        bool t1 = false, t2 = false;
        if (s.substr(0, 5) == "miao.") t1 = true;
        if (s.substr(len, 5) == "lala.") t2 = true;


        if (t1 == t2) cout << "OMG>.< I don't know!\n";
        else if (t1) cout << "Rainbow's\n";
        else cout << "Freda's\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}