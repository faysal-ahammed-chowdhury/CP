#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
const int N = 2e5 + 9;
int n, k, a[N];

bool ok(int mn) {
  int cost = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < mn) {
      cost += mn - a[i];
    }
  }
  return cost <= k;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = 1e15, ans = -1;
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
  int possible = (ans * n) - (n - 1);
  int rem = k;
  for (int i = 1; i <= n; i++) {
    if (a[i] < ans) {
      rem -= ans - a[i];
      a[i] = ans;
    }
  }

  int extra = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > ans) {
      extra++;
    }
    else if (rem > 0 and a[i] == ans) {
      extra++;
      rem--;
    }
  }

  possible += extra;
  cout << possible << '\n';
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