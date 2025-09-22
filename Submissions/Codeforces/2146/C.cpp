#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;

  int ans[n + 1];
  queue<int> q;
  int last = n;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      for (int j = i + 1; j <= last; j++) {
        ans[j] = q.front();
        q.pop();
      }
      ans[i] = i;
      last = i - 1;
    }
    else {
      q.push(i);
    }
  }

  for (int i = 1; i <= last; i++) {
    ans[i] = q.front();
    q.pop();
  }

  int pref[n + 1], suff[n + 2];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = max(pref[i - 1], ans[i]);
  }
  suff[n + 1] = 1e6;
  for (int i = n; i >= 1; i--) {
    suff[i] = min(suff[i + 1], ans[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      int mx = pref[i - 1];
      int mn = suff[i + 1];
      // cout << i << ' ' << mx << ' ' << mn << '\n';
      if (!(mn < ans[i] or mx > ans[i])) {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}