#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
ll n, a[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<pair<ll, int>> st;
  for (int i = 1; i <= n; i++) {
    ll sum = a[i], cnt = 1;
    while (!st.empty() and st.top().first > sum / cnt) {
      // cout << "there:" << i << '\n';
      sum += st.top().first * st.top().second;
      cnt += st.top().second;
      st.pop();
    }
    // cout << "Here:\n";
    // cout << "SUM : " << sum << '\n';
    // cout << "CNT : " << cnt << '\n';
    // cout << i << ' ' << sum / cnt << ' ' << cnt - sum % cnt << '\n';
    st.push({sum / cnt, cnt - (sum % cnt)});
    if (sum % cnt != 0) {
      // cout << "Not divisible: " << sum / cnt + 1 << ' ' << sum % cnt << '\n';
      st.push({(sum / cnt) + 1, sum % cnt});
    }
  }
  ll mx = st.top().first;
  while (st.size() > 1) st.pop();
  cout << mx - st.top().first << '\n';
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