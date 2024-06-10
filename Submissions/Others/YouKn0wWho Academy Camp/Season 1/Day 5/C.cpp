#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int ans = 0, cnt = 1;
  for(int i = 1; i < s.length(); i++) {
    if(s[i] == s[i - 1]) {
      cnt++;
    }
    else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  cout << ans << '\n';

  return 0;
}