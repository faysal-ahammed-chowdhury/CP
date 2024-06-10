#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;
long long dp[10005];
long long fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n] == -1) {
        long long ans = fn(n-1) % 10000007 + fn(n-2) % 10000007+ fn(n-3) % 10000007 + (fn(n-4) % 10000007) + fn(n-5) % 10000007 + fn(n-6) % 10000007;
        dp[n] = ans;
    }
    
    return dp[n];
}

void solve(int cnt) {
    int n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    fill(dp, dp + n + 1, -1);
    cout << "Case " << cnt << ": " << fn(n) % 10000007 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    int cnt = 1;
    while(t--) {
        solve(cnt++);
    }

    return 0;
}