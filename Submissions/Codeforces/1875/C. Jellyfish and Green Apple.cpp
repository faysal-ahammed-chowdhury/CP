#include <bits/stdc++.h>
using namespace std;

double eps = 1e-12;

void solve() {
  int n, m; cin >> n >> m;
  double avg = (double) n / m;
  int rem = n % m;
  if(rem == 0) {
    cout << 0 << '\n';
    return;
  }
  avg -= (int) avg;

  int x = m / (__gcd(n, m));
  if(!((x & (x - 1)) == 0)) {
    cout << -1 << '\n';
    return;
  }

  double apple = 1;
  long long ans = 0, add = 0, pw = 1;
  while(apple >= eps) {
    if(avg == 0) {
      break;
    }
    if(apple <= avg) {
      int need = apple * m;
      avg -= apple;
      rem -= need;
      ans += add * need;
    }
    apple /= 2;
    add += pw;
    pw *= 2;
  }
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