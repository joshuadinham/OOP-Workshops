#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {
   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   Numbers::Numbers(const char* filename)
   {
       Numbers();
       int len = strlen(filename);

       if (filename[0] != '\0' && len > 0 && MAX_CHAR > len)
       {
           strcpy(m_filename, filename);
           load();
       }
   }

   Numbers::Numbers()
   {
       this->setEmpty();
   }

   Numbers::~Numbers()
   {
       save();
       delete[] m_collection;
   }

   Numbers::Numbers(Numbers& copy)
   {
       *this = copy;
   }

   Numbers& Numbers::operator=(Numbers& right)
   {

       if (right.isEmpty() && !(*this == right))
       {
           m_originalFlag = false;
           delete[] m_collection;
           m_collectionSize = right.m_collectionSize;
           m_collection = new double[m_collectionSize];
           m_collection = right.m_collection;
       }
       
       return *this;
   }

   bool Numbers::load()
   {
       
       std::ifstream file;//input file stream
       file.open(m_filename);
       if (file.is_open())
       {
           while (file) {

           }
       }
       file.close();
   }

   bool Numbers::isEmpty() const
   {
       bool valid = true;
       valid = m_filename[0] != '\0' && m_collection != nullptr && m_collectionSize > 0;
       return valid;
   }

   void Numbers::setEmpty()
   {
       strcpy(m_filename, "\0");
       m_collection = nullptr;
       m_collectionSize = 0;
       m_originalFlag = true;
       m_addedFlag = false;
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

   bool operator==(Numbers& org, Numbers& copy)
   {
       bool same = true;
       same = strcmp(org.m_filename, copy.m_filename) == 0 && org.m_collectionSize == copy.m_collectionSize && *org.m_collection == *copy.m_collection && org.m_addedFlag == copy.m_addedFlag && org.m_originalFlag == copy.m_originalFlag;
       return same;
   }



   
   
}