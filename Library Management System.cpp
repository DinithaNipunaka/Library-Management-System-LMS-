#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<sstream>
#include<windows.h>

using namespace std;

//forward declaration. (After processing the declaruion the compiler would allow to the program to use this functions);

void dashboard();
void regNewBook();
void regNewUser();
void listAllBooks();
void listAllMembers();
void showExpiredBook();
void borrowBook();
void logout();
void login();
void registerAdmin();

int main() { 

  int choice;
  
	cout << "\t\t\t_________________________________________________________________ \n\n\n";
	cout << "\t\t\t                     Welcome to login page                   \n\n\n";
	cout << "\t\t\t________________________     MENU     ___________________________\n\n";
	cout << "\t\t\t																  \n\n";
	
	cout << "\t\t\t| Press 1 to LOGIN                   				|" << endl;
	cout << "\t\t\t| Press 2 to REGISTER                  			        |" << endl;
	
    cout << "\n\t\t\t Please enter your choice : ";
    cin>>choice;
  
    cout<<endl;
        
    switch(choice){
    	
        case 1:
            login();
            break;
            
        case 2:
            registerAdmin();
            break;
    
        default:
            system("cls");
            cout << "You've made a mistake , give it a try again\n" << endl; 
            main( );
    }
        
}

void login(){
	
    int count;
    string userName,password,user,pass;
    
    system("cls");
    
    cout<<"please enter the following details"<<endl;
    
    cout<<"User Naame :";
    cin>>userName;
    
    cout<<"Password :";
    cin>>password;
    
    ifstream input("adminRegStaff.txt");
    
    while(input>>user>>pass){
    	
        if(user == userName && password == pass){
            count=1;
            system("cls");
        }
    }
    
    input.close();
    
    if(count==1){
    	
    	cout << "LOGIN SUCCESS" << endl;
        cout<<"Hello"<<' '<< user << endl; 
        cout << "We're glad that you're here. Thanks for logging in" << endl;
        
        cout << "Loading....................................................";
        Sleep(5000);
        
        system("cls");
        
        dashboard();
    }
    else{
    	cout << "LOGIN ERROR";
        cout<<"Please check your username and password" << endl;

        main();
    }
}

void registerAdmin(){
        
    string regUser,regPass,regu,regp,choice;
	
    system("cls");

    cout<<"Enter the UserName :";
    cin>>regUser;
    
    cout<<"Enter the Password :";
    cin>>regPass;
    
    ofstream reg("adminRegStaff.txt",ios::app);
    
    reg<<regUser<<' '<< regPass <<endl;
    
    system("cls");
    
    cout<<"Registration Sucessful" << endl;
    cout << "Please keep your password safe)" << endl;
    
    cout << "Do you want to register a another user ? (yes / no) :";
    cin >> choice;
    system("cls");
        
        if(choice == "yes"){
        	registerAdmin();
		}else{
			dashboard();
		}
}

void dashboard(){
	
		
	int choice;
	
	cout << "\t\t\t______________________________________________________________ \n\n\n";
	cout << "\t\t\t                   Library Management System                   \n\n\n";
	cout << "\t\t\t____________________     Dashboard     ________________________\n\n";
	cout << "\t\t\t																  \n\n";
	
	cout << "\t| Press 1 to Register a new book                   				|" << endl;
	cout << "\t| Press 2 to Member Registation               				        |" << endl;
	cout << "\t| Press 3 to List out all the books                   				|" << endl;
	cout << "\t| Press 4 to List out all the members                  				|" << endl;
	cout << "\t| Press 5 to Save borrowed Book by user                   			|" << endl;
	cout << "\t| Press 6 to Get expired book list						|" << endl;
	cout << "\t| Press 7 to Logout                   						|" << endl;
	
	cout << "\n\t\t\t Please enter your choice : ";
	cin >> choice;
	cout << endl;
	
	
	switch(choice){
		
		case 1:
			
			regNewBook();
		
			break;
			
		case 2:
			
			regNewUser();
		
			break;
		
		case 3:
			listAllBooks();
			break;
			
		case 4: 
		  	listAllMembers();
		  	break;
		
		case 5:
			borrowBook();
			break;
			
		case 6:
			showExpiredBook();
			break;	

		case 7:
			logout();
			break;
	}
}

void regNewBook(){

		int numberOfBooks, bookID;		
		string bookName,auther,price,issueDate,choice;
		
        system("cls");
        
        // Seed the random number generator with the current time
    	srand(time(NULL));
    	
    	// Generate a unique random number between 0 and 9999
    	int uniqueNumber = rand() % 10000;
    	
        bookID = uniqueNumber;
        
        cout<<"Enter the bookName: ";
        cin>>bookName;
        
        cout<<"Enter the auther of the book: ";
        cin>>auther;
        
        cout<<"Enter the price of the book: ";
        cin>>price;
        
        cout<<"Enter the issue date of the book (yyyy-mm-dd): ";
        cin>>issueDate;
        
        cout<<"How many books do we have: ";
        cin>>numberOfBooks;
        
        ofstream reg("registeredBooks.txt",ios::app);
        reg << bookID <<' '<< bookName <<' '<< auther <<' '<< price <<' '<< issueDate <<' '<< numberOfBooks << endl;
        
        system("cls");
        
        cout << "Processing...................................................." << endl;
        Sleep(3000);
        
        cout << "Book registration Sucessfull" << endl;
        
        cout << "Do you want to register a new book again ? (yes / no) :";
        cin >> choice;
        
        system("cls");
        
        if(choice == "yes"){
        	regNewBook();
		}else{
			dashboard();
		}

}

void regNewUser(){
	
	int userID,userPassword;
	string userName,age,BOD,address,city,mobile,choice;
    system("cls");
    
 	//Seed the random number generator with the current time
    srand(time(NULL));
    	
    // Generate a unique random number between 0 and 9999
    int uniqueNumber = rand() % 10000;
    
    userID = uniqueNumber;
    
	cout<<"Enter the userName :";
    cin>>userName;
		
	userPassword = uniqueNumber;
    
    cout<<"Enter your age :";
    cin>>age;
   
    cout<<"Enter your date of birth (yyyy-mm-dd) :";
    cin>>BOD;
    
    cout<<"Enter your address :";
    cin>>address;
    
   	cout<<"Where you are live in ? :";
    cin>>city;
    
    cout<<"Enter your working mobile number :";
    cin>>mobile;
    
    ofstream reg("userRegistation.txt",ios::app);
    
    reg << userID <<' '<< userName <<' '<< userPassword <<' '<< age <<' '<< BOD <<' '<< address <<' '<< city <<' '<< mobile << endl;
    
    cout << "Processing....................................................";
    Sleep(3000);
        
    system("cls");
    cout<<"Registration Sucessful" << endl;
    
    cout << "Please keep your password safly : " << userPassword << endl;

    cout << "Do you want to register a another user ? (yes / no) :";
    cin >> choice;
        
    system("cls");
    
    if(choice == "yes"){
    	regNewUser();
	}else{
		dashboard();
	}
}

void listAllBooks(){
	
	int bookID;
    string bookName,auther,price,issueDate,numberOfBooks;
    
    system("cls");
    cout<< "Book Details"<<endl<<endl;
     		
	ifstream input("registeredBooks.txt");
        while(input>>bookID >> bookName >> auther >> price >> issueDate >> numberOfBooks){
    
		    cout<<"Book ID : "<<bookID<<endl;
		    cout<<"Book Name :"<<bookName<<endl;
		    cout<<"Auther :"<<auther<<endl;
		    cout<<"Price :"<<price<<endl;
		    cout<<"issueDate :"<<issueDate<<endl;
		    cout<<"Number Of Books :"<<numberOfBooks<<endl;
		    cout<<"\n\n";
	    
    	}
        
		cout<< "Press Enter to continue..." <<endl; 

     	cin.ignore(10, '\n'); 
     	cin.get();
     	
     	system("cls");
        dashboard();
}

void listAllMembers(){
	
	int userID,userPassword;
	string userName,age,BOD,address,city,mobile;
   
   	system("cls");
    cout<< "Member Details"<<endl<<endl;
    
	ifstream input("userRegistation.txt");
        while(input>> userID >> userName >> userPassword >> age >> BOD >> address >> city >> mobile){
        	
            cout<<"User ID : "<<userID<<endl;
		    cout<<"User Password :"<<userPassword<<endl;
		    cout<<"User Name :"<<userName<<endl;
		    cout<<"Age :"<<age<<endl;
		    cout<<"BOD :"<<BOD<<endl;
		    cout<<"Address :"<<address<<endl;
		    cout<<"City :"<<city<<endl;
		    cout<<"Mobile :"<<mobile<<endl;
		    cout<<"\n\n";
	    
    	}
        
		cout<< "Press Enter to continue..." <<endl; 
     	cin.ignore(10, '\n'); 
     	cin.get();
     	
     	system("cls");
        dashboard();
}

void showExpiredBook(){
	
	string bookId,memberID,borrowedDate,expDate,memberName;	

	system("cls");

   	// get the current time
   	time_t now = time(0);

   // convert to local time
   	struct tm *local_time = localtime(&now);

   // format the time as yyyy-mm-dd
   char date_time[20];
   strftime(date_time, sizeof(date_time), "%Y-%m-%d", local_time);

	ifstream input("borrowedBooks.txt");
	while (input >>bookId >> memberID >> memberName >>borrowedDate>>expDate) {
		
	    if (date_time > expDate) {
	    	
	    	cout<<"Book ID : "<<bookId<<endl;
		    cout<<"Member ID :"<<memberID<<endl;
		    cout<<"Member Name :"<<memberName<<endl;
		    cout<<"Borrowed Date :"<<borrowedDate<<endl;
		    cout<<"Expired Date :"<<expDate<<endl;
		    cout<<"\n\n";
		    
		} 
	}

	cout<< "Press Enter to continue..." <<endl; 
 	cin.ignore(10, '\n'); 
 	cin.get();
 	
 	system("cls");
    dashboard();
}

void borrowBook() {
	
  string bookID, memberID, line, expDate, memberName, choice;
  bool found = false;
  time_t currentTime;
  struct tm *localTime;
  
  system("cls");
  
  // get current time
  currentTime = time(NULL);
  localTime = localtime(&currentTime);
  
  // get book ID
  cout << "Enter book ID to borrow: ";
  cin >> bookID;

  // check if book is available
  ifstream books("registeredBooks.txt");
  while (getline(books, line)) {
    istringstream iss(line);
    string id, name;
    iss >> id >> name;
    if (id == bookID) {
      found = true;
      break;
    }
  }
  books.close();
  if (!found) {
    cout << "Book not found or already borrowed" << endl;
    
    cout << "Do you want to try again ?";
    cin >> choice;
    
    if(choice == "yes"){
    	borrowBook();
	}else{
		dashboard();
	}
	
    return;
  }

  // get member ID
  cout << "Enter member ID: ";
  cin >> memberID;

  // check if member exists
  found = false;
  ifstream members("userRegistation.txt");
  while (getline(members, line)) {
  	
    istringstream iss(line);
    string id, name;
    iss >> id >> name;
    
    if (id == memberID) {
      found = true;
      memberName =  name;
      break;
    }
  }
  members.close();
  if (!found) {
    cout << "Member not found" << endl;
    
    cout << "Do you want to try again ?";
    cin >> choice;
    
    if(choice == "yes"){
    	borrowBook();
	}else{
		dashboard();
	}
	
    return;
  }
  
  cout << "Enter the expireDate : ";
  cin >> expDate;

  // add borrowing record
  ofstream borrow("borrowedBooks.txt", ios::app);
  borrow << bookID << " " << memberID << " " << memberName << " " << localTime->tm_mday << "/" << localTime->tm_mon + 1 << "/" << localTime->tm_year + 1900 << " " << expDate << endl;
  borrow.close();
  cout << "Book borrowed successfully" << endl;
  
	cout<< "Press Enter to continue..." <<endl; 
	cin.ignore(10, '\n'); 
	cin.get();
	
	system("cls");
	dashboard();
}

void logout(){
	system("cls");
	main();
}
