#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int cnt[n + 1];
  memset(cnt, 0, sizeof cnt);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    cnt[p]++;
  }

  multiset<int, greater<int>> ms;
  ms.insert(1);
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) ms.insert(cnt[i]);
  }

  int sz = ms.size();
  int ans = sz, i = 0;

  vector<int> v;
  for (auto x : ms) {
    int rem = sz - i;
    int nw = x - rem;
    if (nw > 0) v.push_back(nw);
    i++;
  }
  ms.clear();
  for (auto x : v) {
    ms.insert(x);
  }
  v.clear();

  while (true) {
    if (ms.empty()) break;
    ans++;
    for (auto x : ms) {
      int nw = x - 1;
      if (nw > 0) v.push_back(nw);
    }
    ms.clear();
    for (auto x : v) {
      ms.insert(x);
    }
    v.clear();

    if (ms.empty()) break;

    int first = *ms.begin();
    ms.erase(ms.begin());
    if (first > 1) ms.insert(first - 1);

    // for (auto x : ms) cout << x << ' ';
    //   cout << '\n';

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