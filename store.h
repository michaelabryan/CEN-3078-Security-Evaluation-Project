/*Name: Michael Bryan
 Date : July 7, 2018
 Section : 1
 Assignment : HW #4
 Due Date : June 29, 2018 */

//-------------------------store.h--------------------
#ifndef _STORE_H
#define _STORE_H

#include "book.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Store
{
public:
    Store();
    ~Store();
    void SetStore(int mSize, int cSize, double cashcashMoney);
    void Insert(const char* t, const char* a, Genre g, double p);
    int FindBook(const char* BookName);
    int FindAuthor(const char* AuthorName);
    void SellBook(const char* bookName);
    void DisplayBooks();
    void DisplayGenreBooks(char genreType);
    
    int getcurrentSize();
    int getmaxSize();
    
private:
    int maxSize;
    int currentSize;
    double cashRegisterAmt;
    
    Book * bookList;
    void Grow();
    void Shrink();
};

#endif
