#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n; cin >> n;
    int arr[n - 1];
    for(int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            v[i] = arr[i];
        }
        else if (i == n - 1) {
            v[i] = arr[i - 1];
        }
        else {
            v[i] = min(arr[i - 1], arr[i]);
        }
    }

    for(auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
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