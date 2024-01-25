#include<bits/stdc++.h>
using namespace std;

int idx(vector<int>&arr,int low, int high){
    int count=0;
    int pivotele = arr[low];
    for(int i=low; i<arr.size(); i++){
        if(pivotele>arr[i])count++;
    }
    int pivotidx = count+low;
    swap(arr[low],arr[pivotidx]);
    int i=low,j=high;
    while(i<pivotidx and j>pivotidx){
        if(arr[i]<arr[pivotidx])i++;
        if(arr[j]>arr[pivotidx])j--;
        if(arr[i]>arr[pivotidx] and arr[j]<arr[pivotidx] ){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    return pivotidx;
}
void quick(vector<int>&arr,int low, int high){
    if(low>=high)return;

    int pivotidx = idx(arr,low,high);
    quick(arr,low,pivotidx-1);
    quick(arr,pivotidx+1,high);
}
int main(){
    vector<int>arr{2,1,3,4};
    quick(arr,0,arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}