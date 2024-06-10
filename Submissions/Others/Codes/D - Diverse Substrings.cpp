#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int freq[10];
    memset(freq, 0, sizeof(freq));
    long long unique = 0;
    for (int j = i; j <= i + 100 and j <= n; j++) {
      freq[s[j] - '0']++;
      unique |= (1 << (s[j] - '0'));
      int x = __builtin_popcountll(unique);
      bool ok = true;
      for (int k = 0; k < 10; k++) {
        ok &= freq[k] <= x;
      }
      if (ok) ans++;
    }
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