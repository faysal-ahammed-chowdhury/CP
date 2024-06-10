#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(ll x) const { return x ^ RANDOM; }
};

void fun (int i, int a[], int n, vector<ll> &v, ll sum) {
  if (i == n) {
    v.push_back(sum);
    return;
  }
  fun(i + 1, a, n, v, sum);
  fun(i + 1, a, n, v, sum + a[i]);
  fun(i + 1, a, n, v, sum + a[i] + a[i]);
}

int cs;
void solve() {
  int n, k; cin >> n >> k;
  int x = (n / 2);
  int y = (n - x);

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

  cout << "Case " << ++cs << ": ";
  for (auto val : v2) {
    ll need = k - val;

    bool got = (upper_bound(v1.begin(), v1.end(), need) - lower_bound(v1.begin(), v1.end(), need)) > 0;
    if (got) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
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