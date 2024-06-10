#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x; cin >> x;
  bitset<32> bs(x);
  string s = bs.to_string();
  int n = s.size();
  reverse(s.begin(), s.end());
  int ans[n + 1];
  for (int i = 0; i < n; i++) {
    ans[i] = s[i] - '0';
  }
  for (int i = 1; i < n; i++) {
    if (ans[i - 1] == 1 and ans[i] == 1) {
      ans[i - 1] = -1;
      while (i < n and ans[i] == 1) {
        ans[i] = 0;
        i++;
      }
      ans[i - 1] = 0;
      ans[i] = 1;
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}