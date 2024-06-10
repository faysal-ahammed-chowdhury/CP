#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
vector<bool> is_prime(N, true);
vector<int> ans(N, 0);

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

bool has_zero(int n) {
  while(n > 0) {
    if(n % 10 == 0) return true;
    n /= 10;
  }
  return false;
}

int get_len(int n) {
  int cnt = 0;
  while(n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}

bool afraid(int n) {
  if(!is_prime[n]) return false;
  int len = get_len(n);
  if(len == 1) {
    return is_prime[n];
  }
  int new_n = n % int(pow(10, len - 1));
  return afraid(new_n);
}

void solve() {
  int n; cin >> n;
  cout << ans[n] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  for(int i = 2; i < N; i++) {
    ans[i] = ans[i - 1];
    if(is_prime[i] && !has_zero(i) && afraid(i)) {
      ans[i]++;
    }
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}