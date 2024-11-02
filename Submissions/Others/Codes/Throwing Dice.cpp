#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
int n, x;
ull dp[27][152];

ull f(int i, int sum) {
  if (i > n) return sum >= x;
  ull &ans = dp[i][sum];
  if (ans != -1) return ans;
  ans = 0;
  for (int k = 1; k <= 6; k++) {
    ans += f(i + 1, sum + k);
  }
  return ans;
}

ull power(int n, int x) {
  ull ans = 1;
  for (int i = 1; i <= x; i++) {
    ans *= n;
  }
  return ans;
}

int cs;
void solve() {
  cin >> n >> x;
  memset(dp, -1, sizeof dp);
  ull p = f(1, 0);
  ull q = power(6, n);
  ull x = __gcd(p, q);
  p /= x;
  q /= x;
  cout << "Case " << ++cs << ": " << p;
  if (q == 1) cout << '\n';
  else cout << "/" << q << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}