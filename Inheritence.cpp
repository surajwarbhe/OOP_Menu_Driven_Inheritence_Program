/******************************************************************************

Design a base class with name, date of birth, blood group and another base class 
consisting of the data members such as height and weight. Design one more base 
class consisting of the insurance policy number and contact address. The derived 
class contains the data members’ telephone numbers and driving license number. 
a. Write a menu driven program to carry out the following operations:
i.  Build a master table 
ii. Display 
iii.Insert a new entry
iv. Delete entry   
v. Edit
vi. Search for a record

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class A
{
  public:
	string name, dob, bg;
};

class B
{
  public:
	int ht, wt;
};

class C
{
  public:
	string ipn, add;
};

class D : public C, public B, public A
{
	long int contact, lic_no;

  public:
	void accept();
	void display();
	int insert(D d[], int n);
	void search(D d[], int n);
	void edit(D d[], int n);
	int deleted(D d[], int n);
};

void D::accept()
{
	cout << "\nEnter the following details of the person";
	cin.ignore();
	cout << "\nName : ";
	cin >> name;
	cout << "\nDate of Birth(dd/mm/yyyy) : ";
	cin >> dob;
	cout << "\nBlood Group : ";
	cin >> bg;
	cout << "\nHeight(in cm) : ";
	cin >> ht;
	cout << "\nWeight(in kg) : ";
	cin >> wt;
	cin.ignore();
	cout << "\nInsurance Policy Number : ";
	cin >> ipn;
	cout << "\nAddress : ";
	cin >> add;
	cout << "\nContact No. : ";
	cin >> contact;
	cout << "\nLicense no. : ";
	cin >> lic_no;
}

void D::display()
{
	cout << endl
		 << name << "\t\t" << dob << "\t\t" << bg << "\t\t" << ht << "\t\t" << wt << "\t\t" << ipn << "\t\t" << add << "\t\t" << contact << "\t\t" << lic_no;
}

void D::edit(D d[10], int n)
{
	char c;
	int i;
	cout << "Enter Liscence Number of the record you want to edit : ";
	cin >> c;
	for (i = 0; i < n; i++)
	{
		if (c == d[i].lic_no)
			d[i].accept();
	}
}

void D::search(D d[10], int n)
{
	char c;
	int flag = 0;
	cout << "Enter the License Number you want to search : ";
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		flag = 1;
		if (c == d[i].lic_no)
		{
			cout << "\Person Details :\n";
			cout << endl
				 << "Name"
				 << "\t\t"
				 << "Date of Birth"
				 << "\t\t"
				 << "Blood Group"
				 << "\t\t"
				 << "Height"
				 << "\t\t"
				 << "Weight"
				 << "\t\t"
				 << "Insurance Policy No"
				 << "\t\t"
				 << "Address"
				 << "\t\t"
				 << "Contact No"
				 << "\t\t"
				 << "License no";
			cout << endl
				 << d[i].name << "\t\t" << d[i].dob << "\t\t" << d[i].bg << "\t\t" << d[i].ht << "\t\t" << d[i].wt << "\t\t" << d[i].ipn << "\t\t" << d[i].add << "\t\t" << d[i].contact << "\t\t" << d[i].lic_no;
			break;
		}
	}

	if (flag == 0)
	{
		cout << "Enter Valid License Number !!!";
	}
}

int D::insert(D d[10], int n)
{
	int k;
	cout << "Enter the number of entries you want to add : ";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		d[i + n].accept();
	}
	return n + k;
}

int D::deleted(D d[10], int n)
{
	char c;
	int i, flag = 0;
	cout << "Enter the License Number of person that you want to delete : ";
	cin >> c;
	for (i = 0; i < n; i++)
	{
		flag = 1;
		if (c == d[i].lic_no)
		{
			break;
		}
	}
	if (i == n)
	{
		cout << "\nPerson Not Found !!!\n";
	}
	while (i < n)
	{
		d[i] = d[i + 1];
		i++;
	}
	cout << "\nRecord Deleted Successfully...\n";
	n--;
	return n;
}

int main()
{
	int i, n, choice;
	D d[10];
	D d1;

	do
	{
		cout << "\n\tMENU"
			 << "\n(1) Accept Data"
			 << "\n(2) Display Data"
			 << "\n(3) Insert Data"
			 << "\n(4) Edit Data"
			 << "\n(5) Delete Data"
			 << "\n(6) Search Data"
			 << "\n(7) Exit";
		cout << "\nEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter the number of entries you want to add : ";
			cin >> n;
			for (i = 0; i < n; i++)
			{
				d[i].accept();
			}
			break;

		case 2:
			cout << "***********MASTER TABLE**************";
			cout << endl
				 << "Name"
				 << "\t\t"
				 << "Date of Birth"
				 << "\t\t"
				 << "Blood Group"
				 << "\t\t"
				 << "Height"
				 << "\t\t"
				 << "Weight"
				 << "\t\t"
				 << "Insurance Policy No"
				 << "\t\t"
				 << "Address"
				 << "\t\t"
				 << "Contact No"
				 << "\t\t"
				 << "License no";

			for (i = 0; i < n; i++)
			{
				d[i].display();
			}
			break;

		case 3:
			n = d1.insert(d, n);
			cout << "***********MASTER TABLE**************";
			cout << endl
				 << "Name"
				 << "\t\t"
				 << "Date of Birth"
				 << "\t\t"
				 << "Blood Group"
				 << "\t\t"
				 << "Height"
				 << "\t\t"
				 << "Weight"
				 << "\t\t"
				 << "Insurance Policy no"
				 << "\t\t"
				 << "Address"
				 << "\t\t"
				 << "Contact no"
				 << "\t\t"
				 << "License no";
			break;

		case 4:
			d1.edit(d, n);
			break;

		case 5:
			n = d1.deleted(d, n);
			cout << "***********MASTER TABLE**************";
			cout << endl
				 << "Name"
				 << "\t\t"
				 << "Date of Birth"
				 << "\t\t"
				 << "Blood Group"
				 << "\t\t"
				 << "Height"
				 << "\t\t"
				 << "Weight"
				 << "\t\t"
				 << "Insurance Policy no"
				 << "\t\t"
				 << "Address"
				 << "\t\t"
				 << "Contact no"
				 << "\t\t"
				 << "License no";

			for (i = 0; i < n; i++)
			{
				d[i].display();
			}
			break;

		case 6:
			d1.search(d, n);
			break;
		}
	} while (choice != 7);
}

