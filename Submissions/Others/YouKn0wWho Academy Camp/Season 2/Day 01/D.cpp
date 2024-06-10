#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m; cin >> m;
  int b[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int l; cin >> l;
  int c[l + 1];
  for (int i = 1; i <= l; i++) {
    cin >> c[i];
  }
  set<int> se;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= l; k++) {
        se.insert(a[i] + b[j] + c[k]);
      }
    }
  }
  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    if (se.find(x) == se.end()) {
      cout << "No\n";
    }
    else {
      cout << "Yes\n";
    }
  }

  return 0;
}