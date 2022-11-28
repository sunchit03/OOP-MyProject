/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 2.0
// Date     November 29, 2022
// Author   Sunchit Singh (169146214)
// Description
// Extra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Sunchit Singh     November 11     String functions (MS1)
// Sunchit Singh     November 13    tolower, isalpha, trim (MS3)
// Sunchit Singh     November 28    alcpy (MS5)
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
namespace sdds {
   int strlen(const char* str);
   // copies up to len chars from src to des
   // if len is negative, it will copy up to null char
   // resulting a cstring in des in any case
   void strcpy(char* des, const char* src, int len = -1);
   int strcmp(const char* s1, const char* s2);
   char tolower(char ch);
   int isalpha(char ch);
   void trim(char word[]);
   char* alcpy(const char* cstr);
   void pause();
}
#endif // !
