
using namespace std;


int optimalStrategyOfGame(int* arr, int n)
{
	int table[n][n];
	for (int gap = 0; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			
			int x = ((i + 2) <= j)
				? table[i + 2][j]
				: 0;
			int y = ((i + 1) <= (j - 1))
				? table[i + 1][j - 1]
				: 0;
			int z = (i <= (j - 2))
				? table[i][j - 2]
				: 0;

			table[i][j] = max(
				arr[i] + min(x, y),
				arr[j] + min(y, z));
		}
	}

	return table[0][n - 1];
}


int main()
{
	int arr1[] = {6,4,2,8,10,3};
	int n = sizeof(arr1);
	printf("%d\n",
		optimalStrategyOfGame(arr1, n));
	return 0;
}
