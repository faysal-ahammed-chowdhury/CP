#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int a[n + 1], cnt[n + 1];

  for (int i = 1; i <= n; i++) {
    a[i] = i;
    cnt[i] = 1;
  }

  int ans = 0;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int ke, kothay; cin >> ke >> kothay;
      int agekoichilo = a[ke];
      a[ke] = kothay;
      cnt[agekoichilo]--;
      if (cnt[agekoichilo] == 1) ans--;
      cnt[kothay]++;
      if (cnt[kothay] == 2) ans++;
    }
    else {
      cout << ans << '\n';
    }
  }

  return 0;
}