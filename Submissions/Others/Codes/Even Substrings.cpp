#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i] - '0') % 2 == 0) {
      ans += i + 1;
    }
  }

  cout << ans << '\n';

  return 0;
} 