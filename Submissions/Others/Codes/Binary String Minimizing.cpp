#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n; ll k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int last_zero = 0;
  int go[n + 1];
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      int need = i - last_zero - 1;
      need = min(1ll * need, k);
      go[i] = i - need;
      last_zero = go[i];
      k -= need;
    }
  }
  bool done[n + 1];
  memset(done, false, sizeof done);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      done[go[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (done[i]) cout << 0;
    else cout << 1;
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