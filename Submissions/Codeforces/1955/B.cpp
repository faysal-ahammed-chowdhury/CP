#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, c, d; cin >> n >> c >> d;
  int x = n * n;
  multiset<int> se;
  for (int i = 1; i <= x; i++) {
    int val; cin >> val;
    se.insert(val);
  }
  int first = *se.begin();
  int a[n + 1][n + 1];
  a[1][1] = first;
  for (int i = 2; i <= n; i++) {
    a[i][1] = a[i - 1][1] + c;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      a[i][j] = a[i][j - 1] + d;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (se.find(a[i][j]) == se.end()) {
        cout << "NO\n";
        return;
      }
      se.erase(se.find(a[i][j]));
    }
  }
  cout << "YES\n";
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