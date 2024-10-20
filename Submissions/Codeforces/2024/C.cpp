#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  array<int, 3> a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
    b[i] =  a[i];
    if (a[i][0] < a[i][1]) {
      swap(a[i][0], a[i][1]);
    }
  }
  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    cout << b[a[i][2]][0] << ' ' << b[a[i][2]][1] << ' ';
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