#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (n % 2 == 0) {
        int even = 2;
        int odd = 1;
        int half = n / 2;
        for(int i = 1; i <= half; i++) {
            cout << even << ' ' << odd << ' ';
            even += 2, odd += 2;
        }
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
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