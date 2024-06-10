#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int a[n + 1], b[m + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  if(k & 1) {
    if(a[1] <= b[m]) {
      swap(a[1], b[m]);
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
      sum += a[i];
    }
    cout << sum << '\n';
  }
  else {
    if(a[1] <= b[m]) {
      swap(a[1], b[m]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    if(b[1] <= a[n]) {
      swap(b[1], a[n]);
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
      sum += a[i];
    }
    cout << sum << '\n';
  }
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