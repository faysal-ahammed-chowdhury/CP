#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  string t = s[1];
  sort(s + 1, s + n + 1);

  int m = t.size();
  m--;

  pair<int, int> a[m + 1];
  a[0] = {1, n};
  for (int j = 1; j <= m; j++) {
    int st = -1, en = -1;
    for (int i = a[j - 1].first; i <= a[j - 1].second; i++) {
      if (s[i][j] == t[j]) {
        if (st == -1) st = i;
        en = i;
      }
    }
    a[j] = {st, en}; 
  }

  int ans = 1;
  int cnt = 1;
  for (int i = 2; i <= m; i++) {
    // cout << a[i].first << ' ' << a[i].second << '\n';
    if (a[i].first == a[i - 1].first and a[i].second == a[i - 1].second) {
      cnt++;
      if (a[i].first == 1 and a[i].second == n) continue;
      if (cnt == 2) ans++;
      continue;
    }
    ans++;
    cnt = 1;
  }

  cout << ans << '\n';

  return 0;
}