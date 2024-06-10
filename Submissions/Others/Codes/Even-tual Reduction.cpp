#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int freq[26];
  memset(freq, 0, sizeof freq);
  string s; cin >> s;
  for (auto c : s) {
    freq[c - 'a']++;
  }

  bool ok = true;
  for (int i = 0; i < 26; i++) {
    ok &= freq[i] % 2 == 0;
  }
  cout << (ok ? "YES\n" : "NO\n");
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