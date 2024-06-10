#include <bits/stdc++.h>
using namespace std;

const int N = 62, mod = 993344777;
int freq[N], mp[N], dp[N][(1 << 18) + 2][2][2];
vector<pair<int,int>>factors[61];

int fun(int i, int mask, int nisi, int even) {
  if (i == 61) {
    if (even) {
      return mask and nisi;
    }
    else {
      return !mask and nisi;
    }
  }

  int &ans = dp[i][mask][nisi][even];
  if (ans != -1) return ans;

  ans = fun(i + 1, mask, nisi, even);
  if (freq[i] > 0) {
    for (auto u : factors[i]) {
      int p = mp[u.first];
      int x = (mask & (1 << p)) > 0;
      int y = u.second;
      int z = (x + y) % 2;

      if (z == 1) {
        mask |= (1 << p);
      }
      else {
        mask &= (~(1 << p));
      }
    }

    ans += (1LL * fun(i + 1, mask, 1, (even + 1) % 2) * freq[i]) % mod;
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  mp[2] = 0;
  mp[3] = 1;
  mp[5] = 2;
  mp[7] = 3;
  mp[11] = 4;
  mp[13] = 5;
  mp[17] = 6;
  mp[19] = 7;
  mp[23] = 8;
  mp[29] = 9;
  mp[31] = 10;
  mp[37] = 11;
  mp[41] = 12;
  mp[43] = 13;
  mp[47] = 14;
  mp[51] = 15;
  mp[53] = 16;
  mp[59] = 17;

  for (int i = 2; i <= 60; i++) {
    int k = i;
    for (int j = 2; j <= 60; j++) {
      int c = 0;
      while ( k % j == 0) {
        c++;
        k /= j;
      }
      if (c) factors[i].push_back({j, c});
    }
  }


  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    freq[x]++;
  }


  memset(dp, -1, sizeof(dp));
  cout << fun(1, 0, 0, 0) << '\n';

  return 0;
}