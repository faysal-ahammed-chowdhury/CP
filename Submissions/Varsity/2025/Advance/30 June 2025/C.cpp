#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 9;
ll psum[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;
  for (int i = b; i <= c; i++) {
    int l = a + i, r = b + i;
    psum[l]++;
    psum[r + 1]--;
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    psum[i] += psum[i - 1];
    int cnt = i - c;
    if (i > d) cnt = d - c + 1;
    cnt = max(0, cnt);
    ans += 1ll * psum[i] * cnt;
  }

  cout << ans << '\n';

  return 0;
}