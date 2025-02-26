#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  string s; cin >> s;
  for (auto c : s) {
    if (c == 'x') x--;
    else x++;
    x = max(0, x);
  }

  cout << x << '\n';

  return 0;
}