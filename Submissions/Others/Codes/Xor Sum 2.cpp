#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int psum[20][n + 1];
  memset(psum, 0, sizeof psum);
  for (int k = 0; k < 20; k++) {
    for (int i = 1; i <= n; i++) {
      psum[k][i] = psum[k][i - 1] + CHECK(a[i], k);
    }
  }
  // for (int k = 0; k < 3; k++) {
  //   cout << k << ": ";
  //   for (int i = 1; i <= n; i++) {
  //     cout << psum[k][i] << ' ';
  //   }
  //   cout << '\n';
  // }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int k = 0; k < 20; k++) {
      int cur = lower_bound(psum[k] + 1, psum[k] + n + 1, psum[k][i] - 1) - psum[k];
      if (psum[k][i] - 1 > 0) cur++; 
      mx = max(mx, cur);
    }
    ans += i - mx + 1;
    // cout << i << ' ' << mx << '\n';
  }
  cout << ans << '\n';

  return 0;
}