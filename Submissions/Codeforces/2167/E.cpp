#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
pair<int, int> a[N];
int n, k, x;

bool ok(int d) {
  int need = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (a[i].first - d >= 0) {
        int cnt = a[i].first - d + 1;
        need += cnt;
      }

      if (i + 1 <= n) {
        if ((a[i].first + d) <= (a[i + 1].first - d)) {
          int cnt = (a[i + 1].first - d) - (a[i].first + d) + 1;
          need += cnt;
        }
      }
    }
    if (i == n) {
      if (a[i].first + d <= x) {
        int cnt = x - (a[i].first + d) + 1;
        need += cnt;
      }
      continue;
    }

    if (i == 1) continue;

    if ((a[i].first + d) <= (a[i + 1].first - d)) {
      int cnt = (a[i + 1].first - d) - (a[i].first + d) + 1;
      need += cnt;
    }
  }

  return need >= k;
}

void print(int d) {
  int tmp = 1;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (a[i].first - d >= 0) {
        int cnt = a[i].first - d + 1;
        for (int j = 0; tmp <= k and j <= a[i].first - d; j++, tmp++) {
          cout << j << ' ';
        }
      }

      if (i + 1 <= n) {
        if ((a[i].first + d) <= (a[i + 1].first - d)) {
          int cnt = (a[i + 1].first - d) - (a[i].first + d) + 1;
          for (int j = a[i].first + d; tmp <= k and j <= (a[i + 1].first - d); j++, tmp++) {
            cout << j << ' ';
          }
        }
      }
    }
    if (i == n) {
      if (a[i].first + d <= x) {
        int cnt = x - (a[i].first + d) + 1;
        for (int j = (a[i].first + d); tmp <= k and j <= x; j++, tmp++) {
          cout << j << ' ';
        }
      }
      continue;
    }

    if (i == 1) continue;

    if ((a[i].first + d) <= (a[i + 1].first - d)) {
      int cnt = (a[i + 1].first - d) - (a[i].first + d) + 1;
      for (int j = a[i].first + d; tmp <= k and j <= (a[i + 1].first - d); j++, tmp++) {
        cout << j << ' ';
      }
    }
  }

  assert(tmp >= k);
}


void solve() {
  cin >> n >> k >> x;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    se.insert(a[i].first);
  }
  sort(a + 1, a + n + 1);

  int rem = (x + 1) - se.size();

  bool here = (x + 1) == k;
  here |= rem < k;

  if (here) {
    for (int j = 0, i = 1; i <= k and j <= x; j++, i++) {
      cout << j << ' ';
    }
    cout << '\n';
    return;
  }

  int l = 1, r = x, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  assert(ans != 0);

  // cout << ans << '\n';
  print(ans);
  cout << '\n';
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