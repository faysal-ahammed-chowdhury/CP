#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int cnt[n + 50];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    int x = max(0, cnt[i] - 2);
    cnt[i + 1] += x;
    cnt[i] -= x;
  }

  bool ok = true;
  for (int i = 1; i <= n + 10; i++) {
    ok &= cnt[i] % 2 == 0;
    ok &= cnt[i] >= 0;
  }

  if (ok) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}