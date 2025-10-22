#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
string s;
vector<int> pos[26];
int idx[N], nxt[N][26];

void solve() {
  for (int i = 0; i < 26; i++) {
    pos[i].clear();
  }

  cin >> s;
  int power; cin >> power;
  int n = s.size();
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    pos[s[i] - 'A'].push_back(i);
    idx[i] = pos[s[i] - 'A'].size() - 1;
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      nxt[i][j] = -1;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      if (i + 1 <= n) nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'A'] = i;
  }

  int ans = 0;
  for (int p = power; p <= n; p++) {
    int last = 1, cnt = 0;
    while (last <= n) {
      int mn = inf;
      for (char c = 'A'; c <= 'Z'; c++) {
        if (nxt[last][c - 'A'] == -1) continue;
        int st = idx[nxt[last][c - 'A']];
        int en = st + p - 1;
        if (en < pos[c - 'A'].size()) {
          mn = min(mn, pos[c - 'A'][en]);
        }
      }
      if (mn == inf) break;
      last = mn + 1;
      cnt++;
    }
    ans = max(ans, p * cnt);
  }

  cout << ans << '\n';
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