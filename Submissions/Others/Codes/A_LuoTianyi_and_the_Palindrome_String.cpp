#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

string s;
bool is_palindrome(int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++, j--;
    }
    return true;
}

void solve() {
    cin >> s;
    int len = s.length();
    int ans = -1;
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(!is_palindrome(i, j)) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << '\n';
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