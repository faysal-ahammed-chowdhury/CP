#include <bits/stdc++.h>
using namespace std;

void solve() {
  int d; cin >> d;
  int val = 10000;
  vector<int> ans;
  while (val > 1) {
    int times = d / val;
    int sq = (int)sqrt(times);
    int rem = d - (sq * sq * val);
    for (int i = 1; i <= sq; i++) ans.push_back(val + 2);
    for (int i = 1; i <= sq; i++) ans.push_back(val + 1);
    if (sq) ans.push_back(1);
    val /= 10;
    d = rem;
  }
  ans.push_back(1);
  for (int i = 1; i <= d; i++) ans.push_back(3);
  ans.push_back(2);
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' '; cout << '\n';
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