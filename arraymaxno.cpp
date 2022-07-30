#include <iostream>
#include <climits>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
    }
    cout << "the largest no. in the array is :" << largest << endl;

    return 0;
}