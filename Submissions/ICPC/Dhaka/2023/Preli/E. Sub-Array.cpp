#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 1ll * n * (n + 1) / 2;
  vector<int> vec;
  int last = a[1], cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == last) {
      cnt++;
    }
    else {
      vec.push_back(cnt);
      cnt = 1;
    }
    last = a[i];
  }

  vec.push_back(cnt);

  for (auto x : vec) {
    ans -= 1ll * x * (x + 1) / 2;
  }
  cout << "Case " << ++cs << ": ";
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