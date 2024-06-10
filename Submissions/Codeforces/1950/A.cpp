#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if (a < b and b < c) {
    cout << "STAIR\n";
  }
  else if (a < b and b > c) {
    cout << "PEAK\n";
  }
  else {
    cout << "NONE\n";
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