#include<iostream>
#include<algorithm>
using namespace std;
int binarysearchAsc(int arr[],int n,int key)
{
	int low=0, high=n-1;
while(low<=high){
	int mid=(low+high)/2;
	if(arr[mid]==key)
	return mid;
else if(arr[mid]<key)
low=mid+1;
else
high=mid-1;
}
  return-1;
}
       int binarysearchDesc(int arr[],int n,int key)
       {
       	int low=0, high=n-1;
       	while(low<=high){
       		int mid=(low+high)/2;
       		if(arr[mid]==key)
       		
       		return mid;
       		else if(arr[mid]<key)
       		low=mid+1;
       		else
       		high =mid-1;
		   }
		   return 1;
	   }
	int main(){
		int n;
		cout<<"enter the number of students:";
		cin>>n;
		int roll[n];
		cout<<"enter the student roll number:";
		for(int i=0;i<n;i++)
		cin>>roll[i];
	int key;
	cout<<"enter roll number to search:";
	cin>>key;
	
	int pos;
	if(key%2==0){
		sort(roll,roll+n);
		cout<<"performing binaryfunction in (ascendingorder)"<<endl;
		pos= binarysearchAsc(roll,n ,key);
	}
	else{
		sort(roll,roll+n);
		reverse(roll,roll+n);
		cout<<"performing binaryfunction in(descendingorder)"<<endl;
		pos= binarysearchDesc(roll ,n ,key);
	}
	if(pos!=-1)
	cout<<"roll no found at position:"<<pos+1<<endl;
	else
	cout<<"roll no not found";
	return 0;
	}
