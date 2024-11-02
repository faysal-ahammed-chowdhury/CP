#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  string s; cin >> s;
  int ans = 0;
  for (int i = 0; i + 2 < n; i++) {
    if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') ans++;
  }
  while (q--) {
    int i; char c; cin >> i >> c;
    i--;
    if (i - 2 >= 0) {
      if (s[i - 2] == 'A' and s[i - 1] == 'B' and s[i] == 'C') ans--;
    }
    if (i - 1 >= 0 and i + 1 < n) {
      if (s[i - 1] == 'A' and s[i] == 'B' and s[i + 1] == 'C') ans--;
    }
    if (i + 2 < n) {
      if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') ans--;
    }
    s[i] = c;
    if (i - 2 >= 0) {
      if (s[i - 2] == 'A' and s[i - 1] == 'B' and s[i] == 'C') ans++;
    }
    if (i - 1 >= 0 and i + 1 < n) {
      if (s[i - 1] == 'A' and s[i] == 'B' and s[i + 1] == 'C') ans++;
    }
    if (i + 2 < n) {
      if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}