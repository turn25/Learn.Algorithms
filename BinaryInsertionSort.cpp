#include <iostream>
using namespace std;

void InputArray(int [],int &); //tham chiếu
void OutputArray(int [],int );
void BinaryInsertionSort(int [],int );

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    BinaryInsertionSort(a,n);
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

void BinaryInsertionSort(int a[],int n) //Tăng dần
{   
    int l,m,r; // l=left , m = mid , r=right
    for(int i=1;i<n;i++) //vị trí đầu đoạn CHƯA sắp xếp
    {
        int x=a[i]; //lưu giá trị a[i] tránh bị ghi đè
        int l=0;    //left = vị trí đầu đoạn ĐÃ sắp xếp
        int r=i-1;  //right= vị trí cuối đoạn ĐÃ sắp xếp
        while(l<=r) //thỏa thì THỰC HIỆN vòng lặp tiếp (nếu left > right kết thúc vòng lặp)
        {
            m=(l+r)/2; // Tìm mid  
            if(x<a[m]) //Nếu x<a[m] (a[i]<a[mid]) thì 
                r=m-1; // vị trí cuối đoạn ĐÃ sắp xếp = vị trí mid -1 (xét đoạn bên trái mid)
            else       // Nếu ko thỏa ĐK if thì
                l=m+1; // vị trí đầu đoạn ĐÃ sắp xếp = vị trí mid +1 (xét đoạn bên phải mid)
        /* Tìm vị trí để chèn x bằng pp tìm nhị phân (binary search )
           Vị trí tìm đc chính là l (left)                */
        }
        for(int j=i-1;j>=l;j--)
            a[j+1]=a[j]; //Dời các phần tử lớn hơn x trong đoạn ĐÃ sắp xếp sang phải 1 đơn vị
        a[l]=x; //vị trí chèn x là (l,left tìm đc ở đoạn trên)
    }
}