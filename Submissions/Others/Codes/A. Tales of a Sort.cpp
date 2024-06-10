#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(is_sorted(a, a + n)) {
    cout << 0 << '\n';
    return;
  }
  int i;
  for(i = n - 2; i >= 0; i--) {
    if(a[i] > a[i + 1]) {
      break;
    }
  }
  int idx = i;
  int ans = -1;
  for(i = 0; i <= idx; i++) {
    ans = max(ans, a[i]);
  }
  cout << ans << '\n';
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