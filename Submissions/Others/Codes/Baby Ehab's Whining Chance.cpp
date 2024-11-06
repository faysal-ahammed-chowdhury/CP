#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("lis.in", "r", stdin);

  string s; cin >> s;
  int f = s[0] - '0';

  int ans = 9 * (s.size() - 1);
  ans += f;
  if (count(s.begin() + 1, s.end(), '9') != (s.size() - 1)) {
    ans--;
  }
  cout << ans << '\n';

  return 0;
}