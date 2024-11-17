#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int L[N], R[N];

void solve() {
  int n, m, dest; cin >> n >> m >> dest;
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }

  vector<pair<int, int>> v;
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  multiset<int, greater<int>> ms;

  // for (auto [x, y] : v) {
  //   cout << x << ' ' << y << '\n';
  // }

  int p = 1, ans = 0;

  for (int i = 1; i <= n; i++) {
    auto it = lower_bound(v.begin(), v.end(), make_pair(R[i - 1], 0ll));
    while (it != v.end()) {
      if ((*it).first >= L[i]) break;
      ms.insert((*it).second);
      ++it;
    }

    int need = (R[i] - L[i] + 1) + 1;
    if (p >= need) continue;
    int power_need = need - p;

    while (power_need > 0 and !ms.empty()) {
      ans++;
      power_need -= *ms.begin();
      p += *ms.begin();
      ms.erase(ms.begin());
    }

    if (power_need > 0) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << ans << '\n';
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