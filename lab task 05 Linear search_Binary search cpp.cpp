#include<iostream>
using namespace std;

int linearsearch(int arr[],int size,int roll){
	for(int i=0; i<size; i++){
		if(arr[i]==roll)
		return i;
	}
	return -1;
}

int binarysearch(int arr[], int size, int roll){
	int low =0,high =size-1;
	while(low<=high){
	int mid =(low + high)/2;
		
	if(arr[mid]==roll)
	return mid;
	else if(arr[mid]<roll)
	low=mid+1;
	else
	   high=mid-1;
	}
	return -1;
}

int main(){
	int n ,choice ,roll;
	  
	  cout<<"===== student record search system====="<<endl;
	  cout<<"enter the number of students:";
	  cin>> n;

int arr[n];
cout<<"enter the roll number:"<<endl;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
cout<<"\n select search method:"<<endl;
cout<<"1.linear search(unsorted  Record)"<<endl;
cout<<"2. binary search(sorted  Record)"<<endl;
cout<<"enter your choice (1 or 2):";
cin>> choice;
        cout<<"\n enter roll number to search:";
        cin>>roll;
        
            int result=-1;
             if(choice==1){
             	 result =linearsearch(arr,n,roll);
             	 
			 }
			 
			 else if(choice==2){
			 	
		        result = binarysearch(arr,n,roll);
			 }
		    else{
		    	cout<<"invalid choice!"<<endl;
		    	 return 0;
			}
			
	   if(result!=-1)
	   cout<<"\n roll number found at position:"<<result+1<<endl;
	   
	   else
	   cout<<"\n roll number not found in record. "<<endl;
	   
	   
	   return 0;
}

