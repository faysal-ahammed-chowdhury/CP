#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  
  int cnt = 0, ans = 1e9;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') cnt++;
    int cnt2 = 0;
    for (int j = i + 1; j <= n; j++) {
      if (s[j] == '1') cnt2++;
    }
    ans = min(ans, cnt + cnt2);
  }

  cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '0') cnt++;
    int cnt2 = 0;
    for (int j = i - 1; j >= 1; j--) {
      if (s[j] == '1') cnt2++;
    }
    ans = min(ans, cnt + cnt2);
  }

  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') cnt++;
    int cnt2 = 0;
    for (int j = i + 1; j <= n; j++) {
      if (s[j] == '0') cnt2++;
    }
    ans = min(ans, cnt + cnt2);
  }

  cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') cnt++;
    int cnt2 = 0;
    for (int j = i - 1; j >= 1; j--) {
      if (s[j] == '0') cnt2++;
    }
    ans = min(ans, cnt + cnt2);
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