#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include <fstream>
#include <cstring>
namespace sdds {
    const int MAX_CHAR = 255;
   class Numbers {
       double* m_collection;
       char m_filename[MAX_CHAR];
       unsigned int m_collectionSize;
       bool m_originalFlag;
       bool m_addedFlag;
      unsigned int countLines(const char* filename);
      void sort(double* collectionPtr, unsigned int size);
   public:
       Numbers(const char* filename);
       Numbers();
       ~Numbers();
       Numbers(Numbers&);
       bool isEmpty() const;
       friend bool operator==(Numbers&, Numbers&);
       Numbers& operator=(Numbers&);
       void setEmpty();
       bool load();


   };
   
}
#endif // !SDDS_NUMBERS_H_

