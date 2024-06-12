#include <iostream>
#include<string>
#define SIZE 100
using namespace std;

struct Contact{ //structuring a contact using singly linked list
    string NameOfCustomer;
    string PhoneNo;
    Contact *next;
};
Contact *head = NULL, *tail = NULL, *temp = NULL,*cur = NULL;

void InsertContact(string Name, string PhoneNum) //inserting from tail
{
    Contact *temp = new Contact; //creating a node/ contact
    temp->NameOfCustomer = Name;
    temp->PhoneNo = PhoneNum;
    temp->next = NULL;
    
    if(head == NULL) //if contact book is empty
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}//end of function

void DeleteContact(string Name)//function to delete a contact by person name
{
    Contact *temp = head;
    Contact *prev = NULL;
    if (temp != NULL && temp->NameOfCustomer == Name) {//if not empty and the contact wanted to be deleted is found
        head = temp->next;
        delete temp;
        cout << Name << " is deleted \n";
    }
    else
    {
        while (temp != NULL && temp->NameOfCustomer != Name) {//if not empty and the contact wanted to be deleted isn't the same as entered by user
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)// if list is empty
            return;
        
        prev->next = temp->next;
        
        delete temp;
        cout << Name << " is deleted \n";
    }
}//end of function

void DeleteElement(int number)//function to deleting contact by element #
{
    Contact *temp1 = head;
    
    if(number == 1)//starting from 1st element
    {
        head = temp1->next;
        delete temp1;
    }
    
    for(int i=0; i<number-2; i++)//starting from element after the head
    temp1 = temp1->next;
    
    Contact *temp2=temp1->next;
    
    temp1->next = temp2->next;
    delete temp2;
    
    cout << "contact number (" << number << ") is deleted \n";
}//end of function

void SearchByLetter(int number,char letters[SIZE]) //searching 1-3 first letters
{
    Contact *cur=head;
    
    if(cur==NULL) //empty
    {
        cout<<"List is Empty!!\n";
    }
    else
    {
        while(cur!=NULL)//not empty
        {
         int i=0;
         
          while(number<=3){
           if(number==1){//searching by initial
            if(cur->NameOfCustomer.at(i)== letters[i])
            {
                cout << cur->NameOfCustomer << "  "<< cur->PhoneNo;
                cout<<endl;
                cur=cur->next;//traversing to show other contacts that start with that letter as well
            }//end 2nd if
            else //if no name that start with that first letter is met yet, then traverse again
              cur=cur->next;
              break;
            
          }//end 1st if
          
           else if(number==2){//searching by 1st 2 letters
            if(cur->NameOfCustomer.at(i)== letters[i]&&cur->NameOfCustomer.at(i+1)==letters[i+1])
            {
                cout << cur->NameOfCustomer << "  "<< cur->PhoneNo;
                cout<<endl;
                cur=cur->next;
            }//end 2nd if
            else
                cur=cur->next;
                break;
          }//end 1st if
          
          else if(number==3){//searching by 1st 3 letters
            if(cur->NameOfCustomer.at(i)== letters[i]&&cur->NameOfCustomer.at(i+1)==letters[i+1]&&cur->NameOfCustomer.at(i+2)==letters[i+2])
            { 
                cout <<cur->NameOfCustomer << "  "<< cur->PhoneNo;
                cout<<endl;
                cur=cur->next;
            }//end 2nd if
            else
                cur=cur->next;
                break;
          }//end 1st if
         }//end 2nd while
        }//end 1st while
      cout<<endl;
    }
}//end of function

void SearchByName(string name) //searching by full name
{
    Contact *cur=head;
    
    if(cur==NULL)
    {
        cout<<"List is Empty!!\n";
    }
    else
    {
        while(cur!=NULL)
          {
            if(cur->NameOfCustomer == name )
            {
                cout << cur->NameOfCustomer << "  "<< cur->PhoneNo;
                break;
            }
            cur=cur->next;
        }
        cout<<endl;
    }
}//end of function

void SortList(Contact *head)//sorting contact in an alphabetical order
{
    Contact *i, *j;
    i=head;//assign contact i pointer to head
    
    for(i=head ; i!=NULL ; i=i->next)
    {
        for(j=i->next ; j!=NULL ; j=j->next)//start from head until the end so it�s null
        {            
            if(i->NameOfCustomer.at(0) > j->NameOfCustomer.at(0))//comparing first letters of contacts
            {
            swap(i->NameOfCustomer,j->NameOfCustomer);
            swap(i->PhoneNo , j->PhoneNo);
            }
        }
    }
    cout << "The contacts are sorted \n" ;
}//end of function

void DisplayContacts()//displaying contact info of contact
{
    Contact *ptr = head;
    
    if(ptr == NULL)//empty
    {
        cout <<"NO CONTACTS INFORMATION !!" << endl;
    }
    else
    {
        cout<<"-----DISPLAY CONTACTS-----  " <<endl;
        cout<<endl;
        int count = 1; //intializing to count How many contacts we have in the list
        while(ptr !=NULL)
        {
            cout<< count <<". Name is : "<<ptr->NameOfCustomer<<endl;
            cout <<" - Phone Number is : "<<ptr->PhoneNo <<endl;
            cout<< endl;
            ptr = ptr->next;
            count++;
        }
    }
}//end of function

int main()
{
    int choice, Number;
    string NameOfCustomer, PhoneNumber;
    char letters[SIZE],Upper;
    
    do{
        cout << "\n1: Insert contact ( Name & Number )\n";
        cout << "2: Delete contact ( Name )\n";
        cout << "3: Delete by element number\n";
        cout << "4: Search contacts by 1st letters of names \n";
        cout << "5: Search contacts by full name \n";
        cout << "6: Print List of contacts\n";
        cout << "7: Sort List Alphabetically \n";
        cout << "8: Exit \n";
        
        cout << "\nEnter your choice: \n";
        cin>>choice;
		
        switch (choice){
        case 1:
               cout << "\nEnter Name of a new contact:\n";
               cin.ignore();
               getline(cin,NameOfCustomer);
               Upper = toupper(NameOfCustomer.at(0));//convert the 1st letter to uppercase then store it in upper
               NameOfCustomer = Upper+NameOfCustomer.substr(1);//update the name after converting the first letter to an uppercase
			    
               cout << "\nEnter Phone Number For "+NameOfCustomer+" : \n";
               getline(cin,PhoneNumber);
               InsertContact(NameOfCustomer, PhoneNumber);
               break;
        case 2:
               cout << "Enter a Name to delete the contact:\n";
               cin.ignore();
               getline(cin,NameOfCustomer);
               DeleteContact(NameOfCustomer);
               break;
        case 3:
               cout << "Enter the Number of element of the contact to delete: \n";
               cin>>Number;
               cout<<endl;
               DeleteElement(Number);
               break;
        case 4:
               cout << "Enter Number of letters From 1-3 to search the list by :\n";
               cin>>Number;
               if(Number>0&&Number<=3){
               cout << "Enter letter/s to print list of contact :\n";
               cin>>letters;
               cout<<endl;
                   SearchByLetter(Number,letters);
                       }
               else//if Number<0 or Number>3
               {
                   cout<<"!! Enter Numbers from 1-3 only !!\n";
               }
                
               break;
        case 5:
               cout << "Enter a Name to find the contact:\n";
               cin.ignore();
               getline(cin,NameOfCustomer);
               SearchByName(NameOfCustomer);
               break;
        case 6:
               DisplayContacts();
               break;
        case 7:
               SortList(head);
               cout <<"If you want to see List after Sorting Enter Number 6 \n";
               break;
        case 8 :
               cout<<"EXIT ... "<<endl;
               break;
        
        default:
               cout<<"Error! wrong choice\n";
               break;
       }
       
    }while (choice!=8);
    
    return 0;
}//end of main function
