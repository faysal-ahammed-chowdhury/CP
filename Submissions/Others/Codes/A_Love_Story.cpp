#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    string s; cin >> s;
    string codeforces = "codeforces";
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != codeforces[i]) {
            count++;
        }
    }
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}