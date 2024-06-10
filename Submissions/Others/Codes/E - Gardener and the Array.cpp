#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    a[i].push_back(k);
    for (int j = 1; j <= k; j++) {
      int x; cin >> x;
      a[i].push_back(x);
      mp[x]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    bool ok = true;
    int k = a[i].front();
    for (int j = 1; j <= k; j++) {
      int x = a[i][j];
      if (mp[x] == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
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