#include <bits/stdc++.h>
using namespace std;

#define int long long
int lo, hi;

bool ok(int n) {
  int sum = (n * (n + 1)) / 2;
  return lo + sum <= hi;
} 

void solve() {
  cin >> lo >> hi;
  int l = 0, r = 44725, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ++ ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}