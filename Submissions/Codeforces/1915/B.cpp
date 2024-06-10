#include <bits/stdc++.h>
using namespace std;

void solve() {
  char c[4][4];
  int x, y;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> c[i][j];
      if (c[i][j] == '?') {
        x = i, y = j;
      }
    }
  }

  set<char> se;
  for (int i = 1; i <= 3; i++) {
    se.insert(c[x][i]);
  }
  if (se.find('A') == se.end()) {
    cout << "A\n";
  }
  else if (se.find('B') == se.end()) {
    cout << "B\n";
  }
  else if (se.find('C') == se.end()) {
    cout << "C\n";
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