#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLEAR(int &N, int pos) { (N &= ~(1ll << pos)); }

int n, a, b;
int arr[7], dp[100];

int f(int mask) { // bit on = baki
  // cout << mask << '\n';
  if (__builtin_popcount(mask) == 0) return 0;
  int &ans = dp[mask];
  if (ans != -1) return ans;
  ans = 100;
  for (int submask = mask; submask; submask = (submask - 1) & mask) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
      if (CHECK(submask, i)) sum += arr[i];
    }
    if (sum <= n) {
      int new_mask = mask;
      for (int i = 0; i < 6; i++) {
        if (CHECK(submask, i)) CLEAR(new_mask, i);
      }
      ans = min(ans, 1 + f(new_mask));
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a >> b;
  arr[0] = a;
  arr[1] = a;
  arr[2] = a;
  arr[3] = a;
  arr[4] = b;
  arr[5] = b;

  memset(dp, -1, sizeof dp);
  cout << f((1 << 6) - 1) << '\n';

  return 0;
}