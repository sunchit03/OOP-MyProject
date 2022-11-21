/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 2.0
// Date     November 13, 2022
// Author   Sunchit Singh (169146214)
// Description
// Extra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Sunchit Singh     November 11     String functions (MS1)
// Sunchit Singh     November 13    tolower, isalpha, trim (MS3)
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Utils.h"

namespace sdds {
   int strlen(const char* str) {
      int len = 0;
      while (str[len]) {
         len++;
      }
      return len;
   }
   void strcpy(char* des, const char* src, int len) {
      int i;
      for (i = 0; src[i] && (len < 0 || i < len); i++) {
         des[i] = src[i];
      }
      des[i] = 0; // turning the char array des in to a cString by null terminating it.
   }
   int strcmp(const char* s1, const char* s2) {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   char tolower(char ch) {
      if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
      return ch;
   }
   int isalpha(char ch) {
      return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
   }
   void trim(char word[]) {
      int i;
      while (word[0] && !isalpha(word[0])) {
         strcpy(word, word + 1);
      }
      i = strlen(word);
      while (i && !isalpha(word[i - 1])) {
         word[i-- - 1] = char(0);
      }
   }
}