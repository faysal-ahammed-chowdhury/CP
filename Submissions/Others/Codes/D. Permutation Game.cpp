#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int n, k, s1, s2, a[N], p[N];

ll get_score(int i, int rem_k) {
  vector<bool> vis(n + 5, false);
  ll mx = 0, cur = 0;
  while (vis[i] == false and rem_k > 0) {
    vis[i] = true;
    mx = max(mx, cur + (1ll * a[i] * rem_k));
    cur += a[i];
    rem_k--;
    i = p[i];
  }
  return mx;
}

void solve() {
  cin >> n >> k >> s1 >> s2;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll score1 = get_score(s1, k);
  ll score2 = get_score(s2, k);

  if (score1 == score2) {
    cout << "Draw\n";
  }
  else if (score1 > score2) {
    cout << "Bodya\n";
  }
  else {
    cout << "Sasha\n";
  }
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