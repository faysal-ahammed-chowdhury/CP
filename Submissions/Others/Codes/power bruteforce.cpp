#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;
const ll inf = 1e18;
bool overflow;

ll power(int a, int b) {
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

  return 0;
}