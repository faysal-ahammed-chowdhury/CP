#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void fun (int i, int a[], int n, vector<ll> &v, ll sum) {
  if (i == n) {
    v.push_back(sum);
    return;
  }
  fun(i + 1, a, n, v, sum);
  fun(i + 1, a, n, v, sum + a[i]);
}

int cs;
void solve() {
  int n, W; cin >> n >> W;
  int x = n / 2;
  int y = n - x;

  int a[x], b[y];
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }

  vector<ll> v1, v2;
  fun(0, a, x, v1, 0);
  fun(0, b, y, v2, 0);
  sort(v1.begin(), v1.end());

  ll ans = 0;
  for (auto val : v2) {
    ll need = W - val;
    int idx = upper_bound(v1.begin(), v1.end(), need) - v1.begin();
    ans += idx;
  }

  cout << "Case " << ++cs << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}