#include <bits/stdc++.h>
using namespace std;

void solve() {
  unsigned long long a, b, c, d; cin >> a >> b >> c >> d;
  if ((unsigned __int128)a * d == (unsigned __int128)b * c) {
    cout << "Equal\n";
  }
  else {
    cout << "Not Equal\n";
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