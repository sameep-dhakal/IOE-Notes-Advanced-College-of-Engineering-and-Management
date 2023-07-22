// Binary Search in C++

#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = (low+high)/2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[100], n, i;
  cout<<"enter the sze of array";
  cin >> n;
  cout<<"insert elements in array";
  for(i=0 ; i < n ; i++)
  {
    cin>>array[i] ; 
  }
  
  int x = 7;
  int result = binarySearch(array, x, 0, n );
  if (result == -1)
    cout<<"Not found";
  else
    cout<<"Element :"<<x<<" is found at index"<<result;
}