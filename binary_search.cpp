#include <iostream>
using namespace std;

int binary_search(int a[], int n, int key)
{

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{

    int n;
    int key;

    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element you want to search : ";
    cin >> key;
    cout<<binary_search(a, n, key);
    
    


    return 0;
}