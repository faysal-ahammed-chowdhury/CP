#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0, pos = 1, i, j;
  while (pos <= n) {
    i = pos, j = pos;
    while (i + 1 <= n and a[i] <= a[i + 1]) i++; 
    while (i + 1 <= n and a[j] >= a[j + 1]) j++; 
    ans++;
    pos = max(i, j) + 1;
  }
  cout << ans << '\n';

  return 0;
}