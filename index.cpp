#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct user
{
	string username;
	string password;
	
}record;

struct Order{
	string name;
	double price;
}calc[10];

struct delivery{
	string type;
	int count;
}vehicle;

char option;
void registration();//this function is used for registration
void login();//this function is used for login
void displayMenu();//this function is used to read input from menu.txt and display
void total(Order[],int,delivery&);//this function is used to get input from user based on the displayed menu
void displayOrder(Order[],int,delivery);//this function to display the receipt on the prompt
double calculateSubtotal(Order[], int, delivery);//this function to calculate the order price
void saveReceiptToFile(double,double,double, delivery, Order[],int);//this function to display the receipt on the receipt.txt
void logo();//this function for decoration
void thank();//this function for decoration

int main()
{
	char choice;
	double subtotal;
	double taxRate = 0.08;
	double totalAmount;
	logo();
	thank();
	cout<<setw(45)<<"WELCOME TO MCDONALD"<<endl;
	system("pause");
	system("color ce");
	cout<<setw(68)<<"Already have an account yes(y)/no(n)..";
	cin>>choice;
	cin.ignore();
	if(choice=='Y'||choice=='y'){
		login();
	}
	if(choice=='N'||choice=='n'){
		registration();
	}
	if(option=='y'||option=='Y')
	{
		login();
	}
	if(option=='n'||option=='N')
	{
		return 0;
	}
	
	displayMenu();
	total(calc,10,vehicle);
	displayOrder(calc,10,vehicle);
	subtotal=calculateSubtotal(calc,10,vehicle);
	cout<<"Subtotal : "<<subtotal;
	totalAmount=subtotal+(subtotal*taxRate);
	saveReceiptToFile(subtotal,taxRate,totalAmount,vehicle,calc,10);
	
}

void registration()//this function is used for registration
{
	string name;
	string password;
	string email;
	int numPhone;
	cout<<setw(60)<<"\tCreate account"<<endl;
	cout<<setw(60)<<"Username : ";
	getline(cin,name);
	cout<<setw(60)<<"Password : ";
	getline(cin,password);
	cout<<setw(60)<<"Email : ";
	getline(cin,email);
	cout<<setw(60)<<"Phone Number : ";
	cin>>numPhone;
	cin.ignore();
	cout<<"You are registered"<<endl;
	cout<<"Proceed to log in? yes(y)/no(n)..";
	cin>>option;
	cin.ignore();
	system("cls");
	
	ofstream outfile;
	outfile.open((name + " detail.txt").c_str());
	outfile<<name<<endl;
	outfile<<password<<endl;
	outfile<<email<<endl;
	outfile<<numPhone<<endl;
}

void login()//this function is used for login
{
	string name;
	string password;
	ifstream infile;
	char choice;
	choice = 'y';
	cout<<setw(60)<<"Sign in"<<endl;
	while(choice=='Y'||choice=='y')
	{
		cout<<setw(60)<<"Username : ";
		getline(cin,name);
		cout<<setw(60)<<"Password : ";
		getline(cin,password);
		infile.open((name + " detail.txt").c_str());
		bool success=false;
		while(!success&&getline(infile,record.username)&&getline(infile,record.password))
		{
			if(name==record.username && password==record.password)
			{
				success=true;
				break;
			}
		}
		
		infile.close();
		
		if(success)
		{
			cout<<setw(50)<<"Login success  ";
			system("pause");
			choice='n';
			system("cls");
		}
		else
		{
			cout<<setw(50)<<"Login failed  ";
			cout<<"Do you want to try again? (y/n) : ";
			cin>>choice;
			cin.ignore();
			if(choice=='N'||choice=='n')
			{
				option='n';
			}
		}
	}
}
	
void displayMenu()//this function is used to read input from menu.txt and display
{
	ifstream infile;
	infile.open("menu.txt");
	string display;
	int i=0;
	while(!infile.eof())
	{
		getline(infile,display);
		cout<<setw(60)<<display<<endl;
		
	}
	infile.close();
}

void total(Order cals[],int x,delivery &veh)//this function is used to get input from user based on the displayed menu
{
	int choice;
    cout << "\nEnter the menu number to add to your order (0 to finish order): ";
    cin >> choice;
    veh.count=0;
    while (choice != 0 )
    {
    	int i=veh.count;
    	switch(choice)
    	{
    		case 1:
                cals[i].name="Chicken";
                cals[i].price=6.59;
                veh.count++;
                break;
			case 2:
                cals[i].name="Nasi Lemak";
                cals[i].price=6.59;
                veh.count++;
                break;
            case 3:
                cals[i].name="McChicken";
                cals[i].price=6.49;
                veh.count++;
                break;
            case 4:
                cals[i].name="Beef Burger";
                cals[i].price=6.49;
                veh.count++;
                break;
            case 5:
                cals[i].name="Nuggets";
                cals[i].price=6.19;
                veh.count++;
                break;
            case 6:
                cals[i].name="Porridge";
                cals[i].price=6.19;
                veh.count++;
                break;  
            case 7:
                cals[i].name="Coca Cola";
                cals[i].price=4.29;
                veh.count++;
                break;
            case 8:
                cals[i].name="Milo";
                cals[i].price=3.79;
                veh.count++;
                break;
            case 9:
                cals[i].name="Fries";
                cals[i].price=3.69;
                veh.count++;
                break;
            case 10:
                cals[i].name="Sundae";
                cals[i].price=1.89;
                veh.count++;
                
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
		}
		cout <<setw(60)<< " : ";
        cin >> choice;
		i++;
	}
	system("pause");
	system("cls");
	cout<<" "<<endl;
	cout<<setw(60)<<"----------- TYPE OF ORDER -----------"<<endl;
	cout<<setw(60)<<"|-----------------------------------|"<<endl;
	cout<<setw(60)<<"|     DELIVERY     |    DINE-IN     |"<<endl;
	cout<<setw(60)<<"|------------------|----------------|"<<endl;
	cout <<setw(50)<<"Enter the type of order (D/DN) : ";
    cin >> veh.type;
    cin.ignore();
    
    if (veh.type == "D" || veh.type == "d") {
            string address;
            cout <<setw(60)<<"Enter your delivery address: ";
            getline(cin, address);
            cout <<setw(60)<<"Your order will be delivered to: " << address << endl;
            veh.type="Delivery";
            
        } else if (veh.type == "DN" || veh.type == "dn") {
        	srand(time(0));
            int queueNumber=rand() % 100;
            cout << "You have chosen dine-in. Please wait for your queue number." << endl;
            cout << "Your queue number is: " << queueNumber << endl;
            veh.type="Dine-in";
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
        system("pause");
        system("cls");
}

void displayOrder(Order cals[],int x,delivery veh) {//this function to display the receipt on the prompt
    cout << "\nOrder Details:" << endl;
    cout << "Order Type: " << veh.type << endl;
    cout << "Items:" << endl;

    for (int i = 0; i < veh.count; i++) {
        cout << "Item: " << cals[i].name << ", Price: $" << cals[i].price << endl;
    }
}

double calculateSubtotal(Order y[], int z, delivery x) {//this function to calculate the order price
    double subtotal = 0.0;
    for (int i = 0; i < x.count; i++) {
        subtotal += y[i].price;
    }
    return subtotal;
}

void saveReceiptToFile(double subtotal, double taxes, double totalAmount, delivery eat, Order meal[],int x) {//this function to display the receipt on the receipt.txt
    ofstream outputFile("receipt.txt");

    if (outputFile.is_open()) {
    	
        
        outputFile << "--------------------- McDonald's ---------------------\n";
        outputFile << "Order\n";
        outputFile << "------------------------------------------------------\n";
        outputFile << "Item              Price\n";
        outputFile << "------------------------------------------------------\n";
		
		for (int i = 0; i < eat.count; i++) {
            outputFile << setw(20)<<left<<meal[i].name <<": RM" << fixed << setprecision(2) << meal[i].price << "\n";
        }
		
        outputFile << "------------------------------------------------------\n";
        outputFile << "Subtotal:         RM" << fixed << setprecision(2) << subtotal << "\n";
        outputFile << "Taxes:            RM" << fixed << setprecision(2) << taxes*subtotal << "\n";
        outputFile << "Total Amount:     RM" << fixed << setprecision(2) << totalAmount << "\n";
        outputFile << "------------------------------------------------------\n";
		
        outputFile.close();
        cout << "\nReceipt saved to receipt.txt\n";
    }
    else {
        cout << "Unable to open file for writing.\n";
    }
}

void logo()//this function for decoration
{
	ifstream infile;
	infile.open("burger.txt");
	string display;
	while(!infile.eof())
	{
		getline(infile,display);
		cout<<display<<endl;
		
	}
	infile.close();
}

void thank()//this function for decoration
{
	ifstream infile;
	infile.open("thank.txt");
	string display;
	while(!infile.eof())
	{
		getline(infile,display);
		cout<<display<<endl;
		
	}
	infile.close();
}
