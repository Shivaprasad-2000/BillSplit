#include<bits/stdc++.h>
using namespace std;
class Instances
{
	public:
	float Amount;
	string Reason;
	string Who_paid;
};
void Input(int *n , Instances* &I)
{
	cout<<"Enter how many times money has been spent : ";
	cin>>*n;
	for(int i=0;i<*n;i++)
	{
		float temp_amount;
		cout<<"Enter the amount spent : ";
		cin>>temp_amount;
		cout<<"Enter why amount is spent : ";
		cin>>I->Reason;
		cout<<"Enter who paid the amount \n (me) for you \n (him) for him : "<<endl;
		cin>>I->Who_paid;
		if(I->Who_paid=="him")
			I->Amount = -1*temp_amount;
		else
			I->Amount = temp_amount;
		I++;
	}
	
}
void Output(int n ,Instances* &I_temp)
{
	float Due;
	for(int i=0;i<n;i++)
	{
		
		cout<<"Amount spent = "<<I_temp->Amount<<" by "<<I_temp->Who_paid<<" for "<<I_temp->Reason<<endl;
		Due=Due+(I_temp->Amount/2);
		
		I_temp++;
	}
	if(Due/(Due*-1)==1)
		cout<<" He Should Pay you : "<<Due<<endl;
	else
		cout<<" You need to pay him : "<<Due<<endl;
}
int main()
{
	int n=0;
	Instances *I = new Instances[n],*I_temp = I;
	Input(&n,I);
	Output(n,I_temp);
	return 0;
}
