#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105, mod = 998244353;
int n, a[N], b[N], dp[N][2];

int f(int i, bool last_swap) {
  if (i > n) return 1;
  int last1, last2;
  if (last_swap) {
    last1 = b[i - 1];
    last2 = a[i - 1];
  }
  else {
    last1 = a[i - 1];
    last2 = b[i - 1];
  }

  int &ans = dp[i][last_swap];
  if (ans != -1) return ans;
  ans = 0;
  if (a[i] >= last1 and b[i] >= last2) {
    ans += f(i + 1, false);
    ans %= mod;
  }
  if (b[i] >= last1 and a[i] >= last2) {
    ans += f(i + 1, true);
    ans %= mod;
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  cout << f(1, false) << '\n';
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