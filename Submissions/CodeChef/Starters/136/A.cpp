#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int left = s[0] == '1' ? 11 : 1;
  int right = s[1] == '1' ? 11 : 1;
  int up = s[2] == '1' ? 11 : 1;
  int down = s[3] == '1' ? 11 : 1;
  int x = (left + right - 1);
  int y = (up + down - 1);
  cout << x * y << '\n';
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