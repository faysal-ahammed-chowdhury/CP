#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int cnt0 = 0, cnt1 = 0;
  int need = ((n / 2) - k);
  for (int i = 1; i <= n; i++) {
    cnt0 += s[i] == '0';
    cnt1 += s[i] == '1';
  }

  if (cnt0 < need or cnt1 < need) {
    cout << "NO\n";
    return;
  }

  cnt0 -= need;
  cnt1 -= need;

  int possible = (cnt0 / 2) + (cnt1 / 2);
  if (possible == k) cout << "YES\n";
  else cout << "NO\n";
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