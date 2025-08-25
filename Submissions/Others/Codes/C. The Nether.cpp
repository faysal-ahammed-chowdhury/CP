#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;

  map<int, vector<int>> mp;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cout << "? " << i << ' ' << n << ' ';
    for (int j = 1; j <= n; j++) {
      cout << j << ' ';
    }
    cout << endl;
    int feedback; cin >> feedback;
    mp[feedback].push_back(i);
    mx = max(mx, feedback);
  }

  if (mx == 1) {
    cout << "! 1 " << 1 << endl;
    return;
  }

  int cur = mp[mx].front(), len = mx - 1;
  vector<int> res;
  while (len != 0) {
    res.push_back(cur);
    for (auto x : mp[len]) {
      cout << "? " << cur << ' ' << 2 << ' ' << cur << ' ' << x << endl;
      int feedback; cin >> feedback;
      if (feedback == 2) {
        cur = x;
        break;
      }
    }
    len--;
  }

  res.push_back(cur);

  cout << "! " << mx << ' ';
  for (auto x : res) {
    cout << x << ' ';
  }
  cout << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}