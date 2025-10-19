#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>
typedef long long ll;
#define int long long

const int N = 105, inf = 1e9;
int a[N];

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 2; i <= n; i++) {
    ans = max(ans, abs(a[i] - a[i - 1]));
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