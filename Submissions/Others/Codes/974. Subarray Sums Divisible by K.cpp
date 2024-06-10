#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<long long> nums(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  for(int i = 1; i <= n; i++) {
    nums[i] += nums[i - 1];
  }
  
  map<int, int> mp;
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    int x = ((nums[i] % k) + k) % k;
    ans += (mp[x]);
    if(nums[i] % k == 0) ans++;
    mp[x]++;
  }
  cout << ans << '\n';

  return 0;
}