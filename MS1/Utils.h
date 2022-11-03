/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date     November 2, 2022
// Author   Sunchit Singh (169146214)
// Description
// Extra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Sunchit Singh     November 2     String functions
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
}
#endif // !
