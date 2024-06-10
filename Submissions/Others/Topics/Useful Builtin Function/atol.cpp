#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    string s = "1234";
    cout << s.c_str() << '\n'; // return char array
    cout << atol(s.c_str()) << '\n'; // take char array of number and return its int value
    cout << atol("H12") << '\n'; // return 0 if invalid
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}