#include <bits/stdc++.h>
using namespace std;

#define i128 __int128
#define int long long

const int inf = 1e18;
bool overflow;

int power(int a, int b) {
  i128 ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
    if (ans > inf) {
      overflow = true;
      return -1;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v;
  int x, y, l, r; cin >> x >> y >> l >> r;
  for (int i = 0; i <= 60; i++) {
    for (int j = 0; j <= 60; j++) {
      overflow =  false;
      int p1 = (power(x, i));
      int p2 = (power(y, j));
      int val = p1 + p2;
      if ((i128)p1 + (i128)p2 > inf) overflow = true;
      if (!overflow and val >= l and val <= r) {
        v.push_back(val);
      }
    }
  }

  v.push_back(l - 1);
  v.push_back(r + 1);
  sort(v.begin(), v.end());
  int n = v.size();
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, v[i] - v[i - 1] - 1);
  }
  cout << ans << '\n';

  return 0;
}