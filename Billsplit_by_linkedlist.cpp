#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	float A;
	string R;
	string W;
	Node *Next;
	Node(float Amount,string Reason,string Who_paid)
	{
		W=Who_paid;
		R=Reason;
		if(W=="him")
			A=(-1)*Amount;
		else
			A=Amount;
	}
};
void Node_at_tail(Node* &Tail,float A,string R,string W)
{
	Node*temp=new Node(A,R,W);
	Tail->Next=temp;
	Tail=temp;
}
void Input(Node* &Tail)
{
	char C;
	cout<<"Do you want to enter more data?\n(y) for yes (n) for no : ";
	cin>>C;
	float A;
	string R,W;
	while(C=='y')
	{
		cout<<"Enter the Amount spent : ";
		cin>>A;
		cout<<"Reason for the Amount spent : ";
		cin>>R;
		cout<<"Who paid the Ammount?\n(me) for you (him) for him : ";
		cin>>W; 
		Node_at_tail(Tail,A,R,W);
		cout<<"Do you want to enter more data?\n(y) for yes (n) for no : ";
		cin>>C;
	}
}
void Output(Node* Head)
{
	float Due;
	while (Head!= NULL)
	{
		if (Head->A < 0)
			cout<<"Amount spent = "<<(Head->A*(-1))<<" by "<<Head->W<<" for "<<Head->R<<endl;
			
		else
			cout<<"Amount spent = "<<Head->A<<" by "<<Head->W<<" for "<<Head->R<<endl;
		Due=Due+(Head->A/2);
		Head=Head->Next;
	}
	if(Due < 0)
		cout<<"You need to pay him : Rs "<<(Due*(-1))<<endl;
	else
		cout<<"He Should Pay you : Rs "<<Due<<endl;
}
int main()
{
	float Amount;
	string Reason,Who_paid;
	cout<<"Enter the Amount spent : ";
	cin>>Amount;
	cout<<"Reason for the Amount spent : ";
	cin>>Reason;
	cout<<"Who paid the Ammount?\n(me) for you (him) for him : ";
	cin>>Who_paid; 
	Node*Head=new Node(Amount,Reason,Who_paid),*Tail=Head;
	Input(Tail);
	Output(Head);
	return 0;
}
