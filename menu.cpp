/*Name: Michael Bryan
 Date : July 7, 2018
 Section : 1
 Assignment : HW #4
 Due Date : June 29, 2018 */

//-------------------------menu.cpp--------------------
#include "store.h"
#include <iostream>
using namespace std;

void menu();

int main()
{
    Store MyStore;
    
    char userMenuSelection;
    unsigned int invalidMenuCounter = 0;
    
    do
    {
        if (invalidMenuCounter == 0)
        {
            menu();
        }
        
        cin >> userMenuSelection;
        cin.ignore();
        userMenuSelection = toupper(userMenuSelection);
        
        switch (userMenuSelection)
        {
            case 'A':
            {
                char bookTitle[31], authorName[21], Typetemp;
                double price;
                Genre Final;
                
                cout << "Book Title: ";
                cin.getline(bookTitle,30);
                cout << "Author Name: ";
                cin.getline(authorName,20);
                do
                {
                    cout << "Genre (Only F,M,S,C): ";
                    cin >> Typetemp;
                    Typetemp = toupper(Typetemp);
                    if(Typetemp != 'F' && Typetemp != 'M' && Typetemp != 'S' && Typetemp != 'C')
                        cout << "Error, incorrect Genre. Please try Again.\n";
                }while (Typetemp != 'F' && Typetemp != 'M' && Typetemp != 'S' && Typetemp != 'C');
                do
                {
                    cout << "Price : $";
                    cin >> price;
                    if(price < 0)
                        cout << "Invalid Price. Please try Again.\n";
                }while (price < 0);
                
                if(Typetemp == 'F')
                    Final = FICTION;
                else if (Typetemp == 'M')
                    Final = MYSTERY;
                else if (Typetemp == 'S')
                    Final = SCIFI;
                else
                    Final = COMPUTER;
                
                MyStore.Insert(bookTitle, authorName, Final, price);
                invalidMenuCounter = 0;
                break;
            }
            case 'F':
            {
                char bookName[31], authorName[21], userChoice;
                do
                {
                    cout << "Search by (A)uthor or by (T)itle: ";
                    cin >> userChoice;
                    switch (toupper(userChoice))
                    {
                        case 'A':
                            cout << "Author Name: ";
                            cin >> authorName;
                            MyStore.FindAuthor(authorName);
                            break;
                        case 'T':
                            cout << "Title of book: ";
                            cin >> bookName;
                            MyStore.FindBook(bookName);
                            break;
                        default:
                            
                            cout << "Please try again. >";
                            break;
                    }
                    
                }while(toupper(userChoice) != 'A' && toupper(userChoice) != 'T');
                
                invalidMenuCounter = 0;
                break;
            }
            case 'S':
            {
                char bookName[31];
                
                cout << "Enter a Book Title: ";
                cin.getline(bookName, 30);
                MyStore.SellBook(bookName);
                invalidMenuCounter = 0;
                break;
            }
            case 'D':
            {
                MyStore.DisplayBooks();
                invalidMenuCounter = 0;
                break;
            }
            case 'G':
            {
                char genre;
                
                do
                {
                    cout << "Please select a Genre (F, M, S, C): ";
                    cin >> genre;
                    genre = toupper(genre);
                    if(genre != 'F' && genre != 'M' && genre != 'S' && genre != 'C')
                        cout << "Error, incorrect Genre. Please try Again.\n";
                }while (genre != 'F' && genre != 'M' && genre != 'S' && genre != 'C');
                
                MyStore.DisplayGenreBooks(genre);
                
                invalidMenuCounter = 0;
                break;
            }
            case 'M':
            {
                menu();
                invalidMenuCounter = 0;
                break;
            }
            case 'X':
            {
                cout << "Goodbye!\n";
                invalidMenuCounter = 0;
                break;
            }
            default:
            {
                cout << "Invalid option, please retry > ";
                invalidMenuCounter++;
                continue;
            }
        }
        if (userMenuSelection == 'X')
            break;
    } while (userMenuSelection == 'A' || userMenuSelection == 'F' || userMenuSelection == 'S' || userMenuSelection == 'D' || userMenuSelection == 'G' || userMenuSelection == 'M' || invalidMenuCounter >= 1);
    
    return 0;
}

void menu()
{
    cout << "A:   Add a book to inventory\n";
    cout << "F:   Find a book from inventory\n";
    cout << "S:   Sell a book\n";
    cout << "D:   Display the inventory list\n";
    cout << "G:   Genre summary\n";
    cout << "M:   Show this Menu\n";
    cout << "X:   eXit the program\n";
    cout << "> ";
};
