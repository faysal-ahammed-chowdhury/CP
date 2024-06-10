#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 2e5 + 9;
vector<bool> is_prime(N, 0);

void sieve() {
  for(int i = 2; i < N; i++)
  is_prime[i] = 1;
  for(int i = 2; i < N; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

void solve() {
  int n; cin >> n;
  int a[n + 1], ans [n + 1];
  for(int i = 1; i <= n; i++) {
    a[i] = i;
    ans[i] = i;
  }
  int mx = 0;
  do {
    int primality = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = i; j <= n; j++) {
        vector<int> v;
        for(int k = i; k <= j; k++) {
          v.push_back(a[k]);
        }
        sort(v.begin(), v.end());
        int mex = 1;
        for(auto k: v) {
          if(k == mex) {
            mex++;
          }
        }
        if(is_prime[mex]) primality++;
        if(primality > mx) {
          mx = primality;
          for(int i = 1; i <= n; i++) {
            ans[i] = a[i];
          }
        }
      }
    }
  } while(next_permutation(a + 1, a + n + 1));


  cout << mx << ' ';
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  int t; cin >> t;
  while(t--) {
    solve();
  }
        
  return 0;
}