#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class db
{
    int roll;
    char name[20];
    char Class[20];
    char Div[20];
    char dob[20];
    char bg[10], contact[20];
    char phone[20], license[20];

public:
    static int stdno;

    static void count()
    {
        cout << "\nNo. of objects created: " << stdno;
    }

    void fin()
    {
        cout << "\nInline Function!";
    }

    // Default constructor
    db()
    {
        roll = 1;
        strcpy(name, "John Blesswin");
        strcpy(Class, "II");
        strcpy(Div, "A");
        strcpy(dob, "01/01/2022");
        strcpy(bg, "B+ve");
        strcpy(contact, "Pune");
        strcpy(phone, "1234567890");
        strcpy(license, "ABC102030ABC");
        ++stdno;
    }

    // Copy constructor
    db(db *ob)
    {
        strcpy(name, ob->name);
        strcpy(dob, ob->dob);
        strcpy(Class, ob->Class);
        strcpy(Div, ob->Div);
        strcpy(bg, ob->bg);
        strcpy(contact, ob->contact);
        strcpy(phone, ob->phone);
        strcpy(license, ob->license);
        ++stdno;
    }

    // Member function to get data
    void getdata()
    {
        cout << "\n\nEnter:Name, Roll No., Class, Division, DOB, Blood Group, Contact, Phone, License\n";
        cin >> name >> roll >> Class >> Div >> dob >> bg >> contact >> phone >> license;
    }

    // Friend function to display data
    friend void display(db d);

    // Destructor
    ~db()
    {
        cout << "\n\n"
             << this->stdno << " - " << this->name << "(Object) is destroyed!";
    }
};

// Friend function definition
void display(db d)
{
    cout << "\n\nName: " << d.name << "\nRoll No.: " << d.roll << "\nClass: " << d.Class << "\nDivision: " << d.Div
         << "\nDOB: " << d.dob << "\nBlood Group: " << d.bg << "\nContact: " << d.contact << "\nPhone: " << d.phone
         << "\nLicense: " << d.license << endl;
}

// Static member initialization
int db::stdno;

int main()
{
    int n, i;
    db d1, *ptr[5];

    cout << "Default values:";
    display(d1);

    d1.getdata();
    cout << endl;
    display(d1);

    db d2(&d1);
    cout << "\n\nUse of copy constructor :";
    display(d2);

    cout << "\nHow many objects u want to create?:";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        ptr[i] = new db();
        ptr[i]->getdata();
    }

    for (i = 0; i < n; i++)
    {
        display(*ptr[i]);
    }

    db::count();

    for (i = 0; i < n; i++)
    {
        delete (ptr[i]);
    }

    cout << "\nObjects deleted!";
    return 0;
}
