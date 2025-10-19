#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>
typedef long long ll;
#define int long long

int cs;
void solve() {
  int n, a, b; cin >> n >> a >> b;
  cout << "Case #" << ++cs << ": ";
  for (int i = 1; i < n + n; i++) {
    cout << 1 << ' ';
  }
  cout << b << '\n';
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