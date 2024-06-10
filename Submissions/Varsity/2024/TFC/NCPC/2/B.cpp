#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = a[n];
  n++; 

  int diff[n + 2];
  diff[1] = 0;
  for (int i = 2; i <= n; i++) {
    diff[i] = a[i] - a[i - 1];
  }


  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (diff[i] >= 20) {
      ans++;
      continue;
    }
    int taken = 1;
    int x = 0;
    while (i <= n and (x + diff[i] * taken) < 20) {
      // cout << diff[i] << '\n';
      x += diff[i] * taken;
      taken++; 
      i++;
    }
    ans++;
  }

  cout << ans << '\n';

  return 0;
}