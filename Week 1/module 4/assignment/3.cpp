#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &vec, int l, int r, int mid)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = vec[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right[j] = vec[mid + 1 + j];
    }

    // Merge both subarrays
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        mergesort(vec, l, mid);
        mergesort(vec, mid + 1, r);
        merge(vec, l, r, mid);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    mergesort(vec, 0, vec.size() - 1);

    for (int i = 1; i < n; i++)
    {
        if (vec[i] != vec[i + 1])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    // for (int val : vec)
    //     cout << val << " ";

    return 0;
}
