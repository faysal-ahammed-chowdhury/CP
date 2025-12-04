#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
void solve() {
  int n; cin >> n;
  vector<int> ans;
  bool vis[n + 1];
  memset(vis, false, sizeof vis);
  for (auto p : primes) {
    if (p > n) break;
    vector<int> v;
    for (int i = p; i <= n; i += p) {
      if (!vis[i]) {
        v.push_back(i);
      }
      if (v.size() == 2) {
        ans.push_back(0);
        ans.push_back(v[0]);
        ans.push_back(v[1]);
        vis[v[0]] = true;
        vis[v[1]] = true;
        v.clear();
      }
    }
  }

  set<int> se;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) se.insert(i);
  }

  int cnt = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 0) {
      if (!se.empty()) {
        cout << *se.begin() << ' ';
        se.erase(se.begin());
        cnt++;
      }
    }
    else {
      cout << ans[i] << ' ';
      cnt++;
    }
  }
  while (!se.empty()) {
    cout << *se.begin() << ' ';
    se.erase(se.begin());
    cnt++;
  }
  cout << '\n';
  assert(cnt == n);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}