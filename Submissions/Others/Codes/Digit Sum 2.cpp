#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  bool all_nine_except_first = true;
  int len = s.size();
  for (int i = 1; i < len; i++) {
    all_nine_except_first &= s[i] == '9';
  }
  int ans = 9 * (len - 1);
  if (all_nine_except_first) ans += s[0] - '0';
  else ans += (s[0] - '0') - 1;
  cout << ans << '\n';

  return 0;
}