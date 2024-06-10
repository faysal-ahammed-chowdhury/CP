#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    int max = 2 * n;
    int ans[3][n + 1];
    
    int curr = 1;
    for(int i = 1; i <= n; i += 2) {
        ans[2][i] = curr++;
        if(i + 1 <= n) {
            ans[1][i + 1] = curr++;
        }
    }

    for(int i = 2; i <= n; i += 2) {
        ans[2][i] = curr++;
        if(i + 1 <= n) {
            ans[1][i + 1] = curr++;
        }
    }

    ans[1][1] = max;
    ans[2][n] = max - 1;

    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
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