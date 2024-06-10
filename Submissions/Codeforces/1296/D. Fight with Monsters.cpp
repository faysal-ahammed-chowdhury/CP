#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, k; cin >> n >> a >> b >> k;
  vector<int> vec;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int rem = (x % (a + b));
    if (rem != 0 and rem <= a) ans++;
    else if (rem == 0) {
      rem += b;
      vec.push_back((rem + a - 1) / a);
    }
    else {
      rem -= a;
      vec.push_back((rem + a - 1) / a);
    }
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size() and k > 0; i++) {
    if (vec[i] <= k) ans++; k -= vec[i];
  }
  cout << ans << '\n';

  return 0;
}