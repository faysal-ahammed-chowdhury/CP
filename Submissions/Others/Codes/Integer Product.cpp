#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    bool found = false;
    ll num = 0, cnt = 0;
    for (auto c : s) {
      if (c == '.') {
        found = true;
        continue;
      }
      else if (found) cnt++;
      num = num * 10 + (c - '0');
    }
    while (num % 2 == 0) {
      a[i].first++;
      num /= 2;
    }
    while (num % 5 == 0) {
      a[i].second++;
      num /= 5;
    }
    a[i].first -= cnt;
    a[i].second -= cnt;
  }
  map<pair<int, int>, int> mp;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int need2 = -a[i].first, need5 = -a[i].second;
    for (auto [pw, cnt] : mp) {
      if (pw.first >= need2 and pw.second >= need5) ans += cnt;
    }
    mp[a[i]]++;
  }
  cout << ans << '\n';

  return 0;
}