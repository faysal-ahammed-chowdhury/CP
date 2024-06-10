#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  string s; cin >> s;
  s = '.' + s;
  int last = 0;
  int i = 0;
  int ans = 0;
  for (auto c : s) {
    if (c == '0') {
      ans += (i - last > 1 ? i - last : 0);
      last++;
    }
    i++;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}