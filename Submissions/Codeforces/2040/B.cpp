#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> v;

void prec() {
  int x = 1;
  v.push_back(x);
  while (x < N) {
    x = (x + 1) * 2;
    v.push_back(x);
  }
  // for (auto x : v) cout << x << ' ';
}

void solve() {
  int n; cin >> n;
  auto idx = lower_bound(v.begin(), v.end(), n) - v.begin();
  cout << ++idx << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}