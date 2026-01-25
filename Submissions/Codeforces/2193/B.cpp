#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    int ex = n - i + 1;
    if (a[i] == ex) {
      cout << a[i] << ' ';
      continue;
    }
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == ex) {
        for (int k = j; k >= i; k--) {
          cout << a[k] << ' ';
        }
        for (int k = j + 1; k <= n; k++) {
          cout << a[k] << ' ';
        }
        cout << '\n';
        return;
      }
    }
  }
  cout << '\n';
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