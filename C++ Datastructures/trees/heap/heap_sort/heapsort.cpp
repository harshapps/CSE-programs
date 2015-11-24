#include<iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;
}
void minHeapify(int a[], int i, int n)    // i- index position
{
    int l = 2*i+1, r = 2*i+2; // l left  r right
    int smallest = i;
    if (l < n && a[l] < a[smallest])
    smallest = l;
    if (r < n && a[r] < a[smallest])
    smallest = r;
    if (smallest != i)
    {
    swap(a[smallest], a[i]);
    minHeapify(a, smallest, n);

    }
}
void maxHeapify(int a[], int i, int n)
{
    int l = 2*i+1, r = 2*i+2; // l left  r right
    int largest = i;
    if (l < n && a[l] > a[largest])
    largest = l;
    if (r < n && a[r] > a[largest])
    largest = r;
    if (largest != i)
    {
    swap(a[largest], a[i]);
    maxHeapify(a, largest, n);

    }
}

void formHeap(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)  //n/2 bcoz there is no need to check leaf nodes
    maxHeapify(a, i, n);

}

void heapSort(int a[], int n)
{  // in max heap the first elelement is largest ,send it to the largest index and bring the largest index data to first index
 // max heapify so that largest element at first index..........
  formHeap(a, n);
    while (n > 1)
    {
    swap(a[0], a[n - 1]);
    n--;
    maxHeapify(a, 0, n);
    }
}

int main()
{
    int a[] = { 1, 4, 2, 7, 5, 10, 9, 16, 15, 14 };

    int n = sizeof(a) / sizeof(int);

    heapSort(a, n);
    print(a, n);



    return 0;
}
