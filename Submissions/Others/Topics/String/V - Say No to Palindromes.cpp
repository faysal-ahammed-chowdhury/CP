#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
string beautiful[6];
int pref[6][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<char> p({'a', 'b', 'c'});
  int id = 0;
  do {
    beautiful[id].resize(n);
    for (int i = 0; i < n; i++) {
      beautiful[id][i] = p[i % 3];
    }
    id++;
  } while (next_permutation(p.begin(), p.end()));

  for (int id = 0; id < 6; id++) {
    for (int i = 0; i < n; i++) {
      pref[id][i] = s[i] != beautiful[id][i];
      if (i) {
        pref[id][i] += pref[id][i - 1];
      }
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    l--, r--;
    int ans = inf;
    for (int id = 0; id < 6; id++) {
      int op = 0;
      // for (int i = l; i <= r; i++) {
      //   op += s[i] != beautiful[id][i];
      // }
      op = pref[id][r] - (l ? pref[id][l - 1] : 0);
      ans = min(ans, op);
    }
    cout << ans << '\n';
  }

  return 0;
}