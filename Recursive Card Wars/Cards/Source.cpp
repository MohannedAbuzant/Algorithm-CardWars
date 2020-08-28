#include<iostream>
using namespace std;

int Recursive_CardWars(int S[], int i, int j, int total)
{

    if (j == i)
        return S[i];

    int Left = total - Recursive_CardWars(S, i + 1, j, total - S[i]);
    int Right = total - Recursive_CardWars(S, i, j - 1, total - S[j]);

    return (Left > Right)? (Left): (Right);
}


int main()
{
    int n;
    cin >> n;
    int A[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }


    cout << Recursive_CardWars(A, 0, n - 1, sum);
    return 0;
}
