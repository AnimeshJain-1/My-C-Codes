#include<iostream>
using namespace std;
#include "firstnode.cpp"
void print(node * h)
{   node*temp=h;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
node*inputnode_better()
{
    int data;
    cin>>data;
    node*head=NULL;
    node*tail=NULL;
    while(data!=-1)
    {  // node*newNode=new node(data);
        if(head==NULL)
        { 
            head=tail=new node(data);
            //head=tail=newNode;
            //tail=newNode;
        }
        else
        {
            tail->next=new node(data);
         
            tail=tail->next;  //OR tail=newNode;
        }
        cin>>data;
    }
    return head;
}
//WORKING
void bubblesort3(node*head,int length)
{
    node*temp=head;
    node*temp1=head;
    int i=0,count=0;
    while(temp1->next!=NULL)
    {
        count=0;
    for(temp=head;temp->next!=NULL;temp=temp->next)
        {
            if(count<length-i)
            {
                if(temp->data>temp->next->data)
                {
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
                }
            }
            else
            break;
            count++;
        }
        temp1=temp1->next;
        i++;
    }
    print(head);
}
//NOT WORKING
void bubblesort2(node*head,int length)
{
    node*temp=head;
    for(int i=0;i<length;i++)
      { 
          temp=head; 
        for(int j=0;j<length-i;j++)
        {
            if(temp->data>temp->next->data)
            {
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
            }
            temp=temp->next;
        }
      } 
      print(head);
}
//WORKING
void bubblesort(node*head)
{   node*temp=head;
    node*temp1=head;
    while(temp1->next!=NULL)
    {
    for(temp=head;temp->next!=NULL;temp=temp->next)
        {
            if(temp->data>temp->next->data)
            {
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
            }
        }
        temp1=temp1->next;
    }
    print(head);    
}
int lengthofLL(node*head)
{   int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
int main()
{
    node*head=inputnode_better();
    print(head);
    //bubblesort(head);
    int length=lengthofLL(head);
    cout<<"length : "<<length<<endl;
    //bubblesort2(head,length);
    bubblesort3(head,length);
}