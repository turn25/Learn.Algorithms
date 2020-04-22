#include <iostream>
using namespace std;

void InputArray(int [],int &); //tham chiếu
void OutputArray(int [],int );
void ShellSort(int [],int);

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    ShellSort(a,n);
    cout<<"\nSorted Array: ";
    OutputArray(a,n);
    return 0;
}

void InputArray(int a[],int &n)  //tham chiếu
{
    do{
        cout<<"Input n: ";
        cin>>n;
    }while(n<=0);
    for(int i=0;i<n;i++)
    {
        cout<<"Input a["<<i<<"]: ";
        cin>>a[i];
    }
}

void OutputArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void ShellSort(int a[],int n)
{
    int h[3]={5,3,1};
    int k=3; //h[] có 3 phần tử
    for(int step=0;step<k;step++) /* step tăng đến k-1 => step =2 => len=h[step]=h[2]= 1 => Insertion Sort bình thường */
    {
        int len=h[step]; // tùy step mà có thể = 5,3,1
        for(int i=len;i<n;i++) // Chia thành nhiều dãy con 
        {
            int x=a[i];
            int j=i-len;
            while(j>=0 && a[j]>x) //ĐK thỏa cả .nếu j(i-len) >=0 và a[j] |a[i-len]| >x |a[len]|
            { //Xếp dãy con bằng pp Insertion Sort
                a[j+len]=a[j]; // Dời mảng sang len(5,3,1) đơn vị
                j=j-len; // trừ khoảng cách len để tiếp tục xét
            }
            a[j+len]=x; //chèn x vào vị trí j+len, j+len vì ở trên vòng while có j-len
        }
    }
}