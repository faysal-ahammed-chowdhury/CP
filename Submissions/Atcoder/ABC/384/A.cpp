#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  char c1, c2; cin >> c1 >> c2;
  string s; cin >> s;
  for (auto &c : s) {
    if (c != c1) c = c2;
  }
  cout << s << '\n';

  return 0;
}