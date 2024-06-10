#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int unsigned long long
const int N = 2e5 + 9;
int n, x; 
int a[N];

bool ok(int h) {
  int used = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i] < h) {
      used += h - a[i];
    }
  }
  return used <= x;
}

void solve() {
  cin >> n >> x;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 0, r = 2e9, ans = -1;
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
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}