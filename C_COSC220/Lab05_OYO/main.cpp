#include <iostream>

//#include "PersonData.h"
//#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

int main()
{
    int choice;
    bool Continue = true;
    PersonData* arr[10];
    int databaseSize = -1;
    string sholder;
    int iholder;
    bool bholder;
    double dholder;
    char cholder;
    while (Continue == true)
    {
        cout << "\n1. Add Personal Data Object" << endl;
        cout << "2. Add Customer Data Object" << endl;
        cout << "3. Add Prefered Customer Data Object" << endl;
        cout << "4. View Database Long Form " << endl;
        cout << "5. View Database Short Form" << endl;
        cout << "6. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            databaseSize++;
            arr[databaseSize] = new PersonData();
            // create object store in array
            cout << " \n Input First Name: ";
            cin >> sholder;
            arr[databaseSize]->setFirst(sholder);

            cout << " \n Input Last Name: ";
            cin >> sholder;
            arr[databaseSize]->setLast(sholder);

            cout << " \n Input Street Address: ";
            cin >> sholder;
            arr[databaseSize]->setAddress(sholder);

            cout << " \n Input City: ";
            cin >> sholder;
            arr[databaseSize]->setCity(sholder);

            cout << " \n Input State: ";
            cin >> sholder;
            arr[databaseSize]->setState(sholder);

            cout << " \n Input Zip Code: ";
            cin >> sholder;
            arr[databaseSize]->setZip(sholder);

            cout << " \n Input Phone Number: ";
            cin >> sholder;
            arr[databaseSize]->setPhone(sholder);

            cout << "\n\n";
        }

        if (choice == 2)
        {
            databaseSize++;
            //create object store in array

            arr[databaseSize] = new CustomerData();
            cout << " \n Input First Name: ";
            cin >> sholder;
            arr[databaseSize]->setFirst(sholder);

            cout << " \n Input Last Name: ";
            cin >> sholder;
            arr[databaseSize]->setLast(sholder);

            cout << " \n Input Street Address: ";
            cin >> sholder;
            arr[databaseSize]->setAddress(sholder);

            cout << " \n Input City: ";
            cin >> sholder;
            arr[databaseSize]->setCity(sholder);

            cout << " \n Input State: ";
            cin >> sholder;
            arr[databaseSize]->setState(sholder);

            cout << " \n Input Zip Code: ";
            cin >> sholder;
            arr[databaseSize]->setZip(sholder);

            cout << " \n Input Phone Number: ";
            cin >> sholder;
            arr[databaseSize]->setPhone(sholder);

            cout << " \n Input Customer Number: ";
            cin >> iholder;
            ((CustomerData*)arr[databaseSize])->setCustomerNumber(iholder);

            cout << " \n Does Customer Wish to be on mailing list y or n: ";
            cin >> cholder;
            ((CustomerData*)arr[databaseSize])->setMailingList(cholder);

            cout << "\n\n";
        }
        if (choice == 3)
        {
            databaseSize++;
            //create object store in array

            arr[databaseSize] = new PreferredCustomer();
            cout << " \n Input First Name: ";
            cin >> sholder;
            arr[databaseSize]->setFirst(sholder);

            cout << " \n Input Last Name: ";
            cin >> sholder;
            arr[databaseSize]->setLast(sholder);

            cout << " \n Input Street Address: ";
            cin >> sholder;
            arr[databaseSize]->setAddress(sholder);

            cout << " \n Input City: ";
            cin >> sholder;
            arr[databaseSize]->setCity(sholder);

            cout << " \n Input State: ";
            cin >> sholder;
            arr[databaseSize]->setState(sholder);

            cout << " \n Input Zip Code: ";
            cin >> sholder;
            arr[databaseSize]->setZip(sholder);

            cout << " \n Input Phone Number: ";
            cin >> sholder;
            arr[databaseSize]->setPhone(sholder);

            cout << " \n Input Customer Number: ";
            cin >> iholder;
            ((CustomerData*)arr[databaseSize])->setCustomerNumber(iholder);

            cout << " \n Does Customer Wish to be on mailing list y or n: ";
            cin >> cholder;
            ((CustomerData*)arr[databaseSize])->setMailingList(cholder);

            cout << "\n Input Purchase Amount :";
            cin >> dholder;
            ((PreferredCustomer*)arr[databaseSize])->purchaseAmount(dholder);
            cout << "\n\n";
        }

        if (choice == 4)
        {
            cout << arr[databaseSize]->getRecord();
        }

        if (choice == 5)
        {
            arr[databaseSize]->PrintRecord();
        }
        if (choice == 6)
        {
            Continue = false;
        }



        //counter++;
    }


    return 0;
}