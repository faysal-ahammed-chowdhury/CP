#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> v(n), a;
  for (auto &x : v) {
    cin >> x.first;
  }
  for (auto &x : v) {
    cin >> x.second;
  }

  int all = 0;

  a.emplace_back(0, 0);
  for (int i = 0; i < n; i++) {
    if (v[i].first <= v[i].second) {
      a.emplace_back(v[i].first, v[i].second);
      all += v[i].second - v[i].first;
    }
  }

  if (k == 0) {
    cout << all << '\n';
    return;
  }

  n = a.size() - 1;

  sort(a.begin() + 1, a.end(), [&](pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  });

  int profit[n + 1];
  for (int i = 1; i <= n; i++) {
    profit[i] = a[i].second - a[i].first;
  }

  int pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + profit[i];
  }

  if (k >= n) {
    cout << 0 << '\n';
    return;
  }

  multiset<pair<int, int>> ms;
  int loss = 0;
  for (int i = 1; i <= k; i++) {
    ms.insert(a[i]);
    loss += a[i].first;
  }

  int ans = 0;
  int sum = pref[n] - pref[k];
  ans = max(ans, sum - loss);

  for (int i = k + 1; i <= n; i++) {
    sum = pref[n] - pref[i];
    pair<int, int> largest = *(--ms.end());
    if (a[i].first < largest.first) {
      ms.erase(--ms.end());
      ms.insert(a[i]);
      loss -= largest.first;
      loss += a[i].first;
    }
    ans = max(ans, sum - loss);
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