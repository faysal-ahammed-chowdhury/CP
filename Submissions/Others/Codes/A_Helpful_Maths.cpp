#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[4] = {0};
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            arr[str[i] - '0']++;
    }

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            str[count] = char(i + '0');
            count++;
            str[count] = '+';
            count++;
        }
    }

    cout << str << endl;

    return 0;
}
