#include <iostream>
using namespace std;

void InputArray(int [],int &); //tham chiếu
void OutputArray(int [],int );
void MergeSort(int [],int ,int );

int main()
{
    int a[50];
    int n;
    InputArray(a,n);
    cout<<"Array: ";
    OutputArray(a,n);
    MergeSort(a,0,n-1); // mảng chạy từ 0 đến n-1
    cout<<"Sorted Array: ";
    OutputArray(a,n);
    return 0;
} 
/*int main()                    //Test
{
    int a[5]={4,6,3,1,2};
    int size=sizeof(a)/sizeof(int);
    cout<<size<<endl;
    MergeSort(a,0,size-1);
    OutputArray(a,size);
}*/ 
void InputArray(int a[],int &n)  // n là tham chiếu
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

/*void MergeSort(int a[],int left,int right) //Sort từ NHỎ đến LỚN
{
    if(left<right)   // vị trí đầu < vị trí cuối (ĐK dừng đệ quy)
    {
        int mid=(left+right)/2; //Tìm vị trí ở giữa
        //xài đệ quy chia đôi từng nửa để xét, chạy từ trái qua phải
        MergeSort(a,left,mid); //Đệ quy. chạy từ vị trí đầu đến vị trí giữa 
        MergeSort(a,mid+1,right); //Đệ quy. chạy từ vị trí giữa+1 đến vị trí cuối
        int Sub[right];   //Tạo mảng phụ với độ dài là vị trí cuối+1
        int i=left; //Xét từ left đến mid  (NỬA TRÁI)
        int j=mid+1;//Xét từ mid+1 đến right (NỬA PHẢI)
        int k=0; //vị trí của mảng phụ
        while(i<=mid || j<= right) //Khi nào còn 1 trong 2 cái thì vẫn tiếp tục
        {   
//THỨ TỰ BỊ SAI
            //Sort từ NHỎ đến LỚN
            if(a[i]>a[j]) //phần từ bên TRÁI (>)LỚN hơn phần từ bên PHẢI
            {
                Sub[k]=a[j]; // Cho (vị trí) a[j] vào mảng phụ
                k++; //Dời qua vị trí tiếp theo của mảng phụ               (1)
                j++; //Dời vị trí j (bên PHẢI) 1 đơn vị xét để xét tiếp với i (bên TRÁI)
            }
            else if(a[i]<a[j]) //phần từ bến TRÁI (<)NHỎ hơn phần tử bên phải
            {
                Sub[k]=a[i]; // Cho (vị trí) a[i] vào mảng phụ
                k++; // (1)
                i++; //Dời vị trí i (bên TRÁI) 1 đơn vị xét để xét tiếp với j (bên PHẢI)
            }
            else if(i>mid) //bên TRÁI ko còn phần tử nào
            {
                Sub[k]=a[j]; // Cho (vị trí) a[j] vào mảng phụ
                k++; //(1)
                j++; 
            }
            else //bên PHẢI ko còn phần tử nào    if(j>right)
            {
                Sub[k]=a[i]; //Cho (vị trí) a[i] vào mảng phụ
                k++; //(1)
                i++;
            }
        }
        //Copy mảng phụ về mảng a
        for(int i=0;i<k;i++) //
            a[left+i]=Sub[i];  //left +i vì xài đệ quy
    }
}*/ //Sai vòng while VÌ NẾU KO ĐỂ ĐK i>mid và j>right lên trước, (i>mid bị lấn sang bên phải) (j>right bị vượt quá vị trí trong mảng)
void MergeSort(int a[],int left,int right) //Sort từ NHỎ đến LỚN
{
    if(left<right)   // vị trí đầu < vị trí cuối (ĐK dừng đệ quy)
    {
        int mid=(left+right)/2; //Tìm vị trí ở giữa
        //xài đệ quy chia đôi từng nửa để xét, chạy từ trái qua phải
        MergeSort(a,left,mid); //Đệ quy. chạy từ vị trí đầu đến vị trí giữa 
        MergeSort(a,mid+1,right); //Đệ quy. chạy từ vị trí giữa+1 đến vị trí cuối
        int Sub[right];   //Tạo mảng phụ với độ dài là vị trí cuối+1
        int i=left; //Xét từ left đến mid  (NỬA TRÁI)
        int j=mid+1;//Xét từ mid+1 đến right (NỬA PHẢI)
        int k=0; //vị trí của mảng phụ
        while(i<=mid || j<= right) //Khi nào còn 1 trong 2 cái thì vẫn tiếp tục
        {
            //Sort từ NHỎ đến LỚN
            if(i>mid) //bên TRÁI ko còn phần tử nào
            {
                Sub[k]=a[j]; // Cho (vị trí) a[j] vào mảng phụ
                k++; //Dời qua vị trí tiếp theo của mảng phụ               (1)
                j++; //Dời vị trí j (bên PHẢI) 1 đơn vị xét để xét tiếp với i (bên TRÁI)
            }
            else if(j>right) //bên PHẢI ko còn phần tử nào    if(j>right)
            {
                Sub[k]=a[i]; //Cho (vị trí) a[i] vào mảng phụ
                k++; //(1)
                i++; //Dời vị trí i (bên TRÁI) 1 đơn vị xét để xét tiếp với j (bên PHẢI)
            }
            else if(a[i]<a[j]) //phần từ bến TRÁI (<)NHỎ hơn phần tử bên phải
            {
                Sub[k]=a[i]; // Cho (vị trí) a[i] vào mảng phụ
                k++; // (1)
                i++; 
            }
            else //phần từ bên TRÁI (>)LỚN hơn phần từ bên PHẢI
            {
                Sub[k]=a[j]; // Cho (vị trí) a[j] vào mảng phụ
                k++; //(1)
                j++; 
            }
        }
        //Copy mảng phụ về mảng a
        for(int i=0;i<k;i++) //
            a[left+i]=Sub[i];  //left +i vì xài đệ quy
    }
}
