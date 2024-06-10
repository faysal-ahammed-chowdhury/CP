#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 2e9, N = 2e5 + 9, MAX_VAL = 2e5 + 9;
int a[N], freq[MAX_VAL];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  sort(a + 1, a + 1 + n);

  int ans = inf;
  for(int i = 1; i < MAX_VAL; i++) {
    int val = i, need = max(0, k - freq[i]);
    if(need == 0) {
      cout << 0 << '\n';
      return;
    }
    int tmp = 0;
    int x = 2, pw = 1;
    while(need > 0 && x < MAX_VAL) {
      int idx1 = lower_bound(a + 1, a + 1 + n, val * x) - a;
      int idx2 = upper_bound(a + 1, a + 1 + n, (val + 1) * x - 1) - a - 1;
      int cnt = max(0, idx2 - idx1 + 1);
      tmp += min(cnt, need) * pw;
      need -= cnt;
      x *= 2, pw++;
    }
    if(need <= 0) ans = min(ans, tmp);
  }
 
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  while(t--) {
    solve();
  }

  return 0;
}