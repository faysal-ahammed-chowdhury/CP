#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y; cin >> n >> x >> y;
  pair<int, int> a[n + 1];
  for (int i = 1; i <= n; i++) {
    if (x < y) cin >> a[i].first;
    else cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    if (y <= x) cin >> a[i].first;
    else cin >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  if (x > y) swap(x, y);
  int cnt = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    if (tot > x) break;
    cnt++;
    tot += a[i].first;
  }
  cout << cnt << '\n';

  return 0;
}