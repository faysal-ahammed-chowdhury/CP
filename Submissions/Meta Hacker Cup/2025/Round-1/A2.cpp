#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>
typedef long long ll;
#define int long long

const int N = 500000 + 20, inf = 1e9;
int a[N];
bool vis[N];
int n; 

bool ok(int len) {
  vector<int> v;
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= len) {
      v.push_back(i);
      vis[i] = true;
    }
  }

  for (auto i : v) {
    int j = i - 1;
    while (true) {
      if (j == 0) break;
      if (vis[j]) break;
      int d = abs(a[j] - a[j + 1]);
      if (d <= len) {
        vis[j] = true;
        j--;
      }
      else break;
    }

    j = i + 1;
    while (true) {
      if (j > n) break;
      if (vis[j]) break;
      int d = abs(a[j] - a[j - 1]);
      if (d <= len) {
        vis[j] = true;
        j++;
      }
      else break;
    }
  }

  bool ok2 = true;
  for (int i = 1; i <= n; i++) {
    ok2 &= vis[i];
  }

  return ok2;
}

int cs;
void solve() {
  cin >> n;
  int mn = inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }

  int l = 0, r = inf, ans = mn;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  
  cout << "Case #" << ++cs << ": " << ans << '\n';
}

int32_t main() {
  rlimit rlim;
  if (getrlimit(RLIMIT_STACK, &rlim)) return 1;
  rlim.rlim_cur = rlim.rlim_max;
  // You can set the fixed value instead of max value, e.g. rlim.rlim_cur = 1024 * 1024 * 1024
  // will set your stack size to 1 GiB
  if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}