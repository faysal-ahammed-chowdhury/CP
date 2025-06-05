#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int x; cin >> x;
  if (x == 1) {
    cout << 3 << '\n';
    return;
  }
  if (x <= 3) {
    cout << 5 << '\n';
    return;
  }

  array<int, 3> a = {1, 1, 3};

  int ans = 3;
  while (a[0] < x) {
    if (a[0] == a[1]) a[1] = a[2];
    else if (a[1] == a[2]) a[0] = a[1] * 2 + 1;
    ans++;
    sort(a.begin(), a.end());
  }

  cout << ans << '\n';
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