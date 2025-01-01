#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1e6;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  vector<int> v = a;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int idx = -1, sz = v.size();
  for (int i = 0; i < sz; i++) {
    if (v[i] == a[0]) {
      idx = i;
      break;
    }
  }
  int ans = 0, x, y;
  if (idx == 0) x = 1;
  else x = (abs(v[idx - 1] + v[idx]) + 1) / 2;

  if (idx == sz - 1) y = MAXV;
  else y = (abs(v[idx] + v[idx + 1])) / 2;
  ans = y - x + 1;
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