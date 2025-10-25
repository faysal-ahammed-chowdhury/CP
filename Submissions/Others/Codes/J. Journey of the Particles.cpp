#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int a[N + N], ans[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  set<pair<int, int>> se;
  for (int i = 1; i <= n + n; i++) {
    if (i <= n) se.insert({a[i] - ((i - 1) * k), i});
    int me = a[i] - ((i - 1) * k);
    // cout << me << '\n';
    auto it = se.upper_bound({me, 1e9});
    vector<pair<int, int>> v;
    while (it != se.end()) {
      int x = (*it).first;
      int idx = (*it).second;
      ans[idx] = i;
      if (ans[idx] > n) ans[idx] -= n;
      v.push_back({x, idx});
      ++it;
    }

    for (auto [x, idx] : v) {
      se.erase({x, idx});
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}