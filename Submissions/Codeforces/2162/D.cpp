#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int query(int type, int l, int r) {
  cout << type << ' ' << l << ' ' << r << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  int sum1 = query(1, 1, n);
  int sum2 = query(2, 1, n);

  int len = abs(sum1 - sum2);

  // cout << len << endl;

  int l = 1, r = n, idx = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    int sum1 = query(1, 1, mid);
    int sum2 = query(2, 1, mid);
    if (sum1 != sum2) {
      idx = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  assert(idx != -1);

  cout << "! " << idx << ' ' << idx + len - 1 << endl;
}

int32_t main() {

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}