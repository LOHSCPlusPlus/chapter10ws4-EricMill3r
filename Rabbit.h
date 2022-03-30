using namespace std;
#include <fstream>
using namespace std;

class Rabbit{

  public:

    Rabbit();
    void print(ostream &out);
    void readFromUser();
    void readFromFile(ifstream &inFile);
    void inValid();
    bool getIsValid();
    
 
private: 
    
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
};
    