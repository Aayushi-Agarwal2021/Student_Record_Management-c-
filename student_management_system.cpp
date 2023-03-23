#include<iostream>
#include<conio.h>
// for console ip/op
using namespace std; //library containing standards
// making linked lsit
class node
{
    public://access specifier
     int roll_no;
     string name;
     float marks;
     float per;
     node * next;
};
class linked_list //all functions like insert delete will be here
{
    public:
       node* head=NULL; //null because there is no node in linked list

       //insert function
       void insert()
       {
         int r;
         string n;
         float m;
         cout<<"\n Enter roll no:  ";
         cin>>r;
         cout<<"\n Enter name: ";
         cin>>n;
         cout<<"\n Enter marks: ";
         cin>>m;
         node * new_n=new node;
         new_n->roll_no=r;
         new_n->name=n;
         new_n->marks=m;
         new_n->per=(m/100)*100;
         new_n->next=NULL;
         
         if(head==NULL)
         {
            head=new_n;

         }
         else{
            node *t=head;
            while(t->next != NULL)
            {
                t=t->next;
            }
            t->next=new_n;
         }
         cout<<"\n NEW NODE INSERTED SUUCESSFULLY";

        
       }

       //SEARCH FUNCTION 
       void search()
       {
        if(head==NULL)
          cout<<"\n OOPS! LINKED LIST IS EMPTY yet.";
          else{
            int r,found=0;
            cout<<"\n ENTER ROLL NO OF RECORD TO BE SEARCHED: ";
            cin>> r;
            node*t=head;
            while(t!=NULL)
            {
                if(t->roll_no==r)
                {
                    cout<<"\n Roll no : "<<t->roll_no;
                    cout<<"\n NAME : "<<t->name;
                    cout<<"\n Marks : "<<t->marks;
                    cout<<"\n Percentage : "<<t->per<<"%";
                    found++;
                    break;
                }
                t=t->next;
            }
            if(found==0)
            cout<<"\n NO SUCH RECORD FOUND! ENTER CORRECT ROLL NO.";

          }
       }
       //COUNT FUNCTION
       void count()
        {
            if(head==NULL)
             cout<<"\n NO RECORDS FOUND.";

            else{
                int c=1;
                node*t=head;
                while(t->next!=NULL)
                {
                    c++;
                    t=t->next;
                }
                cout<<"\n TOTAL NO OF RECORDS FOUND : "<< c;
            }
        }
        //UPDATE FUNCTION
        void update()
        {
            int r;
            cout<<"\nEnter roll no of the record you want to update: ";
            cin>>r;
            if(head==NULL)
            {
                cout<<"\n KINDLY ENTER RECORDS FIRST.";
                return;
            }
            node * t= head;
            int found=0;
            while(t!=NULL)
            {
                if(t->roll_no==r)
                {
                    cout<<"\n CURRENT ENTRIES ARE: ";
                    cout<<"\n Roll no : "<< t->roll_no;
                    cout<<"\n NAME : "<<t->name;
                    cout<<"\n Marks : "<<t->marks;
                    cout<<"\n Percentage : "<<t->per<<"%";
                    found++;
                    break;
                }
                t=t->next;
            }
            if(found==0)
            cout<<"\n NO SUCH RECORD FOUND! ENTER CORRECT ROLL NO.";
            else{
                cout<<"\n\n ENTER CHANGES YOU WANT TO MADE";
                cout<<"\n\n ROLL NO: ";
                cin>>t->roll_no;
                cout<<"\n NAME: ";
                cin>>t->name;
                cout<<"\n MARKS: ";
                cin>>t->marks;
                t->per= (t->marks/100)*100;
                cout<<"\n\n RECORD IS UPDATED SUCCESSFULLY.";
            }


        }
        //delete
        void del()
        {
            if(head==NULL)
            {
                cout<<"\n\n NO RECORDS FOUND. ";
                return;
            }
            else{
            
            int found=0;
            int r;
            cout<<"\n\n ENTER ROLL NO OF THE RECORD YOU WANT TO DELETE: ";
            cin>>r;
            if(r==head->roll_no)
            {
                node *ptr=head;
                head=head->next;
                cout<<"\n\n RECORD DELETED SUCCEESSFULLY";
                delete(ptr);
                found++;
            }
            else{
                node* t=head->next, *q=head;
             while(t!=NULL)
             {
                if(t->roll_no==r)
                {
                    cout<<"\n delete record's ENTRIES ARE: ";
                    cout<<"\n Roll no : "<< t->roll_no;
                    cout<<"\n NAME : "<<t->name;
                    cout<<"\n Marks : "<<t->marks;
                    cout<<"\n Percentage : "<<t->per<<"%";
                    cout<<"\n\n\n RECORD DELETED SUCCESSFULLY.  :)";
                    found++;
                     q->next=t->next;
                     delete(t);
                    break;
                }
                q=t;
                t=t->next;
             }
            }
            if(found==0)
              cout<<"\n\n RECORD NOT FOUND.";
            }

        }
        //show
        void print()
        {
            if(head==NULL)
            cout<<"\n\n LINKED KIST IS EMPTY.";
            else{
                node* t=head;
                while(t!=NULL)
                {
                    cout<<"\n\n RECORD: ";
                    cout<<"\n Roll no : "<< t->roll_no;
                    cout<<"\n NAME : "<<t->name;
                    cout<<"\n Marks : "<<t->marks;
                    cout<<"\n Percentage : "<<t->per<<"%";
                    t=t->next;
                }
            }
        }
       

};
 main()
{
    linked_list obj; //object of class linked_list to access its functions'
    int choice;
    p:
      system("cls");
    //menu
    cout<<"\n\n 1. INSERT RECORD";
    cout<<"\n\n 2. SEARCH RECORD";
    cout<<"\n\n 3. COUNT NO OF RECORDS";
    cout<<"\n\n 4. UPDATE RECORD";
    cout<<"\n\n 5. DELETE RECORD";
    cout<<"\n\n 6. SHOW ALL RECORD";
    cout<<"\n\n 7. EXIT";
    cout<<"\n\n\n\n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
           system("cls");
           obj.insert();
           break;
        case 2:
           system("cls");
           obj.search();
           break;
        case 3:
           system("cls");
           obj.count();
           break;
        case 4:
           system("cls");
           obj.update();
           break;
        case 5:
           system("cls");
           obj.del();
           break;
        case 6:
           system("cls");
           obj.print();
           break;
        case 7:
           exit(0);
        default:
           cout<<"\n\n\n\nINVALID CHOICE...... try again";
           
    }
    getch();
    goto p;//label

    
}