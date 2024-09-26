#include <bits/stdc++.h>
using namespace std;

const int N = 105, mod = 1e9 + 7;
int n, a[N], dp[N][N][N];

int f(int i, int sum, int rem, int k) {
  if (i > n) {
    return sum == 0 and rem == 0;
  }
  int &ans = dp[i][sum][rem];
  if (ans != -1) return ans;
  ans = f(i + 1, sum, rem, k);
  if (rem > 0) {
    int x = (a[i]) % k;
    if (x < 0) x += k;
    ans += f(i + 1, (sum + x) % k, rem - 1, k);
    ans %= mod;
  }
  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int cnt = 1; cnt <= n; cnt++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    ans += f(1, 0, cnt, cnt);
    ans %= mod;
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}