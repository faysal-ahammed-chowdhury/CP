#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s; cin >> s;

  int old_m = m;

  int x = 0, buy = 0;
  for (auto c : s) {
    if (c == '0') { //  wash
      x = buy;
      m = old_m;
    }
    else if (c == '1') { // plain
      if (m == 0) {
        if (x > 0) x--;
        else buy++;
      }
      else m--;
    }
    else {
      if (x > 0) x--;
      else buy++;
    }
  }

  cout << buy << '\n';

  return 0;
}