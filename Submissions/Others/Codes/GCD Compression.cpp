#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  n += n;
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) {
      odd.push_back(i);
    }
    else {
      even.push_back(i);
    }
  }

  if ((int)odd.size() & 1) {
    odd.pop_back();
  }
  if ((int)even.size() & 1) {
    even.pop_back();
  }
  else {
    if (odd.size() > 0) {
      odd.pop_back();
      odd.pop_back();
    }
    else {
      even.pop_back();
      even.pop_back();
    }
  }

  int nn = odd.size(), m = even.size();
  vector<pair<int, int>> v;
  for (int i = 0; i < nn; i += 2) {
    v.push_back({odd[i], odd[i + 1]});
  }
  for (int i = 0; i < m; i += 2) {
    v.push_back({even[i], even[i + 1]});
  }
  sort(v.begin(), v.end());
  for (auto [x, y] : v) {
    cout << x << ' ' << y << '\n';
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