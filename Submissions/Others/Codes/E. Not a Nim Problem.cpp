#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXV = 1e7 + 9;
int spf[MAXV], grundy[MAXV];

void spf_sieve() {
  for (int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }
  int cnt = 0;
  for (int i = 2; i < MAXV; i++) {
    if (spf[i] == i) {
      grundy[i] = ++cnt;
      for (int j = i; j < MAXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    xr ^= grundy[spf[x]];
    if (x % 2 == 0) continue;
  }

  if (xr) cout << "Alice\n";
  else cout << "Bob\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();
  grundy[2] = 0;
  grundy[1] = 1;
  spf[1] = 1;

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}