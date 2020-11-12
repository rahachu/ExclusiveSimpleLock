#include "LockManager.h"
#include <iostream>

using namespace std;

LockManager::LockManager(/* args */)
{
}

LockManager::~LockManager()
{
}

bool LockManager::lock(int *varToLock,void *funcWhoCall){
    if(this->lockedVar.count(varToLock)==0){
        queue<void *> *listFunction = new queue<void *>();
        listFunction->push(funcWhoCall);
        this->lockedVar.insert(pair<int *,queue<void *>>(varToLock,*listFunction));
        return true;
    }
    else{
        this->lockedVar.find(varToLock)->second.push(funcWhoCall);
        return false;
    }
}

bool LockManager::grant(int *varToLock,void *funcWhoCall){
    if (this->lockedVar.count(varToLock)==0)
    {
        return true;
    }
    return this->lockedVar.find(varToLock)->second.front() == funcWhoCall;
}

void LockManager::release(int *varToLock){
    this->lockedVar.find(varToLock)->second.pop();
}