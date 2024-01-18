#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n;

    vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    cin >> m;

    vector<int> v2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    int i = 0, j = 0, k = 0;
    vector<int> nums(n + m);

    while (i < n && j < m)
    {
        if (v1[i] >= v2[j])
        {
            nums[k] = v1[i];
            i++;
        }
        else
        {
            nums[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        nums[k] = v1[i];
        i++;
        k++;
    }

    while (j < m)
    {
        nums[k] = v2[j];
        j++;
        k++;
    }

    for (int val : nums)
        cout << val << " ";

    return 0;
}
