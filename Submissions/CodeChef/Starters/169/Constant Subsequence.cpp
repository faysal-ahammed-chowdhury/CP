#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int n, a[N];
vector<int> pos, neg;

bool ok(ll mx) {
  int sz1 = pos.size(), sz2 = neg.size();
  int i = 0, j = 0;
  ll sum = 0;
  while (true) {
    sum = max(sum, 0ll);
    while (i < sz1 and sum + pos[i] <= mx) {
      sum += pos[i];
      i++;
    }
    if (j < sz2) {
      sum += neg[j];
      j++;
    }
    else if (i < sz1) return false;
    if (i >= sz1 and j >= sz2) break;
  }

  return true;
}

void solve() {
  pos.clear();
  neg.clear();
  cin >> n;  
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
  }

  if (pos.size() == 0) {
    cout << 0 << '\n';
    return;
  }

  int mx = *max_element(a + 1, a + n + 1);
  ll l = mx, r = 1e15, ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
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