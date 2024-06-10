#include <bits/stdc++.h>
using namespace std;

void solve() {
    // word
    string s; getline(cin, s);
    stringstream ss;
    ss << s;
    string word;
    while(ss >> word) {
        cout << word << '\n';
    }

    // int to string
    stringstream ss2;
    int n = 102;
    ss2 << n;
    string num_s;
    ss2 >> num_s;
    cout << num_s << '\n';
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