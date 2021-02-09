#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int X;
    cin >> N >> X;
    int A;
    vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A != X)
        {
            vec.push_back(A);
        }
    }
    int vecEnd = vec.size();
    if (vecEnd != 0)
    {
        for (int i = 0; i < vecEnd - 1; i++)
        {
            cout << vec.at(i) << " ";
        }
        cout << vec.back() << endl;
    }
    else
    {
        cout << "" << endl;
    }
}