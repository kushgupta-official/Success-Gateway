/*Link List Operations by Kush Gupta*/
//Faults: first and last index in rev range not works usually

# include <iostream>
# include <stdlib.h>
# include <process.h>
# include <conio.h>
using namespace std;

struct node{
	int data;
	struct node *next;
};
struct node *start=NULL;

void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter data: ";
	cin>>temp->data;
	temp->next=NULL;	
	if (start==NULL)
	{
		start=temp;
	}
	else
	{
		struct node *p=start;
		while (p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}

void display()
{
	struct node *p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"-->";
		p=p->next;
	}
	cout<<"NULL";
}

void remdup()
{
	struct node *p=start,*q=start;
	while(p->next!=NULL)
	{
		q=p->next;
		//cout<<"q assigned";
		while(q->data==p->data)
		{
			if(q->next!=NULL)
			{
				q=q->next;
			}
		}
		/*if(q==NULL)
		{
			p->next=NULL;
			break;
		}*/
		p->next=q;
		p=p->next;
	}
	cout<<"done";
}
struct node *reverse()
{
	struct node *p,*q,*r;
	p=NULL;
	q=start;
	r=q->next;
	while(q!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL)
		{
			r=r->next;
		}
	}
	return p;
}

void revrange()
{
	int s,e;
	cout<<"Enter rev start index: ";
	cin>>s;
	cout<<"Enter rev end index: ";
	cin>>e;
	struct node *temp=start,*p=NULL,*q,*r,*temp2,*prev;
	int count=0;
	while(temp->next!=NULL)
	{
		++count;
		if (count==s-1)
		{
			q=temp->next;
			p=temp;
			prev=temp;
		}
		else if(count==e)
		{
			temp2=temp->next;
			temp->next=NULL;
			break;
		}
		temp=temp->next;
	}
//	cout<<"\nInitialization done.\n";
	r=q->next;
	p=NULL;
/*	getch();
	display();
	getch();
	cout<<p->data<<endl<<q->data<<endl<<r->data<<endl;
	getch();*/
	while(q!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL)
		{
			r=r->next;
		}
	}
//	cout<<"\nReverse done\n";
	prev->next=p;
/*	getch();
	display();
	getch();
*/	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp2;
	cout<<"Reversed successfully\n";
}

/*void revpattern()//in a pattern of 3
{
	int count=0;
	node *p,*q,*r,*prev,*temp=start,*temp2,*end;
	while(temp->next!=NULL)
	{
		p=NULL;
		count++;
		if (count==1)
		{
			q=temp;
			r=q->next;
		}
		if (count==3)
		{
			end=temp->next;
			temp->next=NULL;
		while(q!=NULL)
		{
			q=q->next;
			p=q;
			q=r;
			if (r!=NULL)
			{
				r=r->next;
		}
		}
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=end;
		temp=end;
	}
}*/
int main()
{
 while(1)
 {
  int ch;
  cout<<"\n1.Append\n2.Display\n3.Remove duplicate from sorted ll\n4.Reverse\n5.Reverse in a range\n6.Reverse in pattern of 3\n0.Exit";
  cout<<"\nEnter your choice : ";
  cin>>ch;
  switch(ch){
  	case 1:append();
  		   break;
  	case 2:display();
  		   break;
  	case 3:remdup();
  		   break;
  	case 4:start=reverse();
  		   break;
  	case 5:revrange();
  		   break;
  	case 6:revpattern();
  		   break;
  	case 0:exit(0);
  		   break;
  	default:cout<<"Wrong choice entered\n";
  }	
 }
}
