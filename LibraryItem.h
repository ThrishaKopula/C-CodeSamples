#ifndef  LIBRARYITEM_H
#define  LIBRARYITEM_H

#include <string>

/**
 * LibraryItem class provides basic operations for an item in a library
 */
class LibraryItem 
{
   public:
 
     /**
      *  return the indicator on whether the item is currently borrowed or not
      */
     virtual bool isOnLoan() = 0 ;

     /**
      *  borrow the item.
      *  return true if the item can be borrowed and false otherwise.
      */
     virtual bool borrow() = 0 ;

	 
     /**
      *  return the item.
      *  return true if the item can be returned and false otherwise.
      */
     virtual bool takeBack() = 0 ;

     /**
      *   return indicator whether a search string is found in this item
      */
     virtual bool search(std::string searchStr) = 0 ;
  
     /**
      *  return the library item's information a string
      */
     virtual std::string toString() = 0 ;
} ;

#endif
