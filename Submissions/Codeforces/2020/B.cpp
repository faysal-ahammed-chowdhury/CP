#include <bits/stdc++.h>
using namespace std;

#define int __int128

long long k;

bool ok(int n) {
  int sq = sqrtl(n);
  while (sq * sq < n) sq++;
  while (sq * sq > n) sq--;
  int possible = n - sq;
  return possible >= k;
}

void print(__int128 x) {
  if (x > 9) print(x / 10);
  cout << char((x % 10) + '0');
}


void solve() {
  cin >> k;
  int l = k, r = 1e20, ans = -1;
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
  print(ans);
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}