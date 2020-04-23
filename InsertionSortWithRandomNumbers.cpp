#include <iostream>
#include <time.h>
using namespace std;

void InputElements(int &); //tham chiếu
void RandomArray(int [],int );
void OutputArray(int [],int );
void InsertionSort(int [],int );

int main()
{
    srand(time(0));
    int n;
    InputElements(n);
    int a[n];
    RandomArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    InsertionSort(a,n);
    cout<<"\nSorted Array: ";
    OutputArray(a,n);
    return 0;   
}

void InputElements(int &n)
{
    do{
        cout<<"Input the number of elements: ";
        cin>>n;
    }while(n<=0);
}

void RandomArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        a[i]=rand() %20;
}

void OutputArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void InsertionSort(int a[],int n) //Giảm dần
{
    for(int i=1;i<n;i++)
    {
        int x=a[i];
        int pos=i-1;
        while(pos>=0 && x>a[pos])
        {
            a[pos+1]=a[pos]; // dời qua phải 1 đơn vị
            pos--;
        }
        a[pos+1]=x;
    }
}