/* The following program is a Food Ordering and Delivering system and has 2 users:-
		a) Restaurant Manager
		b) Customer

Programmer : THINESHKUMAR SARAVANAN
Programmer ID : 152771 */
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdio>
using namespace std;


//Declaration of global variable
const int cols = 2;


//Function prototypes
void create_menu();
void update_menu();
double customer(int &);	//Int variable is passed as reference
double DailySales(double, double&);	//Double variable is passed as argument and another double variable is passed as reference


//Main function
int main()
{
	//Variable declaration
	int user, password, wish, again;
	double sales, total = 0, totalsales = 0;
	char update;
	
	//Passed as reference to keep track the total number of customers
	int total_customers = 0;
	
	
	//Program instructions for the users
	cout << "Program Instructions: ";
	cout << "\n\nGood Morning.";
	cout << "If the customers do not see the 'Customer' options, it means the manager has not started the business yet.\n";
	cout << "Please try again later.\n";
	cout << "If you are the manager press number 1 and key in the password to start the business.";
	cout << "\nAfter every order you can press the 'Restaurant Manager' option to check the total sales.\n\n";
	
	cout <<"\t\t\t|-------------------------------------------------------|\n";
	cout <<"\t\t\t|                       TK BISTRO                       |\n";
	cout <<"\t\t\t|-------------------------------------------------------|\n\n";

	//Requires the manager to start the program
	cout << "\t\n[1] : Restaurant manager\n";
	cout << "Enter your choice: ";
	cin >> user;
	
	
	//If the user is not a manager, the program executes the following instruction
	while(user != 1)
	{
		cout << "If you are the manager key in 1: ";
		cin >> user;
	}
	
	
	//If the user is a manager, the program executes the following instructions
	//Requires the manager to input a password
	cout << "Password: ";
	cin >> password;
	
	
	//If invalid password is entered, the program executes the following instruction until a valid password is entered
	while(password != 1111)
	{
		cout << "Invalid password.\n";
		cout << "Try again: ";
		cin >> password;
	}
	
	
	//If the password is correct
	system("CLS");
	cout << "Select one of the following options.";
	cout << "\n\t[1] : Create a new menu\n";
	cout << "\t[2] : Update the menu\n";
	cout << "\t[3] : Use the same menu\n";
	
	//Requires the manager to create a new menu, update an existing menu or use the same menu
	cout << "\nEnter your choice: ";
	cin >> wish;
	
	
	//Only the choices given can be entered
	while(wish != 1 && wish != 2 && wish != 3)
	{
		cout << "Enter your choice: ";
		cin >> wish;
	}
	
	
	//If the manager decides to create a new menu
	if(wish == 1)
	{
		create_menu();	//Function call to create a new menu
		
		
		//If the manager decides to update the menu once he created a new menu
		cout << "Do you wish to update your menu. Key in Y for yes and N for no: ";
		cin >> update;
		
		
		//The manager can only enter the choice given
		while(update != 'Y' && update != 'N')
		{
			cout << "Key in Y or N: ";
			cin >> update;
		}
		
		
		//If the manager wants to update the menu
		if(update == 'Y')
			update_menu();	//Function call to update the menu
	}
	
	
	//If the manager decides to update the already existing menu
	else if(wish == 2)
		update_menu();	//Function call to update the already existing menu
		
	
	//If the manager decides to use an already existing menu
	else if(wish == 3)
		cout << "Have a good day.\n";
	system("PAUSE");
	
	
	//Once the manager decides on menu, the program executes the following instructions
	//Program is allowed for the customers to use
	do
	{
		system("CLS");
		cout <<"\t\t\t|-------------------------------------------------------|\n";
		cout <<"\t\t\t|                       TK BISTRO                       |\n";
		cout <<"\t\t\t|-------------------------------------------------------|\n\n";
		cout << "Choose one of the following options:\n";
				
		//Requires the manager or any new user to input the choice
		cout << "\t[1] : Restaurant manager\n";
		cout << "\t[2] : Customer\n";
		cout << "Enter your choice: ";
		cin >> user;
		
		
		//Only allowed to enter the choice given
		while(user != 1 && user != 2)
		{
			cout << "Please select 1 or 2: ";
			cin >> user;
		}
		
		
		//If the user is the manager, the program executes the following instructions
		if(user == 1)
		{
			//Manager is allowed to check his business's statistics
			cout << "Choose the following option:\n";
			cout << "\t[1] : Business Statistics\n";
			cout << "Enter your choice: ";
			cin >> wish;
			
			
			//Only allowed to enter the choice given
			while(wish != 1)
			{
				cout << "Please select the option given above: ";
				cin >> wish;
			}
			
			
			//If the manager decided to check the business's statistics
			cout << "\nTotal Sales: RM " << totalsales;
			cout << "\nTotal Customers: " << total_customers << endl;
		}
		
		
		//If the user is a customer, the program executes the following instructions
		if(user == 2)
		{
			sales = customer(total_customers);	//Function call to customer
			totalsales = DailySales(sales, total);	//Function call to DailySales
		}
		system("PAUSE");
		system("CLS");
		
		
		//After every customer's order, the manager gets to decide if he still wants to run the business or not
		cout << "Do you still want to run the shop or close it: \n";
		cout << "\t[1]: Yes\n";
		cout << "\t[2]: No\n";
		cout << "Enter your choice: ";
		cin >> again;
		
		
		//Only allowed to enter the choices given
		while(again != 1 && again != 2)
		{
			cout << "Enter again: ";
			cin >> again;
		}
	
	
	//If the manager decides to continue running the business, the program starts again
	}while(again == 1);
	
	
	//If the manager decides to close his business, the program executes the following statements
	cout << "\n\nTotal Sales: RM " << totalsales;
	cout << "\nTotal Customers: " << total_customers << " people";
	cout << "\nHope you had a great day.\n";
	cout << "See you tomorrow.";
	
	
	return 0;
}


//Function to create a new menu
void create_menu()
{
	ofstream outfile;
	outfile.open("Restaurant Menu.txt");	//Open the file
	
	//Variable declaration
	string food;
	int num;
	double price;


	cout << "How many food and drinks do you want to include in your menu? ";
	cin >> num;	//Number of food that the manager wants to include in the menu
	
	
	for(int i = 0; i < num; i++)
	{
		cin.ignore();
		cout << "\nFood/Drink " << (i + 1) << ": ";
		getline(cin, food);	//Food/drink name
		cout << "Price " << (i + 1) << ": RM ";
		cin >> price;	//Price of the food/drink
		
		outfile << fixed << showpoint << setprecision(2);
		outfile << food << "\t" << price  << endl;	//Output all the food/drink and price into a file
	}
	
	
	outfile.close();	//Close the file
}


//Function to update an already existing menu
void update_menu()
{
	ofstream outfile;
	outfile.open("Restaurant Menu.txt", ios::app);	//Open the file
	
	//Variable declaration
	string food;
	int num;
	double price;
	
	
	cout << "How many food and drinks do you wish to update in your menu: ";
	cin >> num;	//Number of food/drinks that the manager wants to update
	
	
	for(int i = 0; i < num; i++)
	{
		cin.ignore();
		cout << "\nFood/Drink " << (i + 1) << ": ";
		getline(cin, food);	//Food/drink name
		cout << "Price " << (i + 1) << ": RM ";
		cin >> price;	//Price of the food/drink
		
		outfile << fixed << showpoint << setprecision(2);
		outfile << food << "\t" << price << endl;	//Output the food and price into the file
	}
	
	
	outfile.close();	//Close the file
}


//Function for the customer
double customer(int &total_customer)
{
	ifstream infile;
	infile.open("Restaurant Menu.txt");//Open the file
	
	//Variable declaration
	string food;
	int count = 0;
	double value;
	
	//Creating array
	string menu[100];
	double price[100];
	
	
	//Read the content from the file and place it in arrays
	while(count < 100 && getline(infile, food, '\t') && infile >> value)
	{
		infile.ignore();
		fflush(stdin);
		menu[count] = food;
		price[count] = value;
		count++;
	}
	
	
	//Variable declaration
	string name;
	int newsize = count + 5, location, wish;
	
	
	cout << "\nKey in your name: ";
	getline(cin, name);
	cout << "\nHello " << name;
	
	
	//Location of customers
	cout << "\nWe only operate within these areas: \n";
	cout << "\t[1]: Seremban\n";
	cout << "\t[2]: Senawang\n";
	cout << "\t[3]: Seremban 2\n";
	cout << "\t[4]: Rasah Jaya\n";
	cout << "\t[5]: Rasah\n";
	cout << "\t[6]: Nilai\n";
	cout << "\t[7]: Mantin\n";
	cout << "Select your location: ";
	cin >> location;
	
	
	//Can only enter location from the choice given
	while(location < 1 || location > 7)
	{
		cout << "Sorry. We only operate within the location stated above.";
		cout << "\nKey in again: ";
		cin >> location;
	}
	
	
	//Print menu that is saved in the file by the manager
	cout << "\nTK Bistro Menu: \n";
	for(int i = 0; i < count; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\tChoice [" << (i + 1) << "]: " << menu[i] << endl;
		cout << "\t\tRM" << price[i] << endl;
	}
	
	
	//Variable declaration
	int choice, num, a = 0, b = 0, c = 0;
	double multiply, total = 0, full_total = 0, tax, payment, balance;
	
		
	//Creating array
	double arr[newsize][cols] = {}, PriceOrdered[newsize];
	double TemporaryPrice;
	string FoodOrdered[newsize];
	
	
	//Requires the customer to order food/drinks
	do
	{
		bool flag = false;
		
				
		cout << "\nEnter a choice from 1 to " << count << ": ";
		cin >> choice;
		
		
		//Can only enter the food/drinks from the choice given
		while(choice < 1 || choice > count)
		{
			cout << "The choice entered should be within 1 to " << count << ". Enter again: ";
			cin >> choice;
		}
		
		
		//Num of food/drinks that the customer wants
		cout << "How many? ";
		cin >> num;
		
		
		//Placing the order of the customer in a new 2d array		
		while(a < newsize)
		{
			while(b < newsize)
			{
				arr[a][0] = price[choice - 1];
				arr[a][1] = num;
				TemporaryPrice = price[choice - 1] * num;
				flag = true;
				break;
			}
			if(flag == true)
			{
				a++;
				b++;
				cin.ignore();
				fflush(stdin);
				break;
			}
		}
		
		
		//Placing the food ordered and price for the food ordered in the arrays
		while(c < newsize)
		{
			FoodOrdered[c] = menu[choice - 1];
			PriceOrdered[c] = TemporaryPrice;
			c++;
			break;
		}
		
		
		//If the same customer wishes to order more food/drinks
		cout << "\nDo you wish to continue: \n";
		cout << "\t[1]: Yes\n";
		cout << "\t[2]: No\n";
		cout << "Enter your choice: ";
		cin >> wish;
		
		
		//Only allowed to choose from the choice given
		while(wish != 1 && wish != 2)
		{
			cout << "Enter again: ";
			cin >> wish;
		}
	}while(wish == 1);
	

	//Calculating the price of the food and drinks ordered by the customer
	for(int i = 0; i < newsize; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			multiply = arr[i][0] * arr[i][1];
			total += multiply;
			break;
		}
	}
	
	
	tax = 0.08 * total;	//Inclusion of tax and delivery charge
	full_total = total + tax;	//New total after including tax and delivery charge


	cout << "\nOrder: RM " << total << endl;
	cout << "Tax and Delivery Charge: RM " << tax << endl;
	cout << "\nTotal: RM " << full_total;
	cout << "\nPayment: RM ";
	cin >> payment;
	
	
	//If the payment by the customer is insufficient
	while(payment < full_total)
	{
		cout << "Insufficient amount.\n";
		cout << "Payment: RM ";
		cin >> payment;
	}
	
	
	balance = payment - full_total;	//Balance that needs to be paid back to the customer
	
	
	//Receipt of the purchase
	cout << "\n\n\n\t\t=Receipt=\t\t\n\n";
	
	//Display the order, tax and delivery charge and the total amount that needs to be paid by the customer
	cout << "Food Ordered\t\t\tTotal Price\n\n";
	for(int i = 0; i < newsize; i++)
	{
		if (!FoodOrdered[i].empty() && PriceOrdered[i] != 0)
		{
			cout << FoodOrdered[i] << "\t\t\tRM "  << PriceOrdered[i] << endl;
		}
	}
	
	cout << "\n\nOrder: RM " << total;
	cout << "\nTax and Delivery: RM " << tax;
	cout << "\nTotal: RM " << full_total;
	cout << "\nPayment: RM " << payment;
	cout << "\nBalance: RM " << balance;
	
	
	//Time taken for the food to get delivered according to the location from the customer
	switch(location)
	{
		case 1:
			cout << "\nYour food will be delivered in 10 minutes. Thank you.";
			break;
		case 2:
			cout << "\nYour food will be delivered in 30 minutes. Thank you.";
			break;
		case 3:
			cout << "\nYour food will be delivered in 20 minutes. Thank you.";
			break;
		case 4:
			cout << "\nYour food will be delivered in 20 minutes. Thank you.";
			break;
		case 5:
			cout << "\nYour food will be delivered in 20 minutes. Thank you.";
			break;
		case 6:
			cout << "\nYour food will be delivered in 40 minutes. Thank you.";
			break;
		case 7:
			cout << "\nYour food will be delivered in 30 minutes. Thank you.";
			break;
	}
	
	
	total_customer += 1;	//Number of customers is added by 1 and passed back to main function as reference
	
	
	infile.close();
	
	
	return full_total;	//The total amount from the sale is sent back to main function
}


//Function to calculate the total sales of the day
double DailySales(double sales, double &total)	//Sales from every customer is passed as the parameter
{
	total += sales;	//The total sales is passed back to main function as reference
}

