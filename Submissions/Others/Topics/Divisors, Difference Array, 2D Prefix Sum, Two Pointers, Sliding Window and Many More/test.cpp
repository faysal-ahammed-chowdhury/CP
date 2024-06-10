#include<bits/stdc++.h>
using namespace std;

#define  ll  long long
#define lli long long int
#define ull unsigned ll
#define pb push_back
#define for1(i,n) for(ll i=0; i<n; i++)
#define for2(i,n) for(ll i=1; i<=n; i++)
#define for3(i,n) for(ll i=0;i<s.size(); i++)
#define fast()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));

//const ll N=1e5+2; //for segment tree
//ll a[N],tree[4*N]; //segment tree declared


const ll MOD = 1e9 + 7;
const ll BASE = 256;

ll N=100000001;
bool seive[100000001];

bool shihab()
{
    for(ll i=2; i<N; i++)seive[i]=true;

    for(ll i=2; i*i<N; i++)
    {
        if(seive[i]==true)
        {
            for(ll j=i*i; j<N; j+=i)
            {
                seive[j]=false;
            }
        }
    }
}


bool isPalindrome(const string &s) 
{
    int left = 0, right = s.size() - 1;
    while (left < right) 
    {
        if (s[left] != s[right]) 
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;

        if (isPalindrome(s) && k == 0)cout << "YES" << endl;
         
        else
        {
            unordered_map<char, ll> vec;
            
            for (char c : s) vec[c]++;

            ll sum = 0;
            
            for (auto& pair : vec) 
            {
                if (pair.second % 2 != 0) sum++;
            }

            //ll remove = (sum + 1) / 2; 
              cout << sum << '\n';
            if (k +1  >= sum  ) cout << "YES" << endl;
            else  cout << "NO" << endl;
        }
    }
}

