#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s1.substr(n - i) == s2.substr(0, i)) {
      cnt = i;
    }
  }

  int ans = n + (n - cnt);
  cout << ans << '\n';

  return 0;
}