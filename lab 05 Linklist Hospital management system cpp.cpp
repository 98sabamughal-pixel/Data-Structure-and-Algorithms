#include<iostream>
using namespace std;
struct patient{
	int id;
	patient*next;
	
};
patient*head=NULL;
void insertAtbegining(int id){
	patient* newNode=new patient();
	newNode->id=id;
	newNode->next=head;
	head=newNode;
}

void insertAtend(int id){
	patient*newNode=new patient();
	newNode->id=id;
	newNode->next=NULL;
	
if(head==NULL){
	head=newNode;
	return;
}	
patient*temp=head;
while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=newNode;
}
void displaypatients(){
	if(head==NULL){
		cout<<"no patients in the list."<<endl;
		return;
	}
patient*temp=head;
cout<<"current patients ids:";
while(temp!=NULL){
	cout<<temp->id<<"->";
	temp=temp->next;
}	
cout<<"NULL"<<endl;
}
int main(){
	int choice, id;
	do{
		cout<<"\n---hospital patient system---\n";
		cout<<"1.add emergency patient (beginning)\n";
		cout<<"2.add normal patient(end)\n";
		cout<<"3.display all patients\n";
		cout<<"4.exit\n";
		cout<<"enter your choice:";
		cin>>choice;
	switch(choice){
	case 1:
		cout<<"enter patient id:";
		cin>>id;
		insertAtbegining(id);
		cout<<"emergency patient added.\n";
		break;
	case 2:
		cout<<"enter patient id:";
		cin>>id;
		insertAtend(id);
		cout<<"patient added at end.\n";
		break;
	case 3:
		displaypatients();
		break;
	case 4:
		cout<<"exiting program...\n";
		break;
	default:
		cout<<"invalid choice!\n:";
}

	}while(choice!=4);
	return 0;
}

