#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

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
  int ans = 0;
  for (int k = 0; k < 21; k++) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      if (CHECK(a[i], k)) cnt1++;
      else cnt0++;
    }
    ans += (1 << k) * (3 * cnt0 * cnt0 * cnt1);
    ans += (1 << k) * ((cnt1 * cnt1 * cnt1));
  }
  cout << ans << '\n';

  return 0;
}