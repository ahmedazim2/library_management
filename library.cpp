#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;
struct Date
{
    int day{}, month{}, year{};
};

struct Book
{
    int id{};
    double price{};
    Date date;
    Date var3;
};
struct Library
{
    int num = 0;
    Book books[N];
};
void listOptions()
{
    cout << "~~~~~~~~~Welcome!~~~~~~~~~~" << endl;
    cout << "0: Exit" << endl;
    cout << "1: Add" << endl;
    cout << "2: Show" << endl;
    cout << "3: Delete" << endl;
    cout << "4: Sort" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void add(Library *p)
{
    if (p->num >= N)
    {
        int var1{};
        double var2{};

        cout << "Input Book ID:" << endl;
        cin >> var1;
        cout << "Input Price: " << endl;
        cin >> var2;
        cout << "Input Date (dd mm yyyy): " << endl;
        cin >> p->books[p->num].var3.day >> p->books[p->num].var3.month >> p->books[p->num].var3.year;
        cout << "Library is full" << endl;
        return;
    }
    cout << "Input Book ID: " << endl;
    cin >> p->books[p->num].id;

    bool uniqueID = false;
    while (!uniqueID)
    {
        uniqueID = true;
        for (int i = 0; i < p->num; i++)
        {
            if (p->books[i].id == p->books[p->num].id)
            {
                cout << "Input Book ID: " << endl;
                cin >> p->books[p->num].id;
                uniqueID = false;
                break;
            }
        }
    }

    cout << "Input Price: " << endl;
    cin >> p->books[p->num].price;

    cout << "Input Date (dd mm yyyy): " << endl;
    cin >> p->books[p->num].date.day >> p->books[p->num].date.month >> p->books[p->num].date.year;

    p->num++;
}
void show(Library *p)
{

    Book *books = p->books;

    if (p->num == 0)
    {
        cout << "There is no books in the library" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < p->num; i++)
        {
            const Book &book = books[i];
            cout << setfill('0') << setw(3) << book.id << "     ";
            cout << fixed << setprecision(2) << book.price << "   ";
            cout << setfill('0') << setw(2) << book.date.day << "-";
            cout << book.date.month << "-";
            cout << book.date.year << endl;
        }
    }
}
void del(Library *p)
{
    if (p->num == 0)
    {
        cout << "The library is empty." << endl;
        return;
    }

    int promptID;
    cout << "Enter the ID to be deleted" << endl;
    cin >> promptID;

    bool found = false;
    for (int i = 0; i < p->num; i++)
    {
        if (p->books[i].id == promptID)
        {
            for (int j = i; j < p->num - 1; j++)
            {
                p->books[j] = p->books[j + 1];
            }
            p->num--;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "The ID cannot be found" << endl;
    }
}

void sort_id(Library *p)
{
    for (int i = 0; i < p->num; i++)
    {
        for (int j = 0; j < p->num - 1; j++)
        {
            if (p->books[j].id > p->books[j + 1].id)
            {
                Book temp = p->books[j];
                p->books[j] = p->books[j + 1];
                p->books[j + 1] = temp;
            }
        }
    }
}
void sort_date(Library *p)
{
    for (int i = 0; i < p->num; i++)
    {
        for (int j = 0; j < p->num - 1; j++)
        {
            if (p->books[j].date.year > p->books[j + 1].date.year || (p->books[j].date.year == p->books[j + 1].date.year && p->books[j].date.month > p->books[j + 1].date.month) || (p->books[j].date.year == p->books[j + 1].date.year && p->books[j].date.month == p->books[j + 1].date.month && p->books[j].date.day > p->books[j + 1].date.day))
            {
                Book temp = p->books[j];
                p->books[j] = p->books[j + 1];
                p->books[j + 1] = temp;
            }
            else if (p->books[j].date.year == p->books[j + 1].date.year && p->books[j].date.month == p->books[j + 1].date.month && p->books[j].date.day == p->books[j + 1].date.day)
            {
                if (p->books[j].id > p->books[j + 1].id)
                {
                    Book temp = p->books[j];
                    p->books[j] = p->books[j + 1];
                    p->books[j + 1] = temp;
                }
            }
        }
    }
}
void sort(Library *p)
{
    int n;
    cout << "1: Sort by ID" << endl;
    cout << "2: Sort by Date" << endl;
    cin >> n;
    if (n == 1)
    {
        sort_id(p);
    }
    else if (n == 2)
    {
        sort_date(p);
    }
}
void init(Library *p)
{
    p->books[p->num].id = 3;
    p->books[p->num].price = 10.5;
    p->books[p->num].date.day = 15;
    p->books[p->num].date.month = 1;
    p->books[p->num].date.year = 1990;
    (p->num)++;
    p->books[p->num].id = 2;
    p->books[p->num].price = 20.55;
    p->books[p->num].date.day = 15;
    p->books[p->num].date.month = 2;
    p->books[p->num].date.year = 2024;
    (p->num)++;
    p->books[p->num].id = 4;
    p->books[p->num].price = 10.5;
    p->books[p->num].date.day = 20;
    p->books[p->num].date.month = 2;
    p->books[p->num].date.year = 2021;
    (p->num)++;
    p->books[p->num].id = 1;
    p->books[p->num].price = 30.1;
    p->books[p->num].date.day = 20;
    p->books[p->num].date.month = 2;
    p->books[p->num].date.year = 2021;
    (p->num)++;
}
int main()
{
    Library lib;
    lib.num = 0;
    init(&lib);
    int opt;

    do
    {
        listOptions();
        cin >> opt;

        switch (opt)
        {
        case 0:
            cout << "Bye!" << endl;
            break;
        case 1:
            add(&lib);
            break;
        case 2:
            show(&lib);
            break;
        case 3:
            del(&lib);
            break;
        case 4:
            sort(&lib);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
        cout << endl;
    } while (opt != 0);
    return 0;
}