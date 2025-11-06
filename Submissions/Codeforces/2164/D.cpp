#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t;

  if (s[0] != t[0]) {
    cout << -1 << '\n';
    return;
  }
  if (s == t) {
    cout << 0 << '\n';
    return;
  }

  int kk = k;
  s = '#' + s;
  t = '#' + t;

  int nxt[n + 1][26];
  memset(nxt, -1, sizeof nxt);

  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 26; c++) {
      nxt[i][c] = nxt[i - 1][c];
    }
    nxt[i][s[i] - 'a'] = i;
  }


  vector<string> ans;

  
  while (k--) {
    if (s == t) break;
    string tmp = "#";
    for (int i = 1; i <= n; i++) {
      tmp += "#";
    }
    tmp[1] = s[1];
    int last = n;
    for (int i = n; i >= 1; i--) {
      last = min(last, i);
      int x = nxt[last][t[i] - 'a'];
      // cout << i << ' ' << x << '\n';
      if (x != -1 and i != x) {
        tmp[x + 1] = s[x];
        last = x;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (tmp[i] == '#') {
        tmp[i] = s[i];
      }
    }

    // cout << tmp << '\n';

    s = tmp;

    ans.push_back(s);

    memset(nxt, -1, sizeof nxt);

    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < 26; c++) {
        nxt[i][c] = nxt[i - 1][c];
      }
      nxt[i][s[i] - 'a'] = i;
    }
  }

  if (s != t) {
    cout << -1 << '\n';
    return;
  }

  cout << ans.size() << '\n';
  if (ans.size() > 0) {
    for (auto x : ans) {
      cout << x.substr(1) << '\n';
    }
  }
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