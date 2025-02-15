#include <bits/stdc++.h>
using namespace std;

const int N = 1200009, MAX = 1e6 + 9;
int multiple[MAX], cnt[MAX], a[N];
vector<int> divs[MAX];
int dp[N];

void sieve() {
  for (int i = 1; i < MAX; i++) {
    divs[i].push_back(1);
    multiple[1] += cnt[i];
  }
  for (int i = 2; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      multiple[i] += cnt[j];
      divs[j].push_back(i);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sieve();

  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    int val = a[i];
    if (dp[val] != -1) cout << dp[val] << '\n';
    else {
      int ans = 1;
      for (auto x : divs[val]) {
        if (multiple[x] >= k) ans = max(ans, x);
      }
      dp[val] = ans;
      cout << ans << '\n';
    }
  }


  return 0;
}