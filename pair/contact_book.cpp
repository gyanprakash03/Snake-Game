#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

// structure to store parameters i.e., phone number and name
struct Node
{
	string name;                
	long long int phone_number; 
	Node *next;
	Node *prev;
};

class ContactBook
{
	Node *head;
    Node *tail;
	string x;
	long long int y;
	
    public:

        // constructor
		ContactBook()
		{
			head = NULL;
            tail = NULL;
			x = "";
			y = 0;
		}

        // function to add a new contact
    	void AddContact()
	    {
            // if contactbook is empty
	    	if(head==NULL)
	    	{
    	    	Node *newcon = new Node;
	    	    cout <<"  Name of Contact: ";
		        cin >> x;
		        newcon->name = x;

    		    cout <<"  Phone Number: ";
	    	    cin >> y;
		        newcon->phone_number = y;

	
		        newcon->next = NULL;
		        newcon->prev = NULL;
		        head = newcon;
                tail = newcon;
		        
		        cout <<"\n  Contact Added Successfully" <<endl;
		    }
            // if contactbook already has contacts
		    else
		    {
			
		        Node *newcon = new Node;
	    	    cout <<"  Name of Contact: ";
		        cin >> x;
		        newcon->name = x;

    		    cout <<"  Phone Number: ";
	    	    cin >> y;
		        newcon->phone_number = y;
		        
		        newcon->next = NULL;
		        
                tail->next = newcon;
                newcon-> prev = tail;
                tail = newcon;
		    	cout <<"\n  Contact Added Successfully"<<endl;
			}
		}

        // function to display all contacts
        void Display()
    	{
	    	Node *temp = head;
	    	int count = 0;
	    	
	    	if(temp==NULL)
	    	{
		    	cout <<"  No contacts saved..." << endl;
                cout <<"  Please add some contacts..." << endl;
	    	}
	    	else
	    	{
	    		BubbleSort();
				cout <<"  -------------------------" << endl;
	    		cout <<"  [Name] "<<"         [Number] "<< endl;
                cout <<"  -------------------------\n" << endl;
	        	while(temp!=NULL)
	        	{
	        	    count++;
		        	cout<<"  "<<temp->name;
		        	cout<<"          "<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
                cout <<"  -------------------------" <<endl;
	        	cout <<"  Total contacts: "<<count<<endl;
	    	}
    	}

        // function to search any contact, either by name or number
        void Search()
    	{
            if (head == NULL) {
                cout << "No contacts saved..." <<endl;
                cout << "Save some contacts to use the Search feature" <<endl;
            }
            else {
                int num = 0;
                Node *temp = head;
                cout <<"-------------------------------------------"<<endl;
                cout <<"  Press 1 if you want to Search By Name." <<endl;
                cout <<"  Press 2 if you want to Search By Number." <<endl;
                cout <<"-------------------------------------------"<<endl;
                int command;
                cout <<"  Enter the Command: ";
                cin >>command;
        
                if(command==1 )
                {
                    cout <<"  Enter the Name to Search: ";
                    cin >> x;

                    while(temp!=NULL)
                    {
                        if(temp->name==x)
                        {
                            cout <<"-------------------------------" <<endl;
                            cout <<"  Name  : "<< temp->name <<endl;
                            cout <<"  Number: "<< temp->phone_number <<endl;
                            cout <<"-------------------------------" <<endl;
                            num = 1;
                            break;
                        }
                        temp = temp->next;
                    }
                    if(num==0)
                    {
                        cout <<"  Name Not Found" <<endl;
                    }
                }
                else if(command==2)
                {
                    cout <<"  Enter the Number to Search: ";
                    cin >> y;
                    
                    while(temp!=NULL)
                    {
                        if(temp->phone_number==y)
                        {
                            cout <<"-------------------------------" <<endl;
                            cout <<"  Name  : "<<temp->name <<endl;
                            cout <<"  Number: "<<temp->phone_number <<endl;
                            cout <<"-------------------------------" <<endl;
                            num = 1;
                            break;
                        }
                        temp = temp->next;
                    }
                    if(num==0)
                    {
                        cout <<"  Number Not Found" <<endl;	
                    }	
                }
                else {
                    cout << "Please enter a valid command..."<<endl;
                }
            }
	    }

        // function to delete all contacts
        void DeleteAllContacts()
	    {
	    	Node *temp = head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<"  Contact Book is Empty..."<<endl;
                cout<<"  Add some contacts to use the Delete feature"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				tail=NULL;
				cout<<"  Successfully Deleted All Contacts"<<endl;
			}
		}

		// function to search and delete a specific contact
		void DeleteContactBySearch()
    	{
    		
	    	Node *temp=head;
	    	cout <<"------------------------------------------"<<endl;
	    	cout <<"  Press 1 if you want to Search By name"<<endl;
	    	cout <<"  Press 2 if you want to Search By Number"<<endl;
			cout <<"------------------------------------------"<<endl;
	    	int command;
	    	cout <<"  Enter the Command: ";
	    	cin >>command;
	  
	  		// search contact by name, print it and delete it
	    	if(command==1)
	    	{
	    		int num2 = 0;
	    		cout <<"  Enter the Name to Delete: ";
	    		cin >> x;

	    		while(temp!=NULL)
	    		{
	    	    	if(temp->name==x)
		        	{
		        		cout <<"------------------------------"<<endl;
		        		cout <<"  Name  : "<<temp->name<<endl;
		        		cout <<"  Number: "<<temp->phone_number<<endl;
		        		cout <<"------------------------------"<<endl;
		        		num2 = 1;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(num2==1)
	        	{
	            	int choice;
	            	cout <<"  Press 1 to Delete the Contact: ";
	            	cin >> choice;
	            	if(choice==1 && temp==head)
	            	{
	            		Node *temp1;
	            		temp1 = temp;
	            		temp = temp->next;
	            		delete temp1;
	        		
	            		temp->prev=NULL;
	            		head = temp;
	            		cout <<"  Contact Deleted SuccessFully"<<endl;
			    	}
			    	else if(choice==1 && temp->next==NULL)
			    	{
						tail = temp->prev;
			    		temp->prev->next=NULL;
			    		delete temp;
			    		cout <<"  Contact Deleted SuccessFully"<<endl;
			    	}
			    	else if (choice==1)
			    	{
			    		Node *temp1;
			    		temp1 = temp;
			    		temp->prev->next = temp1->next;
			    		temp->next->prev = temp1->prev;
			    		delete temp1;
			    		cout <<"  Contact Deleted SuccessFully"<<endl;	
			    	}
					else {
						cout <<"You entered wrong command... Try again"<<endl;
					}
	            }
	            else if(num2==0)
				{
					cout<<"  Contact Not Found..."<<endl;
			    }  
	    	}
			// search contact by number, print it and delete it
	    	else if(command==2)
	    	{
	    		int num2 = 0;
	    		cout <<"  Enter the Number to Delete: ";
	    		cin >> y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout <<"------------------------------"<<endl;
		        		cout <<"name  : "<<temp->name<<endl;
		        		cout <<"Number: "<<temp->phone_number<<endl;
		        		cout <<"------------------------------"<<endl;
		        		num2 = 1;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(num2==1)
	        	{
	            	int choice;
	            	cout <<"  Press 1 to Delete the Contact: ";
	        	    cin >> command;
    	        	if(choice==1 && temp==head)
	            	{
	            		Node *temp1;
	            		temp1 = temp;
	        	    	temp = temp->next;
	        		    delete temp1;
	        		
    	        		temp->prev = NULL;
	            		head = temp;
	            		cout <<"  Contact Deleted SuccessFully"<<endl;
			    	}
				    else if(choice==1 && temp->next==NULL)
    				{
						tail = temp->prev;
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout <<"  Contact Deleted SuccessFully"<<endl;
				    }
				    else if(choice==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next = temp1->next;
				    	temp->next->prev = temp1->prev;
					    delete temp1;
		    			cout <<"  Contact Deleted SuccessFully"<<endl;	
			    	}
					else {
						cout <<"You entered wrong command... Try again"<<endl;
					}
	            }
	            else if(num2==0)
				{
					cout <<"  Contact Not Found..."<<endl;
				}
	    	}
	    	else
	    	{
	    		cout <<"  You Entered a wrong Command"<<endl;
			}
	    }

		// bubblesort function to sort contacts alphabetically
		void BubbleSort()
        {
        	
			Node *i,*j;
			string n;
			long long int n2;
            for(i=head;i->next!=NULL;i=i->next)
            {
                for(j=i->next;j!=NULL;j=j->next)
                {
                    if(i->name>j->name)
		            {
                        n=i->name;
                        i->name=j->name;
                        j->name=n;
             
                        n2=i->phone_number;
                        i->phone_number=j->phone_number;
                        j->phone_number=n2;
                    }
                }
            }
            
        }

		// function to search and edit a contact
		int EditContacts()
    	{
	    	Node *temp = head;
	    	cout <<"------------------------------------------"<<endl;
	    	cout <<"  Press 1 if you want to Search By Name"<<endl;
	    	cout <<"  Press 2 if you want to Search By Number"<<endl;
			cout <<"------------------------------------------"<<endl;
	    	int choice;
	    	cout <<"  Enter the Command: ";
	    	cin >> choice;
	  
	  		// search contact by name, print it and edit it
	    	if(choice==1)
	    	{
	    		int num3 = 0;
	    		cout <<"  Enter the Name to Edit: ";
	    		cin >> x;

	    		while(temp!=NULL)
	    		{
	    	    	if(temp->name==x)
		        	{
		        		cout <<"---------------------------"<<endl;
		        		cout <<"Name  : "<<temp->name<<endl;
		        		cout <<"Number: "<<temp->phone_number<<endl;
		        		cout <<"---------------------------"<<endl;
		        		num3 = 1;
		        		break;
		        	}
			        temp=temp->next;
	        	}				
	        	if(num3==1)
	        	{
	            	int command;
	        	    cout <<"  Press 1 to Edit the Contact: ";
	            	cin >> command;
	        	    if(command==1)
	        	    {
	        		    cout <<"  Enter New Name: ";
    	        		cin >> x;

	            		cout <<"  Enter New Number: ";
	            		cin >> y;
	        		
	            		temp->name = x;
	        	    	temp->phone_number = y;
	        		
	        		    cout <<"  Contact Edited SuccessFully"<<endl;
			    	}
			    	else
			    	{
					    cout <<"  You Enter Wrong Command ... Try Again"<<endl;
	    	        }
	    	    }
	    	    else if(num3==0)
	    	    {
	    	    	cout<<"  Contact Not Found..."<<endl;
				}
	        }
			// search contact by number, print it and edit it.
	    	else if(choice==2)
	    	{
	    		int num3 = 0;
	    		cout <<"  Enter the Number to Edit: ";
	    		cin >> y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"---------------------------"<<endl;
		        		cout<<"Name  : "<<temp->name<<endl;
		        		cout<<"Number: "<<temp->phone_number<<endl;
		        		cout<<"---------------------------"<<endl;
		        		num3 = 1;
		        		break;
		        	}
			        temp = temp->next;
	        	}
	        	if(num3==1)
	        	{
	            	int command;
	        	    cout <<"  Press 1 to Edit the Contact: ";
	            	cin >> command;
	        	    if(command==1)
	        	    {
	        		    cout <<"  Enter New Name: ";
    	        		cin >> x;
						
	            		cout <<"  Enter New Number: ";
	            		cin >> y;
	        		
	            		temp->name = x;
	        	    	temp->phone_number = y;
	        		
	        		    cout <<"  Contact Edited SuccessFully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command... Try again"<<endl;
	    	        }
	        	}
	        	else if(num3==0)
	        	{
	        	    cout<<"  Contact not found..."<<endl;
	            }
	        }
	        else
			{
			    cout<<"  You Entered a Wrong Command "<<endl;
			}
	    }

		// function to save the entered contact info in a .txt file
		void OfflineSave()
    	{
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile <<temp->name <<endl;
		        	myfile <<temp->phone_number <<endl;
    		    	temp = temp->next;		
	        	}
                myfile.close();
                Structure();
            }
            else
            {
            	cout <<"  Error! Opening file..."<<endl;
			}
		}
		
		// function to read the .txt file for further actions like adding, editing or deleting
		void reopenCB()
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt"); // opening file in read mode
            if (myfile.is_open() & myfile.peek() != EOF) // checking if file is open as well as not empty
            {
                int i=0; // initializing from line 1 
                while(getline(myfile,x)) // reading each line and storing it in x
                {	
                    if(i % 2 == 0) // for lines containing name
					{
						if(head==NULL) // if no node
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;
		         
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
						  tail=newer;
		                }
						else  // if atleast one node
						{
							Node *newer= new Node;
							newer->name=x;

							newer->next=NULL;
		                	tail->next=newer;
		                	newer->prev=tail;
							tail=newer;		
						} 
                    }
                   else  // for lines containing phone number
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0) // if only one node
                    	{
                    		
                    		stringstream convert(x); // to convert the string datatype from getline to int
			       	        convert>>y;  // storing that int in y
                            temp->phone_number=y;
						}
						else // if more than one node
						{
							Node *temp=head;
		                	while(temp->next!=NULL)  // iterating to the last node
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(x);
			       	        convert>>y;
		                	temp->phone_number=y;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close(); // closing the file
            }
            else
            {
            	cout<<"  File is Empty so Cannot open..."<<endl; // if file is empty
			}
		}

		// structure of the contactbook
		void Structure()
    	{
	    	cout<<"___________________________________________________________________________\n"<<endl;
	    	cout<<"  1. Add Contact"<<endl;
	    	cout<<"  2. Edit the Contact"<<endl;
	    	cout<<"  3. Delete Contact"<<endl;
	    	cout<<"  4. Search Contact"<<endl;
	    	cout<<"  5. Display All Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
	    	cout<<"------------------------------"<<endl;
		
	    	int Scommand;
	    	cout <<"  Enter the Command: ";
	    	cin >> Scommand;
			cout << "\n";
	    	try
	    	{
	    		if(Scommand==1)
	            {
	            	AddContact();
	            	OfflineSave();
	    	    	Structure();
	            }
	            else if(Scommand==2)
		        {
		        	EditContacts();
		        	OfflineSave();
		        	Structure();
			    }
	            else if(Scommand==3)
	            {
	    	    	DeleteContactBySearch();
					OfflineSave();
	    	    	Structure();
	            }
	            else if(Scommand==4)
	            {
	            	Search();
	            	Structure();
	            }
	            else if(Scommand==5)
	            {      		
	            	Display();
	            	Structure();
	            }
	            else if(Scommand==6)
	            {
	            	DeleteAllContacts();
	            	OfflineSave();
	            	Structure();	
		        }
				else
				{
					throw(Scommand);
				}
			}
			catch(...)
			{
				cout<<"  You Entered a wrong Command... "<<endl;
				Structure();
			}	
	    }
        
};

int main()
{   
    ContactBook cb;
    cb.reopenCB();
	string n;
	cout<<"  What is Your Name: ";
	cin >> n;
	
    cout<<"-------------------------------------------"<<endl;
	cout<< "     THIS IS "<< n << "'s CONTACTBOOK     "<<endl;
	cout<<"-------------------------------------------"<<endl;
	cb.Structure();
	return 0;
}