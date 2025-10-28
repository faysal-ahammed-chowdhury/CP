#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_even = true, all_odd = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_even &=  a[i] % 2 == 0;
    all_odd &=  a[i] % 2 == 1;
  }

  if (all_even or all_odd) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
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