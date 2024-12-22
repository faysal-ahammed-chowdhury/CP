#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int a[m + 1];
  for(int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  set<int> se;
  for(int i = 1; i <= n; i++) {
    se.insert(i);
  }

  while (k--) {
    int x; cin >> x;
    se.erase(x);
  }

  if (se.size() == 0) {
    for (int i = 1; i <= m; i++) {
      cout << 1;
    }
    cout << '\n';
    return;
  }
  if (se.size() > 1) {
    for (int i = 1; i <= m; i++) {
      cout << 0;
    }
    cout << '\n';
    return;
  }

  int miss = *se.begin();
  for (int i = 1; i <= m; i++) {
    cout << (a[i] == miss ? 1 : 0);
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