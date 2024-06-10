#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  reverse(s.begin(), s.end());
  map<int, int> mp;
  int x = 0, ten = 1;
  long long ans = 0;
  for (auto c : s) {
    x += + (c - '0') * ten;
    x %= 2019;
    if (x == 0) ans++;
    ans += mp[x];
    cout << x << ' ' << ans << '\n';
    mp[x]++;
    ten *= 10;
    ten %= 2019;
  }
  cout << (ans) << '\n';

  return 0;
}