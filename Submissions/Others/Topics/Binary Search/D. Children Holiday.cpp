#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
const int N = 1009;
int m, n, t[N], z[N], y[N], arr[N];

bool ok(int time) {
    long long total_possible = 0;
    long long need = m;
    for(int i = 1; i <= n; i++) {
        int block_time = t[i] * z[i] + y[i];
        int count_block = time / block_time;
        long long possible = count_block * z[i];
        int remaining = time % block_time;
        possible += min(z[i], remaining / t[i]);
        total_possible += possible;

        arr[i] = min(need, possible);
        need -= arr[i];
    }
    return total_possible >= m;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> z[i] >> y[i];
    }
    int l = 0, r = MAX, ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    ok(ans);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}