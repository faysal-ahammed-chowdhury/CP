#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  bool flag[n];
  memset(flag, false, sizeof flag);

  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= i;
    if (xr == 0) {
      flag[i] = 1;
    }
  }
  if (xr == 0) {
    cout << "impossible\n";
    return;
  }

  if (n == 1) cout << "impossible\n";
  else if (n == 2) cout << "1 0\n";
  else if (n == 3) cout << "1 0 2\n";
  else {
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(0);
    ans.push_back(2);
    for (int i = 3; i < n; i++) {
      if (flag[i]) {
        ans.push_back(i + 1);
      }
      else if (flag[i - 1]) {
        ans.push_back(i - 1);
      }
      else ans.push_back(i);
    }
    int xr = 0;
    for (auto x : ans) {
      xr ^= x;
      assert(xr != 0);
      cout << x << ' ';
    }
    cout << '\n';
  }
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