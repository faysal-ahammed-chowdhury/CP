#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int n, k, a[N], b[N], c[N], diff[4 * N];
vector<int> v;

int get(int x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

ll f(int price) {
  ll ans = 0;
  if (diff[get(price)] <= k) {
    int x = lower_bound(c + 1, c + n + 1, price) - &c[1];
    x = n - x;
    ans = 1ll *  price * x;
  }
  return ans;
}

void solve() {
  v.clear();

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
    v.push_back(a[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    v.push_back(b[i]);
    v.push_back(b[i] + 1);
    c[i] = b[i];
  }

  sort(c + 1, c + n + 1);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  for (int i = 1; i <= v.size(); i++) {
    diff[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    diff[get(a[i]) + 1]++;
    diff[get(b[i]) + 1]--;
  }
  for (int i = 1; i <= v.size(); i++) {
    diff[i] += diff[i - 1];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f(a[i]));
    ans = max(ans, f(a[i] + 1));
    ans = max(ans, f(b[i]));
    ans = max(ans, f(b[i] + 1));
  }

  cout << ans << '\n';
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