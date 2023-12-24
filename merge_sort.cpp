#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, vector<int>&a, vector<int>&b){
    int i=0,j=0,k=0;
    while(i<a.size() and j<b.size()){
        if(a[i]<b[j]){
            arr[k++]= a[i++];
        }if(a[i]>b[j]){
            arr[k++]= b[j++];
        }
    }
    if(i<a.size()){
        while(i<a.size()){
            arr[k++]=a[i++];
        }
    }
    if(j<b.size()){
        while(j<b.size()){
            arr[k++]=b[j++];
        }
    }
}
void merge_sort(vector<int>&arr){
    if(arr.size()==1)return ;
    int n= arr.size();
    int n1= n/2;
    int n2= n-n1;

    vector<int>a(n1);
    vector<int>b(n2);
    for(int i=0; i<n1; i++){
        a[i]=arr[i];
    }
    for(int i=0; i<n2; i++){
        b[i]=arr[i+n1];
    }
    merge_sort(a);
    merge_sort(b);
    merge(arr,a,b);
}

int main(){
    vector<int>arr{2,5,3,41,1};
    merge_sort(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}