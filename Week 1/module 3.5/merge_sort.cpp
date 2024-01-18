#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &num, int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int right_size = r - mid;

    vector<int> left(left_size);
    vector<int> right(right_size);

    int k = 0;
    for (int i = 0; i < left_size; i++)
    {
        left[i] = num[l + i];
    }
    for (int j = 0; j < right_size; j++)
    {
        right[j] = num[mid + 1 + j];
    }

    int i = 0, j = 0, cur = l;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            num[cur] = left[i];
            i++;
        }
        else
        {
            num[cur] = right[j];
            j++;
        }
        cur++;
    }

    while (i < left_size)
    {
        num[cur] = left[i];
        i++;
        cur++;
    }

    while (j < right_size)
    {
        num[cur] = right[j];
        j++;
        cur++;
    }
}

void mergesort(vector<int> &num, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(num, l, mid);
        mergesort(num, mid + 1, r);
        merge(num, l, r, mid);
    }
}

int main()
{
    vector<int> num = {20, 52, 80, 65, 5};
    mergesort(num, 0, num.size() - 1);

    for (int val : num)
        cout << val << " ";

    return 0;
}
