#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += 1e5;
  }

  vector<pair<int, int>> ans;
  ans.emplace_back(1, 1);
  int last = 0;
  for (int i = 2; i < n; i++) {
    int mx = a[i] % (a[i] / 2 + 1);
    if (mx <= last) {
      last = a[i];
    }
    else {
      last = min(last + 1, mx);
      int mod = a[i] - last;
      ans.emplace_back(i, mod);
    }
  }

  cout << ans.size() + 1 << '\n';
  cout << 1 << ' ' << n << ' ' << (int)1e5 << '\n'; 
  for (auto [x, y] : ans) {
    cout << 2 << ' ' << x << ' ' << y << '\n';
  }

  return 0;
}