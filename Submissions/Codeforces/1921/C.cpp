#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n, left, a, b; cin >> n >> left >> a >> b;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int now = 0;
  for (int i = 1; i <= n; i++) {
    int d = arr[i] - now;
    int need = d * a;
    int need2 = b;
    left -= min(need, need2);
    now = arr[i];
    if (left <= 0) {
      cout << "NO\n";
      return;
    }
  }
  if (left > 0) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}