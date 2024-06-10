#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int n, k, a[N], pref[N], st, en; 

bool ok(int claim) {
  for (int i = 1; i + claim - 1 <= n; i++) {
    int cnt = pref[i + claim - 1] - pref[i - 1];
    int need = claim - cnt;
    if (need <= k) {
      st = i, en = i + claim - 1;
      return true;
    }
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = a[i];
    pref[i] += pref[i - 1];
  }

  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  ok(ans);
  int cnt = pref[en] - pref[st - 1];
  int need = (en - st + 1) - cnt;
  int fill_cnt = min(need, k);
  for (int i = st; i <= en and fill_cnt; i++) {
    if (a[i] == 0) {
      a[i] = 1;
      fill_cnt--;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}