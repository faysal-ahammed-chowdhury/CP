#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b; cin >> a >> b;
  int c, d; cin >> c >> d;
  if (a > b) {
    swap(a, b);
    swap(c, d);
  }
  if (c >= d) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
  }
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