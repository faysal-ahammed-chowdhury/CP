#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 10005, mod = 10000007;
int dp[N];

int a, b, c, d, e, f;
int fun(int n) {
  if (dp[n] != -1) return dp[n];;
  if (n == 0) return a;
  if (n == 1) return b;
  if (n == 2) return c;
  if (n == 3) return d;
  if (n == 4) return e;
  if (n == 5) return f;
  return dp[n] = (fun(n-1) % mod + fun(n-2) % mod + fun(n-3) % mod + fun(n-4) % mod + fun(n-5) % mod + fun(n-6) % mod) % mod;
}

int cs = 0;
void solve() {
  memset(dp, -1, sizeof dp);
  int n;
  cin >> a >> b >> c >> d >> e >> f >> n;
  cout << "Case " << ++cs << ": " << fun(n) % mod << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}