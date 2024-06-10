#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e4 + 9;
int n, c, a[N];

bool ok(int distance) {
  int cnt = 0, last = a[1];
  for(int i = 2; i <= n; i++) {
    if(a[i] - last >= distance) {
      cnt++;
      last = a[i];
    }
    if(cnt + 1 >= c) return true;
  }
  return cnt + 1 >= c;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    cin >> c;
    int l = 1, r = abs(a[1] - a[n]), ans = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      if(ok(mid)) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    cout << max(0, ans) << '\n';
  }

  return 0;
}