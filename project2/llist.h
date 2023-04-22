#include "record.h"
#include <ostream>

class llist
{
private:
    record *start;
    char filename[20];

    llist& operator=(const llist&);

    friend std::ostream& operator<<(std::ostream&, const llist&);

    int readfile();

    int writefile();

    void cleanup();

public:
    llist();

    llist(char[]);

    llist(const llist&);

    ~llist();

    void addRecord(int, char [], char []);

    int findRecord(int);

    void printAllRecords();

    int deleteRecord(int);
};