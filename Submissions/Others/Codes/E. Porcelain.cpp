#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105, M = 1e4 + 9;
int n, m, dp[N][M];
vector<int> a[N];

int f(int i, int need) {
  if (i > n) return 0;
  int &ans = dp[i][need];
  if (ans != -1) return ans;
  ans = f(i + 1, need);

  for (int j = 1; j <= a[i].size(); j++) {
    if (need >= j) ans = max(ans, a[i][j - 1] + f(i + 1, need - j));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    int tmp[k + 1], pref[k + 1];
    pref[0] = 0;
    for (int j = 1; j <= k; j++) {
      cin >> tmp[j];
      pref[j] = pref[j - 1] + tmp[j];
    }

    for (int cnt = 1; cnt <= k; cnt++) {
      int mx = 0;
      for (int front = 0; front <= cnt; front++) {
        int back = cnt - front;
        mx = max(mx, pref[front] + (pref[k] - pref[k - back]));
      }
      a[i].push_back(mx);
      // cout << cnt << ' ' << mx << '\n';
    }
  }

  memset(dp, -1, sizeof dp);
  cout << f(1, m) << '\n';

  return 0;
}