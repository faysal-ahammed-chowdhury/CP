#include <bits/stdc++.h>
using namespace std;

const int N = 109;
vector<bool> is_prime(N, true);
vector<int> primes;

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for(int i = 2; i <= lim; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int cs = 0;
void solve() {
  primes.clear();
  int n; cin >> n;
  for(int i = 2; i <= n; i++) {
    if(is_prime[i]) primes.push_back(i);
  }
  map<int, int> mp;
  for(auto i: primes) {
    int x = n;
    while(x) {
      mp[i] += x / i;
      x /= i;
    }
  }

  vector<pair<int, int>> ans;
  ans.push_back({-1, -1});
  for(auto i: mp) {
    ans.push_back({i.first, i.second});
  }

  cout << "Case " << ++cs << ": ";
  cout << n << " = ";

  int len = ans.size();
  for(int i = 1; i < len; i++) {
    cout << ans[i].first << " (" << ans[i].second << ")";
    if(i + 1 != len) cout << " * ";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}