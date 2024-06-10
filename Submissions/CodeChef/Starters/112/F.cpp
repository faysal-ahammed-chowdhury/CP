#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  if (x == 1) {
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  else if (x == n) {
    for (int i = n; i >= 1; i--) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  else {
    int d = x - 1;
    int val = n - d;
    vector<int> ans;
    ans.push_back(x);
    for (int i = 1; i <= n; i++) {
      if (i == x or i == val) continue;
      ans.push_back(i);
    }
    ans.push_back(val);
    if (ans.size() == n) {
      for (auto val : ans) {
        cout << val << ' ';
      }
      cout << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}