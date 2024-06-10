#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9, inf = 1e9;
int n, a[N];

bool ok(int ans, int idx) {
  if(idx - ans + 1 > 0) {
    if(a[idx - ans + 1] / ans >= 1) return true;
    return false;
  }
  return false;
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    int l = 1, r = i, ans = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(ok(mid, i)) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}