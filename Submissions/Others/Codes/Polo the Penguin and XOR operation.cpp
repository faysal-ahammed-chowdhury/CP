#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  memset(a, -1, sizeof a);
  for (int i = n; i >= 0; i--) {
    if (a[i] != -1) continue;
    int bit = __lg(i);
    int x = 0;
    for (int k = 0; k <= bit; k++) {
      if (CHECK(i, k) == false) {
        x += (1 << k);
      }
    }
    if (i < x) continue;
    a[i] = x;
    a[x] = i;
    // cout << i << ' ' << x << '\n';
  }
  if (a[0] == -1) a[0] = 0;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += a[i] ^ i;
  }
  cout << ans << '\n';
  for (int i = 0; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}