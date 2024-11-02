#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];
double P[N], dp[N][N * N];
bool vis[N][N * N];

double f(int i, int amount) {
  if (i > n) return amount == 0;
  if (vis[i][amount]) return dp[i][amount];
  vis[i][amount] = true;
  double ans = f(i + 1, amount);
  if (amount - a[i] >= 0) {
    ans = max(ans, (1.0 - P[i]) * f(i + 1, amount - a[i]));
  }
  return dp[i][amount] = ans;
}

int cs;
void solve() {
  double p; cin >> p >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> P[i];
  }
  int ans = 0;
  memset(vis, false, sizeof vis);
  for (int amount = 0; amount <= 10000; amount++) {
    double dhora_na_khawar_mx_probability = f(1, amount);
    double dhora_khawar_mn_probability = 1.0 - dhora_na_khawar_mx_probability;
    if (dhora_khawar_mn_probability <= p + (1e-9)) ans = max(ans, amount);
  }
  cout << "Case " << ++cs << ": " << ans << '\n';
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