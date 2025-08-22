#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int inf = 1e18;
pair<int, int> cnt_cost[22];

int power(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
    if (ans > inf) {
      return -1;
    }
  }
  return ans;
}

int cost(int x) {
  int ans = power(3, x + 1);
  ans += x * power(3, x - 1);
  return ans;
}

void solve() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 20; i >= 0; i--) {
    int koybar = n / cnt_cost[i].first;
    ans += koybar * cnt_cost[i].second;

    n -= koybar * cnt_cost[i].first;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i <= 20; i++) {
    int a  = power(3, i);
    int b = cost(i);
    // double c = b / double(a);
    // cout << a << ' ' << b << ' ' << c << '\n';

    cnt_cost[i] = {a, b};
  }

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}