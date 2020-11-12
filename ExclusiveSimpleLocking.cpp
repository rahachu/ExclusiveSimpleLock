#include "LockManager.h"
#include "Transaction.h"

int main(int argc, char const *argv[])
{
    LockManager lm;
    Transaction *t1 = new Transaction(&lm);
    cout << "Created transaction name T1" << endl;
    Transaction *t2 = new Transaction(&lm);
    cout << "Created transaction name T2" << endl;

    int a = 5;
    cout << "Created var a with address " << &a << endl;

    cout << "T1 try to read var a" << endl;
    t1->read(&a);

    cout << "T2 try to read var a" << endl;
    t2->read(&a);

    cout << "T2 try to write var a to 5" << endl;
    t2->write(&a,5);

    cout << "T1 try to write var a to 3" << endl;
    t1->write(&a,5);

    cout << "T1 commit" << endl;
    t1->commit();
    
    cout << "T2 try to read var a" << endl;
    t2->read(&a);

    int b = 5;
    cout << "Created var b with address " << &b << endl;

    cout << "T2 try to read var b" << endl;
    t2->read(&b);

    cout << "T1 try to read var b" << endl;
    t1->read(&b);

    cout << "T2 commit" << endl;
    t2->commit();

    cout << "T2 try to read var b" << endl;
    t2->read(&b);

    cout << "T1 try to read var b" << endl;
    t1->read(&b);
    return 0;
}
