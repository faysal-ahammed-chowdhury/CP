#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9; 
int a[N], cnt[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    cnt[i] = 1;
  }

  int ans = 0;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int p, h; cin >> p >> h;
      int old = a[p];
      a[p] = h;
      cnt[old]--;
      cnt[h]++;
      if (cnt[old] == 1) ans--;
      if (cnt[h] == 2) ans++;
    }
    else {
      cout << ans << '\n';
    }
  }

  return 0;
}