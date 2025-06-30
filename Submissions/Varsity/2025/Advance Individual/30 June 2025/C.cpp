#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 9;
ll psum[N];

void print(__int128 x) {
  string s = "";
  while (x > 0) {
    s += (x % 10) + '0';
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d; cin >> a >> b >> c >> d;
  for (int i = b; i <= c; i++) {
    int l = a + i, r = b + i;
    psum[l]++;
    psum[r + 1]--;
  }

  __int128 ans = 0;
  for (int i = 0; i < N; i++) {
    psum[i] += psum[i - 1];
    // cout << i << ' ' << psum[i] << '\n';
    int cnt = i - c;
    if (i > d) cnt = d - c + 1;
    cnt = max(0, cnt);
    ans += (__int128)psum[i] * cnt;
  }

  print(ans);

  return 0;
}