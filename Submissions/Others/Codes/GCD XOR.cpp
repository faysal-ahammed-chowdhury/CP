#include <bits/stdc++.h>
using namespace std;

const int N = 30000005;
int ans[N];

void prec() {
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      if (j - i == (i ^ j)) {
        ans[j]++;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    ans[i] += ans[i - 1];
  }
}

int cs;
void solve() {
  int n; cin >> n;
  cout << "Case " << ++cs << ": " << ans[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}