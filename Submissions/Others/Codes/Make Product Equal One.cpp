#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int cnt = 0, cnt0 = 0;
  long long op = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 0) {
      cnt0++;
    }
    else if (x > 0) {
      op += abs(x - 1);
    }
    else {
      cnt++;
      op += abs(x + 1);
    }
  }

  if (cnt & 1) {
    if (cnt0) {
      cnt0--;
      op++;
    }
    else {
      op += 2;
    }
  }
  op += cnt0;
  cout << op << '\n';

  return 0;
}