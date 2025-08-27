#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  multiset<int, greater<int>> ms;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ms.insert(a[i] + i - 1);
  }

  int ans = *ms.begin();
  int cur = n - 1;
  // for (auto x : ms) cout << x << ' '; cout << '\n';
  for (int i = 2; i <= n; i++) {
    int prv_before = a[i - 1];
    int prv_now = a[i - 1] + cur--;
    ms.erase(ms.find(prv_before));
    ms.insert(prv_now);

    int me_before = a[i] + (i - 1);
    int me_now = a[i];
    ms.erase(ms.find(me_before));
    ms.insert(me_now);

    // cout << i << ": ";
    // for (auto x : ms) cout << x << ' '; cout << '\n';

    ans = min(ans, *ms.begin());
  }

  cout << ans << '\n';

  return 0;
}