#include <bits/stdc++.h>
using namespace std;

int merge(int a[],int temp[],int left,int mid,int right){
	int i=left,j=mid,k=left;
	int c = 0;
	while(i<=mid-1 and j<=right){
		if(a[i] <= a[j]){
			temp[k++] = a[i++];
		}else{
			temp[k++] = a[j++];
			c+=mid-i;
		}
	}
	
	while(i<=mid-1){
		temp[k++] = a[i++];
	}
	
	while(j<=right){
		temp[k++] = a[j++];
	}
	
	return c;
}

int mergeSort(int a[],int temp[],int left,int right){
	int cnt = 0;
	if(left<right){
		int mid = (left+right)/2;
		cnt+=mergeSort(a,temp,left,mid-1);
		cnt+=mergeSort(a,temp,mid+1,right);
		cnt+=merge(a,temp,left,mid+1,right);
	}
	
	return cnt;
}

int main(){
	int a[]={5,3,2,1,4};
	int n=5;
	int temp[n];
	int ans = mergeSort(a,temp,0,4);
	cout << ans << "\n";
	return 0;
}
