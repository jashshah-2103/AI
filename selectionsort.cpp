
#include <bits/stdc++.h>

using namespace std;

void selectionsort(int arr[],int n){
        
        int i=0;
        int j=0;
        int minidx;
        
        for( i=0;i<n-1;i++){
            minidx=i;
            for( j=i+1;j<n;j++){
                if(arr[j]<arr[minidx]){
                    minidx=j;
                }
            }
            swap(arr[i],arr[minidx]);
        }
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        
    }

int main()
{   
    
    int a[]={5,6,2,1,0,9,8,3};
    int n = sizeof(a)/sizeof(a[0]); 
    selectionsort(a,n);
    cout<<"Hello World";

    return 0;
}
