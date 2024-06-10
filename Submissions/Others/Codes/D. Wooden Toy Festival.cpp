#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, a[N];

bool ok(int time) {
  int pos = 1, st = 1;
  while (pos <= n and a[pos] <= a[st] + (time * 2)) {
    pos++;
  }
  if (pos > n) return true;
  st = pos;
  while (pos <= n and a[pos] <= a[st] + (time * 2)) {
    pos++;
  }
  if (pos > n) return true;
  st = pos;
  while (pos <= n and a[pos] <= a[st] + (time * 2)) {
    pos++;
  }
  return pos > n;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + 1 + n);

  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}