#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  s = '.' + s;
  int q; cin >> q;
  while (q--) {
    int l, r, k; cin >> l >> r >> k;
    string tmp = s.substr(0, l);
    int len = r - l  + 1;
    k %= len;
    tmp += s.substr(r - k + 1, k);
    int x = len - k;
    tmp += s.substr(l, x);
    if (r + 1 <= s.size()) tmp += s.substr(r + 1);
    s = tmp;
  }

  cout << s.substr(1) << '\n';

  return 0;
}