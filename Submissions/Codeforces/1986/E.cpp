#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 2e18;
int n, k, sz, dp[N][2];
vector<int> vec;

int f(int i, bool skipped) {
  if (i == sz) return skipped ? 0 : inf;
  int &ans = dp[i][skipped];
  if (ans != -1) return ans;
  ans = inf;
  if (!skipped) {
    if (i == sz - 1 or i + 2 < sz) ans = min(ans, f(i + 1, true));
    if (i + 2 < sz) ans = min(ans, (abs(vec[i] - vec[i + 2]) / k) + f(i + 3, true));
  }
  if (i + 1 < n) ans = min(ans, (abs(vec[i] - vec[i + 1]) / k) + f(i + 2, skipped));
  return ans;
}

void solve() {
  vec.clear();
  cin >> n >> k;
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x % k].push_back(x);
  }
  int ans = 0, cnt = 0;
  for (auto [_, v] : mp) {
    sort(v.begin(), v.end());
    sz = v.size();
    if (sz & 1) cnt++;
    if (cnt > 1) {
      cout << -1 << '\n';
      return;
    }
    if (sz & 1) {
      for (auto x : v) vec.push_back(x);
      for (int i = 0; i < sz; i++) {
        dp[i][0] = dp[i][1] = -1;
      }
      ans += f(0, false);
    }
    else {
      for (int i = 0; i < sz; i += 2) {
        ans += (v[i + 1] - v[i]) / k;
      }
    }
  }
  cout << ans << '\n';
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