#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int first = a[1], second = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] % first == 0) continue;
    else if (second == -1) {
      second = a[i];
      break;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] % first == 0) continue;
    if (a[i] % second == 0) continue;
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
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