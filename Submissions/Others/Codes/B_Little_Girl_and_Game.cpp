#include <bits/stdc++.h>
using namespace std;

#define pb(v) push_back(v)
#define ll long long
#define mod 1000000007
#define PI double(2 * acos(0.0))

bool winner = 0;
int start, end;

string remove(string s, int pos)
{
    string ns = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
            continue;
        ns += s[i];
    }
    return ns;
}

bool isPalindrome(string &s)
{
    int len = s.length();
    int i = 0, j = len - 1;
    while (i < j)
    {

        if (s[i] != s[j])
        {
            start = i, ::end = j;
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve()
{
    string s, s1, s2;
    cin >> s;

    while (!isPalindrome(s))
    {
        winner = !winner;
        bool ch = false, ch2 = false;

        int i = start, j = ::end;

        if (abs(i - j) == 1)
        {
            s = remove(s, j);
        }
        if (s[i] == s[j - 1])
        {
            s1 = remove(s, j);
            ch = true;
        }
        if (s[i + 1] == s[j])
        {
            s2 = remove(s, i);
            ch2 = true;
        }

        if (!ch && !ch2)
        {
            s = remove(s, j);
        }
        else if (ch && ch2)
            if (isPalindrome(s1))
                s = s1;
            else
                s = s2;
        else if (ch)
            s = s1;
        else
            s = s2;

        // cout << s << endl;
    }

    if (winner == 0)
        cout << "First\n";
    else
        cout << "Second\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
