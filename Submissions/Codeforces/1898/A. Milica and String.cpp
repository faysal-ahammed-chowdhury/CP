#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  
  if (mp['B'] == k) {
    cout << 0 << '\n';
    return;
  }

  char c1, c2; int need;
  if (mp['B'] > k) {
    c1 = 'B', c2 = 'A';
    need = mp['B'] - k;
  }
  else {
    c1 = 'A'; c2 = 'B';
    need = k - mp['B'];
  }

  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    if (cnt == need) {
      cout << 1 << '\n';
      cout << i << ' ' << c2 << '\n';
      break;
    }
    if (s[i] == c1) {
      cnt++;
    }
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