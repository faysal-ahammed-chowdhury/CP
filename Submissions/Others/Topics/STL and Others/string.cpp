#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s = "abcd";
    cout << s << '\n';
    s.push_back('e');
    cout << s << '\n';

    // s += 'e'; => O(1)
    // s = s + 'e'; -> O(len(s))

    s = "e" + s;
    cout << s << '\n';

    string a = "xy", b = "yz";
    cout << a + b << '\n';

    reverse(s.begin(), s.end());
    cout << s << '\n';
    cout << s.find("ba", 3) << '\n';
    cout << s.find("ed", 1) << '\n';
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