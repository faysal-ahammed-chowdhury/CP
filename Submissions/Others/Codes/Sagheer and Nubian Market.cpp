#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 9;
int n, S, a[N];
ll tot_cost;

bool ok(int k) {
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(a[i] + (1ll * i * k));
  }
  sort(v.begin(), v.end());
  ll cost = 0;
  for (int i = 0; i < k; i++) {
    cost += v[i];    
  }
  tot_cost = cost;
  return cost <= S;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> S;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 0, r = n, cnt = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      cnt = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  ok(cnt);
  cout << cnt << ' ' << tot_cost << '\n';

  return 0;
}