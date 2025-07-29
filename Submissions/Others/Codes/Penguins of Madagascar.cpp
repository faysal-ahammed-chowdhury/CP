#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int nxt[27][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  memset(nxt, -1, sizeof nxt);
  for (char c = 'a'; c <= 'z'; c++) {
    int idx = -1;
    for (int i = n; i >= 1; i--) {
      if (s[i] == c) idx = i;
      nxt[c - 'a'][i] = idx;
    }
  }

  int q; cin >> q;
  while (q--) {
    string t; cin >> t;
    int idx = 0;
    bool no = false;
    for (auto c : t) {
      if (nxt[c - 'a'][idx + 1] == -1) {
        no = true;
        cout << "NO\n";
        break;
      }
      idx = nxt[c - 'a'][idx + 1];
    }
    if (!no) cout << "YES\n";
  }

  return 0;
}