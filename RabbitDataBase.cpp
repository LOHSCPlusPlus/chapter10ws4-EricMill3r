#include "RabbitDataBase.h"
#include <fstream>
#include <iostream>
#include "ReadUtils.h"
using namespace std;


  RabbitDataBase::RabbitDataBase() {
        int numRabbits = 0;
        read();
      }
      
  
  void RabbitDataBase::read() {
      ifstream rabbitFile("rabbits.txt");
      int numRabbits = 0;
      while(rabbitFile.peek() != EOF && numRabbits <           MAX_RABBITS) {
          rabbitArray[numRabbits].readFromFile(rabbitFile);
          numRabbits++;
      }
  }
  
  
  
  void RabbitDataBase::print (ostream &out, bool printIndex) {
      for (int index = 0; index < MAX_RABBITS; index++) {
          if (rabbitArray[index].getIsValid()) {
              if (printIndex) {
                  out << "Index " << index << ": ";
              }
              rabbitArray[index].print(out);
          } 
      }
  }
  
  void RabbitDataBase::save() {
      ofstream out("rabbits.txt");
      print(out, false);
  }
  
  void RabbitDataBase::remove() {
      int index = 0;
      do {
          index = readInt("Enter an index to remove                between 0 and 500: ");
      }while (index < 0 || index >= MAX_RABBITS);
      rabbitArray[index].inValid();
  }

  void RabbitDataBase::addRabbit() {
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].getIsValid() == false) {
            rabbitArray[index].readFromUser();
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
}
