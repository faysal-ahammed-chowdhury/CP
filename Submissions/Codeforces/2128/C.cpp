#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cur = 1e9 + 9;
  for (int i = 1; i <= n; i++) {
    int mx = cur + max(0ll, (cur - 1));
    if (mx < a[i]) {
      cout << "NO\n";
      return;
    }

    cur = min(cur, a[i]);
  }

  cout << "YES\n";
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