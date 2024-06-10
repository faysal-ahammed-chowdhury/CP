#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> odd;
  vector<int> even;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    if(x % 2 == 0) {
      even.push_back(x);
    }
    else {
      odd.push_back(x);
    }
  }
  
  sort(even.begin(), even.end());
  reverse(even.begin(), even.end());
  sort(odd.begin(), odd.end());
  reverse(odd.begin(), odd.end());

  long long sum = 0;
  for(auto i: even) {
    sum += i;
  }
  for(auto i: odd) {
    sum += i;
  }

  if(odd.size() % 2 == 1) {
    sum -= odd[odd.size() - 1];
  }
  cout << sum << '\n';

  return 0;
}