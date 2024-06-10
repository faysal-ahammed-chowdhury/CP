#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;
long long is_prime[N], ans[N];

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

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sieve();

  for(int i = 2; i < N; i++) {
    if(i % 2 == 0 && i != 2) {
      ans[i] = 2;
    }
    else if(is_prime[i]) {
      ans[i] = 1;
    }
    else if(is_prime[i - 2]) {
      ans[i] = 2;
    }
    else {
      ans[i] = 3;
    }
  }

  for(int i = 2; i < N; i++) {
    ans[i] += ans[i - 1];
    // cout << i << ' ' << ans[i] << '\n';
  }

  int q; cin >> q;
  while(q--) {
    int x; cin >> x;
    cout << ans[x] << '\n';
  }

  return 0;
}