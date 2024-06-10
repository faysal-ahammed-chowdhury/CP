#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  if (a[n] == a[1]) cout << "NO\n";
  else {
    cout << "YES\n";
    if (mp.size() >= 3) {
      cout << "R";
      for (int i = 2; i <= n; i++) cout << "B";
      cout << '\n';
      return;
    }
    int x = -1;
    for (auto [val, cnt] : mp) {
      if (cnt > 1) {
        x = val;
        break;
      }
    }
    bool done = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] == x and !done) {
        done = true;
        cout << "R";
      }
      else cout << "B";
    }
    cout << '\n';
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