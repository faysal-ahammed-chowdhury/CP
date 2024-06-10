#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long prefix[n];
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    while(q--) {
        // 0 based index
        int l, r; cin >> l >> r; 
        if(l == 0) {
            cout << prefix[r] << '\n';
        }
        else {
            cout << prefix[r] - prefix[l - 1] << '\n';
        }
    }
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