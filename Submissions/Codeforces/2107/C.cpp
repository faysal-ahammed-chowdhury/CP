#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, inf = 5e18, INF = 1e13;
int n, k, a[N];

void solve() {
  cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int cnt = 0, idx = -1;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (s[i] == '0') {
      cnt++;
      a[i] = -INF;
      if (idx == -1) idx = i;
    }
  }

  int ans = -inf;
  int low = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    ans = max(ans, sum - low);
    low = min(low, sum);
  }

  if (ans == k) {
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  if (ans > k or cnt == 0) {
    cout << "No\n";
    return;
  }

  int sum1 = 0;
  for (int i = 1; i < idx; i++) {
    sum1 += a[i];
    sum1 = max(0ll, sum1);
  }

  int sum2 = 0;
  for (int i = n; i > idx; i--) {
    sum2 += a[i];
    sum2 = max(0ll, sum2);
  }

  sum = sum1 + sum2;
  int need = k - sum;
  a[idx] = need;
  cout << "Yes\n";
  for (int j = 1; j <= n; j++) {
    cout << a[j] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}