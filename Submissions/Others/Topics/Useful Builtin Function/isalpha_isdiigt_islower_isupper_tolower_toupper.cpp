#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    char a = 'a', b = '6', c = 'A';
    cout << isalpha(a) << ' ' << isalpha(b) << '\n';
    cout << isdigit(a) << ' ' << isdigit(b) << '\n';
    cout << islower(a) << ' ' << islower(c) << '\n';
    cout << isupper(a) << ' ' << isupper(c) << '\n';
    cout << (char)(tolower(a)) << ' ' << (char)tolower(c) << '\n';
    cout << (char)toupper(a) << ' ' << (char)toupper(c) << '\n';
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