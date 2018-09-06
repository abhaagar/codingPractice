// code owner www.gohired.in
//C++ program to find maximum occured element in given N ranges.
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Return the maximum occurred element in all ranges.
int maximumOccuredSmallestElement(int L[], int R[], int n,int largest)
{
	// Initalising all element of array to 0.
	int prefixArray[largest];
	memset(prefixArray, 0, sizeof L);

	for (int i = 0; i < n; i++)
	{
		prefixArray[L[i]] += 1;
		prefixArray[R[i] + 1] -= 1;
	}
	
	int msum = prefixArray[0], ind;
	for (int i = 1; i < largest; i++)
	{
		prefixArray[i] += prefixArray[i-1];
                //SEE this Array and understand how this code and Logic of prefix works
		cout <<"prefix ["<<i<<"] = "<<prefixArray[i]<<endl;
		if (msum < prefixArray[i])
		{
			msum = prefixArray[i];
			ind = i;
		}
	}
	return ind;
}
// Driven Program
int main()
{
	int L[] = { 1, 4, 9, 13, 21 };
	int R[] = { 15, 8, 12, 20, 30 };
	int largest=0;
	int n = sizeof(L)/sizeof(L[0]);
        for(int i=0;i<n;i++){
            largest = max(largest,max(L[i],R[i]));
        }
	cout << maximumOccuredSmallestElement(L, R, n, largest+1) << endl;
	return 0;
}



