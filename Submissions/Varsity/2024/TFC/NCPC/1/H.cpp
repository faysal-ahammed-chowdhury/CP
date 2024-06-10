#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  string ans = "AWAWHOO";
  int x = 7;
  while (x <= n) {
    x++;
    ans += 'O';
  }

  cout << ans << '\n';

  return 0;
}