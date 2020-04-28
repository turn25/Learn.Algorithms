#include <iostream>
using namespace std;

void clear();
void InputNumberOfElements(int &);
void InputArr(int [],int );
void OutputArr(int [],int );
void CountingSort(int [],int );

int main(){
    int n;
    InputNumberOfElements(n);
    int a[n];
    InputArr(a,n);
    cout<<"Array: ";
    OutputArr(a,n);
    /*int b[7]={1,4,1,2,7,5,2};
    CountingSort(b,7);*/
    CountingSort(a,n);
    cout<<"Sorted Array: ";
    OutputArr(a,n);
    return 0;
}

// Hàm clear buffer
void clear(){
    cin.clear(); // reset lại cờ lỗi
    cin.ignore(1000,'\n'); // bỏ qua 1000 kí tự trong bộ nhớ đệm cho đến khi xuống dòng
}

//Nhập vào độ dài mảng
void InputNumberOfElements(int &n){
    int bad_input;
    do{
        bad_input = 0; // set lại giá trị bad_input 
        cout<<"Input n: ";
        if(!(cin >> n)) // nếu nhập vào giá trị không phải số nguyên thì đặt cờ lỗi
        {
            bad_input=1;
            cout<<"Please input a number!\n";
        }
        clear(); // hàm clear
    }while( n<0 || bad_input == 1); 
}

//Hàm nhập mảng (từ 0 đến 9)
void InputArr(int arr[],int n){
    int bad_input;
    cout<<"Input a number between 0-9\n";
    for(int i = 0; i < n; i++){
        do{
            bad_input=0; // set lại giá trị bad_input 
            cout<<"Input a["<<i<<"]: ";
            if(!(cin>>arr[i])){ //nếu nhập vào giá trị không phải số nguyên thì đặt cờ lỗi
                bad_input=1;
                cout<<"Please input a number!\n";
            }
            clear(); // hàm clear
        }while(arr[i]<0 || arr[i]>9 ||bad_input==1);
    }
}

//Hàm xuất mảng
void OutputArr(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//Hàm sort , từ nhỏ đến lớn , số dương từ 0 đến 9
void CountingSort(int arr[],int n){
    /*OutputArr(arr,n);
    cout<<endl;*/
    int CountArr[10];     //Tạo mảng đếm từ 0 đến 9         CountArr[index]
    for(int i=0;i<10;i++) //Khởi tạo giá trị 0 cho mảng
        CountArr[i]=0;
    for(int i=0;i<n;i++){  // Bắt đầu đếm
        //CountArr[arr[i]]++;
        int value = arr[i]; // lưu giá trị của thứ i của mảng cần xếp
        CountArr[value]++;  // value -> giá trị của index =value sẽ +1 
    }
    /*for(int i=0;i<10;i++){
        cout<<CountArr[i]<<" ";
    }*/
    for(int i=0;i<10;i++){ //cộng giá trị để lấy index xếp cho mảng, giá trị hiện tại = giá trị hiện tại + giá trị trước đó
        CountArr[i]+=CountArr[i-1];  // để lấy index cho mảng
        //cout<<CountArr[i]<<" ";
    }
    /*cout<<endl;
    OutputArr(CountArr,10);
    cout<<endl;*/
    //OutputArr(arr,n);
    int NewArr[n]; //tạo mảng mói để lưu giá trị đã đc sắp xếp 
    
    // Xếp mảng . vì đã có index nên chỉ việc gán giá trị của mảng arr cho index của mảng mới
    for(int i=0;i<n;i++){
         // trừ giá trị của trong mảng count, đặt lên trước vì ở trên xét i=1 thay vì 0;
        int value = arr[i];// lưu giá trị của thứ i của mảng cần xếp
        CountArr[value]--; // trừ giá trị đi 1 trước vì số phần tử trong mảng bắt đầu từ 0 chứ ko phải 1. |vd ở dưới|
                           //(lúc trước khi trừ 1 thì số index = n nhưng số phần tử trong mảng là n-1)
        int index = CountArr[value]; // lưu index của mảng đếm 
        NewArr[index] = arr[i]; //  gán giá trị (value) cho index của mảng mới
        //CountArr[value] --;
    }
    //Dời mảng NewArr sang mảng arr
    for(int i=0;i<n;i++){
        arr[i]=NewArr[i];
    }
    /*cout<<endl;
    OutputArr(NewArr,n);*/
}

/* Input : 5 3 1 2 5
Index:     0  1  2  3  4  5  6  7  8  9     // mảng CountArr
Count:     0  1  1  1  0  2  0  0  0  0

Index:     0  1  2  3  4  5  6  7  8  9     // mảng CountArr
Count:     0  1  2  3  3  5  5  5  5  5     // xếp theo hàng đơn vị , nên cộng giá trị count lại đc vị trí trong mảng

xét lại mảng ban đầu-> vị trí của giá trị trong mảng = giá trị của count, - giá trị của count đi 1 để đc chỗ xếp nhở hơn 1 đơn vị

Index:     0  1  2  3  4  5  6  7  8  9     // mảng CountArr
Count:     0  0  0  2  3  4  5  5  5  5  

Index      1  2  3  4  5 --> mảng này bắt đầu từ 1 còn mảng ở trên chương trình là bắt đầu từ 0 nên phải trừ 1 
NewArr:    1  2  3  5  5     trước khi gán giá trị cho index của mảng mới
*/