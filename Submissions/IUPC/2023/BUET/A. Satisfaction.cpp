#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
int n, a[N];
string s;
bitset<N> take;

void solve() {
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    take[i] = 0;
  }
  s = '.' + s;

  int cntst_cnt = 0;
  for (auto c : s) {
    cntst_cnt += c == 'C';
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'P' and cntst_cnt > 0) {
      take[i] = 1;
      cntst_cnt--;
    }
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'C') pq.push(a[i]);
    else if (take[i]) {
      ans += 1ll * a[i] * pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}