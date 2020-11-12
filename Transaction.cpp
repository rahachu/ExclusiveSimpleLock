#include "Transaction.h"

Transaction::Transaction(LockManager *lm)
{
    this->lm = lm;
}

Transaction::~Transaction()
{
}

void Transaction::write(int *varToWrite, int newVal){
    if (lm->lock(varToWrite,this) || lm->grant(varToWrite,this))
    {
        *varToWrite = newVal;
        this->usedVar.insert(varToWrite);
        cout << this << " Success to write variable" << endl;
    }
    else
    {
        cout << this << " Fail to write, variable locked" << endl;
    }
}

void Transaction::read(int *varToRead){
    if (lm->lock(varToRead,this) || lm->grant(varToRead,this))
    {
        this->usedVar.insert(varToRead);
        cout << this << " Success read variable" << endl;
    }
    else
    {
        cout << this << " Fail to read, variable locked" << endl;
    }       
}

void Transaction::commit(){
    set<int *>::iterator itr;
    for (itr = this->usedVar.begin(); itr != this->usedVar.end(); ++itr)
    {
        this->lm->release(*itr);
    }
    this->usedVar.clear();
    cout << this << " Transaction commited, all variable released" << endl;
}