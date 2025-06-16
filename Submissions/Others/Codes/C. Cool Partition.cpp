#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<int> se, tmp;
  se.insert(a[1]);
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    if (se.find(a[i]) != se.end()) {
      se.erase(a[i]);
    }
    tmp.insert(a[i]);
    if (se.empty()) {
      ans++;
      se = tmp;
      tmp.clear();
    }
  }
  cout << ans << '\n';
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