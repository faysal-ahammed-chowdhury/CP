#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string x, y; cin >> x >> y;
  int n = x.size();

  for (int i = 0; i < n; i++) {
    if (x[i] != y[i]) {
      char a = min(x[i], y[i]);
      char b = max(x[i], y[i]);
      x[i] = a;
      y[i] = b;
      for (int j = i + 1; j < n; j++) {
        char a = min(x[j], y[j]);
        char b = max(x[j], y[j]);
        x[j] = b;
        y[j]= a;
      }
      break;
    }
  }

  cout << x << '\n' << y << '\n';
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