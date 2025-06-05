#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 11;
int fibo[N];

void solve() {
  int n, m; cin >> n >> m;
  string ans = "@";
  for (int i = 1; i <= m; i++) {
    ans.push_back('0');
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c; cin >> a >> b >> c;

    if (n == 1) {
      ans[i] = '1';
      break;
    }

    for (int j = n; j >= 1; j--) {
      if (a < b) swap(a, b);
      if (min({a, b, c}) < fibo[j]) {
        break;
      }
      if (min(a, b) >= fibo[j] and c >= fibo[j] + (j > 1 ? fibo[j - 1] : 0)) {
        ans[i] = '1';
        break;
      }
      else {
        a -= fibo[j];
      }
    }
  }

  cout << ans.substr(1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fibo[1] = 1;
  fibo[2] = 2;
  for (int i = 3; i < N; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}