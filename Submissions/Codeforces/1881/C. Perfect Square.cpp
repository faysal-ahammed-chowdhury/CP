#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  int idx = 0;
  int id[n][n];
  map<int, char> mp;

  memset(id, -1, sizeof(id));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - i - 1; j++) {
      id[i][j] = idx;
      mp[idx++] = (a[i][j]);
    }
  }

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j++) {
      if (id[i][j] != -1) {
        id[j][n - i - 1] = id[i][j];
        mp[id[i][j]] = max(mp[id[i][j]], (a[j][n - i - 1]));
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans += mp[id[i][j]] - a[i][j];
    }
  }

  cout << ans << '\n';
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