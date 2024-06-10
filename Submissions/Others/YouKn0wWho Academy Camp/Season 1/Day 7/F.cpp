#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  s = '.' + s;
  int freq[n + 5][30];
  memset(freq, 0, sizeof(freq));
  for (int i = 1; i <= n; i++) {
    freq[i][s[i] - 'a']++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      freq[i][j] += freq[i - 1][j];
    }
  }

  while (q--) {
    int l, r; cin >> l >> r; char c; cin >> c;
    int sz = (r - l + 1);
    int x = sz / n;
    int ans = x * freq[n][c - 'a'];
    int rem = sz % n;
    int start = ((l % n) == 0 ? n : (l % n)), end = (l + rem - 1) % n;
    if (end == 0) {
      end = n;
    }
    if (rem > 0) {
      if (start <= end) {
        ans += freq[end][c - 'a'] - freq[start - 1][c - 'a'];
      }
      else {
        ans += freq[n][c - 'a'] - freq[start - 1][c - 'a'];
        ans += freq[end][c - 'a'];
      }
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}