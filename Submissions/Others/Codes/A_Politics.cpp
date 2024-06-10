#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, k; cin >> n >> k;
    int arr[n + 1][k + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            char ch; cin >> ch;
            arr[i][j] = (ch == '+' ? 1 : 0);
        }
    }
    int eligible[n + 1];
    fill(eligible + 1, eligible + n + 1, 1);
    // each discussion
    for(int i = 1; i <= k; i++) {
        for(int j = 2; j <= n; j++) {
            if(arr[j][i] != arr[1][i]) {
                eligible[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(eligible[i]) {
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