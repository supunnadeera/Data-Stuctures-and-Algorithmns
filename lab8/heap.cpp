#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void heapify(vector<int>& arr, int n, int root)
{
   int largest = root;
   int left = 2*root + 1;
   int right = 2*root + 2;

   if (left < n && arr[left] > arr[largest])
      largest = left;

   if (right < n && arr[right] > arr[largest])
      largest = right;

   if (largest != root)
   {
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
   }
}

void heapSort(vector<int>& arr, int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   
   for (int i=n-1; i>=0; i--)
   {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }
}

/* print contents of array */
void displayArray(vector<int>& arr, int n)
{
   for (int i=0; i<n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   vector<int> heap_arr;
   string line;
   cout << "Enter space separated array items: ";
   getline(cin, line);
   stringstream ss(line);
   int num;
   while (ss >> num) {
      heap_arr.push_back(num);
   }

   int n = heap_arr.size();
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

