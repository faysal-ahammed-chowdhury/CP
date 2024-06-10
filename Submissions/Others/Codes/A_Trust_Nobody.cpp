#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = -1;
    for(int k = 0; k <= n; k++) {
        int lie = 0;
        for(int i = 0; i < n; i++) {
            if(k < arr[i]) {
                lie++;
            }
        }
        if(lie == k) {
            ans = lie;
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