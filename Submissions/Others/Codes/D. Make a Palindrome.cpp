#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  int kth = b[k], tot = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= kth) {
      tot++;
    }
  }

  int l = 1, r = n, cnt = 0;
  while (l <= r) {
    if (a[l] > kth) {
      l++;
      continue;
    }
    if (a[r] > kth) {
      r--;
      continue;
    }
    if (a[l] == a[r]) {
      l++, r--;
      continue;
    }
    if (a[l] == kth) {
      cnt++, l++;
    }
    else if (a[r] == kth) {
      cnt++, r--;
    }
    else {
      cout << "NO\n";
      return;
    }
  }

  if (tot - cnt >= k - 1) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
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