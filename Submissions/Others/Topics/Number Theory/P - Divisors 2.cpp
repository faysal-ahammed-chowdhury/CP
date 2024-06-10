#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> divisor(N + 1, 1);
vector<bool> ans(N + 1, true);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 2; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      divisor[j]++;
    }
  }

  for(int i = 2; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      if(divisor[j] % divisor[i] != 0) {
        ans[j] = false;
      }
    }
  }

  int cnt = 0;
  for(int i = 1; i <= N; i++) {
    if(divisor[i] > 3 && ans[i]) {
      cnt++;
      if(cnt % 108 == 0) {
        cout << i << '\n';
      }
    }
  }

  return 0;
}
