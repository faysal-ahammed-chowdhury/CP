#include <bits/stdc++.h>
using namespace std;

struct Student {
    int roll;
    string name;
};

void solve() {
    Student s;
    s.roll = 1;
    s.name = "Faysal";
    cout << s.roll << ' ' << s.name << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}