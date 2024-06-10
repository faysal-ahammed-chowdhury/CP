#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int L = 0, D = 0, R = 0, U = 0;
  string s; cin >> s;
  for (auto c : s) {
    if (c == 'L') L++;
    else if (c == 'R') R++;
    else if (c == 'D') D++;
    else if (c == 'U') U++;
  }

  int ans = 2 * (min(L, R) + min(D, U));
  cout << ans << '\n';

  return 0;
}