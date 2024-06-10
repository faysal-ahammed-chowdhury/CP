#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b; cin >> a >> b;
  if (a & 1 and b & 1) {
    cout << "NO\n";
    return;
  }

  if (a > b) swap(a, b);
  if (a & 1) {
    int x = b / 2;
    int y = a + a;
    if (x > y) swap(x, y);
    if (a != x or b != y) {
      cout << "YES\n";
      return;
    }
  }
  else if (b & 1) {
    int x = a / 2;
    int y = b + b;
    if (x > y) swap(x, y);
    if (a != x or b != y) {
      cout << "YES\n";
      return;
    }
  }
  else {
    int x = b / 2;
    int y = a + a;
    if (x > y) swap(x, y);
    if (a != x or b != y) {
      cout << "YES\n";
      return;
    }

    x = a / 2;
    y = b + b;
    if (x > y) swap(x, y);
    if (a != x or b != y) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
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