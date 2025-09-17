#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, a[N], dp[N];
map<int, vector<int>> mp;

int f(int i) {
  if (i > n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = f(i + 1);
  auto idx = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i) - mp[a[i]].begin();
  int mx = idx + a[i] - 1;
  if (mx < mp[a[i]].size()) {
    ans = max(ans, a[i] + f(mp[a[i]][mx] + 1));
  }
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
    dp[i] = -1;
  }

  cout << f(1) << '\n';

  for (int i = 1; i <= n; i++) {
    mp[a[i]].clear();
  }
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