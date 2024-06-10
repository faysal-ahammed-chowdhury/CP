#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int x = 0, y  = 0;
  for (auto c : s) {
    x += c == 'A';
    y += c == 'B';
  }

  if (x >= y) {
    cout << "A\n";
  }
  else {
    cout << "B\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}