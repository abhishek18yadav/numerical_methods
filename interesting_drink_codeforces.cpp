#include<bits/stdc++.h>
using namespace std;

void f(vector<int>&arr, int low , int high, int val){
    bool find=0;
    while(low<=high){
     int mid=( low+high)/2;

     if(arr[mid]==val){
        cout<<mid+1<<endl;
        find=1;
       break;
     }
     else if(arr[mid]<val){
        low=mid+1;

     }
     else{
        high=mid-1;

     }
    }
    if(find==0){
    int count=0;
      for(int i=0; i<arr.size(); i++){
           if(arr[i]<val)count++;
            else {
             cout<<count<<endl;
             break;
           }
        }
    }
}

int main(){
    int n;
    cout<<"no of shops";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int days;
    cout<<"no of days plan to buy drink";
    cin>>days;
    sort(arr.begin(),arr.end());
    while(days--){
        int d;
        cin>>d;
        f(arr,0,n-1,d);
    }

    return 0;
}