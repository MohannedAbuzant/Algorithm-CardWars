
#include <iostream>  
#include <string.h>
using namespace std;
int max(int A, int B) {
    if (A >= B) {
        return A;
    }
    else {
        return B;
    }
}
int min(int A, int B) {
    if (A <= B) {
        return A;
    }
    else {
        return B;
    }
}
void convertToOpposite(string& s)
{
    int sizeOfString = s.length();

  
    for (int i = 0; i < sizeOfString; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            
            s[i] = s[i] - 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            
            s[i] = s[i] + 32;
    }
}

int DP_CardWar(int* A, int  size)
{
    int** table = new int* [size];
    string m[50][50];
    for (int i = 0; i < size;i++)
        table[i] = new int[size];


    for (int Edge = 0; Edge < size; Edge++) {
        for (int i = 0, j = Edge; j < size; i++, j++) {
            
            int Front2Cards = ((i + 2) <= j) ? table[i + 2][j]: 0;
            int FrontBack= ((i + 1) <= (j - 1))? table[i + 1][j - 1]: 0;
            int  Back2Cards= (i <= (j - 2))? table[i][j - 2]: 0;
                
            table[i][j] = max(A[i] + min(Front2Cards, FrontBack),A[j] + min(FrontBack, Back2Cards));
                if (i == j) {
                    m[i][j] = "F";
                    
                }

                else if (table[i][j] == A[i] + Front2Cards|| table[i][j] == A[i] + FrontBack) {
                    string s = m[i + 1][j];
                    convertToOpposite(s);
                    m[i][j] = "F" + s;
                  
                }
                else if (table[i][j] == A[j] + Back2Cards || table[i][j] == A[j] + FrontBack) {
                    string s = m[i ][j-1];
                    convertToOpposite(s);
                    m[i][j] = "B"+s;
                }

            
        }
    }
   
            cout <<"Sequence of (0,5)"<< m[0][5] << endl;
    
    return table[0][size - 1];
}


int main()
{
    int n;
    cin >> n;
    int A[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << DP_CardWar(A, n);

}
