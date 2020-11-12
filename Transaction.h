#include "LockManager.h"
#include <set>
#include <iostream>

using namespace std;

class Transaction
{
private:
    /* data */
    LockManager *lm;
    set<int *> usedVar;
public:
    Transaction(LockManager *lm);
    ~Transaction();
    void write(int *varToWrite,int newValue);
    void read(int *varToRead);
    void commit();
};
