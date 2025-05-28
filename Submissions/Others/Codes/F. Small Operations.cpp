#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9, inf = 1e9;
vector<int> divs[N];
int x, y, k, dp[N]; 

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

int f(int n) {
  if (n == 1) return 0;
  int &ans = dp[n];
  if (ans != -1) return ans;
  ans = inf;
  for (auto d : divs[n]) {
    if (d > k) break;
    ans = min(ans, 1 + f(n / d));
  }
  return ans;
}

void solve() {
  cin >> x >> y >> k;
  int gc = __gcd(x, y);
  x /= gc, y /= gc;

  for (int i = 1; i <= max(x, y); i++) {
    dp[i] = -1;
  }
  int ans = f(x) + f(y);
  if (ans >= inf) ans = -1;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}