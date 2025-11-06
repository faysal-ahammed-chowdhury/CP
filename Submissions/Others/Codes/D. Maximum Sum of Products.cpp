#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005;
int n, a[N], b[N];
ll pref[N], dp[N][N];

ll f(int i, int j) {
  if (i == j) return 1ll * a[i] * b[j];
  if (i > j) return 0;
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = (1ll * a[i] * b[j]) + (1ll * a[j] * b[i]) + f(i + 1, j - 1);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    pref[i] = pref[i - 1] + (1ll * a[i] * b[i]);
  }

  ll ans = pref[n];
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      ll cur = f(i, j);
      cur += pref[i - 1];
      cur += pref[n] - pref[j];
      ans = max(ans, cur);
    }
  }

  cout << ans << '\n';

  return 0;
} 