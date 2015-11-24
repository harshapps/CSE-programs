#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;
}
void minHeapify(int a[], int i, int n,int degree)
{   int pos[degree];
    for(int j=0;j<degree;j++)    //degree - no of childs
        pos[j]=degree*i + (j+1);

      int smallest = i;
    for(int k=0;k<degree;k++)
       if ( pos[k] < n && a[pos[k]] < a[smallest])
       smallest =pos[k];

    if (smallest != i)
    {
    swap(a[smallest], a[i]);
    minHeapify(a, smallest, n,degree);

    }
}

void formHeap(int a[], int n,int degree)
{
    for (int i = n / degree; i >= 0; i--)
    minHeapify(a, i, n,degree);

}

void heapSort(int a[], int n,int degree)
{  // in max heap the first elelement is largest ,send it to the largest index and bring the largest index data to first index
 // max heapify so that largest element at first index..........
  formHeap(a, n,degree);
    while (n > 1)
    {
    swap(a[0], a[n - 1]);
    n--;
    minHeapify(a, 0, n,degree);
    }
}

int main()
{
    int a[] = { 1, 4, 2, 7, 5, 10, 9, 16, 15, 14 };

    int n = sizeof(a) / sizeof(int);
   cout<<"Enter degree of d- heap :";
   int degree;cin>>degree;
    heapSort(a, n,degree);
    print(a, n);



    return 0;
}
