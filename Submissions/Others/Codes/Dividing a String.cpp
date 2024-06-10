#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  string last = "";
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s.substr(i, 1) == last) {
      if (i + 1 <= n) {
        last = s.substr(i, 2);
        ans++;
      }
      i++;
    }
    else {
      last = s[i];
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}