#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n, k, a[N];
char c[N];

bool ok(int distance) {
  for(int i = 1; i <= n; i++) {
    if(c[i] == '1') {
      continue;
    }
    // cout << i << ": ";
    int left = 0, right = 0;
    int range = max(i - distance, 1);
    if(range > 0) {
      left = a[i - 1] - a[range - 1];
    }
    // cout << left << ' ';
    range = min(i + distance, n);
    if(range <= n) {
      right = a[range] - a[i];
    }
    // cout << right << '\n';
    if((left + right) >= k) return true;
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
    if(c[i] == '0') {
      a[i] = 1;
    }
    else {
      a[i] = 0;
    }
  }

  for(int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int l = 0, r = 1e6, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}