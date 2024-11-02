#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  s += t;
  cout << s << '\n';

  return 0;
}