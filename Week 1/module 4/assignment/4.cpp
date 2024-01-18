// #include <bits/stdc++.h>
// using namespace std;

// int bnSearch1(vector<int> &v, int k)
// {
//     int l = 0;
//     int r = v.size() - 1;
//     int cnt = -1;
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (v[mid] == k)
//         {
//             cnt++;
//             r = mid - 1;
//         }
//         else if (v[mid] < k)
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }

//     return cnt;
// }
// int bnSearch2(vector<int> &v, int k)
// {
//     int l = 0;
//     int r = v.size() - 1;
//     int cnt = -1;
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (v[mid] == k)
//         {
//             cnt++;
//             l = mid + 1;
//         }
//         else if (v[mid] < k)
//         {
//             l = mid + 1;
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }

//     return cnt;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     int k;
//     cin >> k;
//     int c1 = bnSearch1(v, k);
//     int c2 = bnSearch2(v, k);
//     if ((c2 - c1) > 0)
//         cout << "yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }

#include <iostream>
using namespace std;
int cnt = 0;
int binary_searc(int arr[], int l, int h, int k)
{
    if (l > h || h < l)
    {
        return cnt;
    }
    int mid = (l + h) / 2;
    if (arr[mid] == k)
    {
        cnt++;
        binary_searc(arr, l, mid - 1, k);
        binary_searc(arr, mid + 1, h, k);
    }
    else if (arr[mid] < k)
    {
        l = mid + 1;
        binary_searc(arr, l, h, k);
    }
    else
    {
        h = mid - 1;
        binary_searc(arr, l, h, k);
    }

    return cnt;
}
int main()
{
    int n, l = 0, h, k;
    cin >> n;
    int arr[n];

    h = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int result = binary_searc(arr, l, h, k);
    if (result > 1)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}