#include <bits/stdc++.h>
using namespace std;

int count_trailing_zero(int n) {
  int cnt = 0;
  while(n) {
    cnt += n / 5;
    n /= 5;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int q; cin >> q;
    int l = 0, r = 5 * q, ans = -1;
    while(l <= r) {
      int mid = (l + r) / 2;
      int trailing_zero = count_trailing_zero(mid);
      if(trailing_zero == q) {
        ans = mid;
        r = mid - 1;
      }
      else if(trailing_zero > q) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    cout << "Case " << ++cs << ": ";
    if(ans == -1) {
      cout << "impossible\n";
    }
    else {
      cout << ans << '\n';
    }
  }

  return 0;
}