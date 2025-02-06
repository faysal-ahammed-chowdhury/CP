#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, l, r; cin >> n >> l >> r;
  vector<int> v1, v2;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (i <= r) v1.push_back(x);
    if (i >= l) v2.push_back(x);
  }

  int len = r - l + 1;
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  long long sum1 = 0, sum2 = 0; 
  for (int i = 0; i < len; i++) {
    sum1 += v1[i];
    sum2 += v2[i];
  }

  cout << min(sum1, sum2) << '\n';
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