#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int l = 1, r = n;
  vector<int> v;
  while (l <= r) {
    if (l == r) v.push_back(l);
    else {
      v.push_back(r);
      v.push_back(l);
    }
    l++, r--;
  }
  reverse(v.begin(), v.end());
  for (auto x : v) cout << x << ' ';
  cout << '\n';
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