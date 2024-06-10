#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; ll s; cin >> n >> s;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int r = 1; ll sum = 0, ans = 0;
  for (int l = 1; l <= n; l++) {
    while (r <= n and sum + a[r] < s) {
      sum += a[r];
      r++;
    }
    ans +=  n - r + 1;
    sum -= a[l];
  }
  cout << ans << '\n';

  return 0;
}