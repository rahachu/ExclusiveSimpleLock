#include <map>
#include <queue>

#ifndef LOCKMANAGER_H
#define LOCKMANAGER_H

using namespace std;

class LockManager
{
private:
    /* data */
    map <int *,queue<void *>> lockedVar;
public:
    LockManager(/* args */);
    ~LockManager();
    bool lock(int *varToLock,void *funcWhoCall);
    bool grant(int *varToLock,void *funcWhoCall);
    void release(int *varToLock);
};

#endif