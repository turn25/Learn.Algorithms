#include <iostream>
using namespace std;
void OutputArray(int [],int );
void MergeSort(int [],int ,int );

int main()
{
    int a[]={5,3,1,2};
    int b[]={5,7,43,2,34,64,53,54,34,75,2,24,5,3,22,42,42};
    int size=sizeof(a)/sizeof(int);
    int sizeb=sizeof(b)/sizeof(b[0]);
    cout<<size<<endl;
    MergeSort(a,0,size-1);
    OutputArray(a,size);
    cout<<endl;
    MergeSort(b,0,sizeb-1);
    OutputArray(b,sizeb);
    return 0;
}

void OutputArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

/*void MergeSort(int a[],int left, int right)
{
    //int size=sizeof(a)/sizeof(a[0]);
    int size=sizeof(a)/sizeof(a[]);
    if(size==1)
        return;
    int mid=(left+right)/2;
    MergeSort(a, left, mid);
    MergeSort(a, mid+1, right);
    int Sub[size-1]; // Mảng phụ 
    int i=left;
    int j=mid+1;
    int k=0; // Chỉ số mảng phụ
    while(i<= mid || j<= right) //Chừng nào còn 1 mảng chưa hết phần tử vẫn xét tiếp
    {
        if(i>mid)
        {
            Sub[k]=a[j];
            j++;
            k++;
        }
        else if(j>right)
        {
            Sub[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]>a[j])
        {
            Sub[k]=a[j];
            j++;
            k++;
        }
        else
        {
            Sub[k]=a[i];
            i++;
            k++;
        }
    }
    for(int i=0;i<k;i++)
    {
        a[left+i]=Sub[i];
    }
} */
void MergeSort(int a[],int left, int right) //Sort từ nhỏ đến lớn
{
    //int size=sizeof(a)/sizeof(a[0]);
    if(left<right){        //ĐK để dừng của đệ quy (vị trí đầu < vị trí cuối )
        int mid=(left+right)/2;    //Tìm vị trí ỏ giữa
        MergeSort(a, left, mid);   //(ĐỆ QUY) Vị trí cuối(right) thay bằng mid
        MergeSort(a, mid+1, right);//(ĐỆ QUY) Vị trí đầu(left) thay bằng mid+1
        int Sub[right]; // Mảng phụ 
        int i=left; //i vị trí đầu chạy đến giữa
        int j=mid+1;//j vị trí giữa+1 chạy đến vị trí (cuối)right
        int k=0; // Chỉ số mảng phụ
        while(i<= mid || j<= right) //Chừng nào còn 1 mảng CHƯA hết phần tử vẫn xét tiếp 
        {
            if(i>mid)          //Bên trái ko còn phần tử
            {
                Sub[k]=a[j];
                j++;
                k++;
            }
            else if(j>right)   //Bên phải ko còn phần tử 
            {
                Sub[k]=a[i];
                i++;
                k++;
            }
            else if(a[i]>a[j])  //Phần tử bên trái lớn hơn phải
            {
                Sub[k]=a[j];
                j++;
                k++;
            }
            else                //Phần tử bên trái nhỏ hơn phải
            {
                Sub[k]=a[i];
                i++;
                k++;
            }
        }
        for(int i=0;i<k;i++) //Copy mảng Sub qua mảng a
        {
            a[left+i]=Sub[i];
        }
    }
}
