#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (v.size() < 2) {
      v.push_back(x);
    }
    else {
      int last = v.back();
      int sec_last = v[v.size() - 2];
      if ((sec_last < last and last < x) or (sec_last > last and last > x)) {
        v.pop_back();
        v.push_back(x);
      }
      else {
        v.push_back(x);
      }
    }
  }

  int k = v.size();
  cout << k << '\n';
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
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