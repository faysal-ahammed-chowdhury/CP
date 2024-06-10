#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, m; cin >> n >> m;
    if(n < m) {
        swap(n, m);
    }
    int nm = n * m;
    int arr[nm];
    for(int i = 0; i < nm; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + nm);
    int max_el = arr[nm - 1];
    int second_max = arr[nm - 2];
    int min = arr[0];
    int second_min = arr[1];
    long long ans = ((max_el - min) * (m * (n - 1))) + ((max(max_el - second_min, second_max - min)) * (m - 1));
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