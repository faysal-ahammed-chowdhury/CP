#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long

bool ok(int &n, int &c, int a[], int &distance) {
  int cnt = 0, now = a[1], idx = 1;
  while(idx <= n) {
    cnt++;
    if(cnt >= c) {
      return true;
    }
    now = a[idx];
    int next = now + distance;
    auto it = lower_bound(a + 1, a + 1 + n, next);
    idx = it - &a[1] + 1;
  }
  return cnt >= c;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int c; cin >> c;
    int l = 1, r = 1e10, ans = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(ok(n, c, a, mid)) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    cout << max(0LL, ans) << '\n';
  }

  return 0;
}