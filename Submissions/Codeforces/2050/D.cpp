#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
 
  for (int i = 1; i <= n; i++) {
    int cur = s[i] - '0', idx = -1;
    for (int jj = 1, j = i + 1; jj <= 12; j++, jj++) {
      if (j > n) break;
      int x = s[j] - '0';
      x -= (j - i);
      if (x > cur) {
        cur = x;
        idx = j;
      }
    }
    // cout << i << ' ' << idx << '\n';
    if (idx == -1) continue;
    for (int j = idx; j > i; j--) {
      swap(s[j - 1], s[j]);
    }
    s[i] = '0' + cur;
  }

  cout << s.substr(1) << '\n';
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