/*Name: Michael Bryan
 Date : July 7, 2018
 Section : 1
 Assignment : HW #4
 Due Date : June 29, 2018 */

//-------------------------book.cpp--------------------
#include "store.h"
#include "book.h"


Book::Book()
{
    Set("None", "None", COMPUTER, 0.00);
}

void Book::Set(const char* t, const char* a, Genre g, double p)
{
    if((g == FICTION || g == MYSTERY || g == SCIFI || g == COMPUTER) && p >= 0 && strlen(t) <= 30 && strlen(a) <= 20)
    {
        for(int i = 0; i < strlen(t); i++)
            title[i] = t[i];
        for(int i = 0; i < strlen(a); i++)
            author[i] = a[i];
        type = g;
        price = p;
    }
    else
        return;
    
}

const char* Book::GetTitle() const
{    
    return title;
}

const char* Book::GetAuthor() const
{
    for (int i = 0; i < strlen(author); i++)
        cout << author[i];
    
    return author;
}

double Book::GetPrice() const
{
    return price;
}

Genre Book::GetGenre() const
{
    return type;
}

void Book::Display() const
{
    cout << setprecision(2) << fixed;
    cout << left;
    for(int i =0; i < strlen(title); i++)
    {
        if (i == strlen(title) -1)
            cout << setw(30);
        cout << title[i];
    }
    for(int i = 0; i < strlen(author); i++)
    {
        if (i == strlen(author)-1)
            cout << setw(20);
        cout << author[i];
    }
    cout << setw(10);
    if (type == 0)
        cout << "Fiction";
    else if (type == 1)
        cout << "Mystery";
    else if (type == 2)
        cout << "Sci-fi";
    else if (type == 3)
        cout << "Computer";
    cout << '$'<< right << setw(6) << price << '\n';
    
};















