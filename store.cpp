/*Name: Michael Bryan
 Date : July 7, 2018
 Section : 1
 Assignment : HW #4
 Due Date : June 29, 2018 */

//-------------------------store.cpp--------------------
#include "store.h"


Store::Store()
{
    SetStore(5, 0, 0);
}

Store::~Store()
{
    delete [] bookList;
}

void Store::SetStore(int mSize, int cSize, double cashcashMoney)
{
    if (mSize < cSize+5)
        return;
    else
    {
        maxSize = mSize;
        currentSize = cSize;
        cashRegisterAmt = cashcashMoney;
        bookList = new Book[maxSize];
    }
}

void Store::Insert(const char* t, const char* a, Genre g, double p)
{
    bookList[currentSize++].Set(t, a, g, p);
    Grow();
}

void Store::Grow()
{
    if (currentSize == maxSize)
    {
        maxSize = currentSize + 5;
        Book * newBooks = new Book[maxSize];
        for(int i = 0; i < currentSize; i++)
            newBooks[i] = bookList[i];
        delete [] bookList;
        bookList = newBooks;
        
    }
    else
        return;
}

void Store::Shrink()
{
    if (currentSize < maxSize - 5)
    {
        maxSize = currentSize - 5;
        Book * newBooks = new Book[maxSize];
        for(int i = 0; i < currentSize; i++)
            newBooks[i] = bookList[i];
        delete [] bookList;
        bookList = newBooks;
    }
    else
        return;
}

int Store::FindBook(const char* BookName)
{
    for(int i = 0; i < currentSize; i++)
    {
        if (strcmp(bookList[i].GetTitle(),BookName) == 0)
            return i;
    }
    return -1;
}

int Store::FindAuthor(const char* AuthorName)
{
    for(int i = 0; i < currentSize; i++)
    {
        if (bookList[i].GetAuthor() == AuthorName)
            return i;
    }
    return -1;
}

void Store::SellBook(const char* bookName)
{
    int bookPosition = FindBook(bookName);
    
    if (bookPosition == -1)
        return;
    else
    {
        cashRegisterAmt += bookList[bookPosition].GetPrice();
        bookList[bookPosition].~Book();
        for (int i = bookPosition; i < currentSize; i++)
        {
            bookList[i] = bookList[i+1];
            if(i+2 == maxSize)
                break;
        }
        currentSize--;
    }
    Shrink();
    
}

void Store::DisplayBooks()
{
    if(currentSize == 0)
    {
        cout << "No books to display.\n\n";
        return;
    }
    else
    {
        cout << left << setw(33) << "Title" << setw(23) << "Author" << setw(10) << "Genre" << setw(10) << "Price\n\n";
        
        for(int i =0; i < currentSize; i++)
            bookList[i].Display();
    }
}

void Store::DisplayGenreBooks(char genreType)
{
    if(currentSize == 0)
    {
        cout << "No books to display.\n\n";
        return;
    }
    else
    {
        cout << left << setw(33) << "Title" << setw(23) << "Author" << setw(10) << "Genre" << setw(10) << "Price\n\n";
        for(int i =0; i < currentSize; i++)
        {
            if(bookList[i].GetGenre() == FICTION && genreType == 'F')
                bookList[i].Display();
            if(bookList[i].GetGenre() == MYSTERY && genreType == 'M')
                bookList[i].Display();
            if(bookList[i].GetGenre() == SCIFI && genreType == 'S')
                bookList[i].Display();
            if(bookList[i].GetGenre() == COMPUTER && genreType == 'C')
                bookList[i].Display();
        }
    }
}

int Store::getmaxSize()
{
    return maxSize;
}

int Store::getcurrentSize()
{
    return currentSize;
}
