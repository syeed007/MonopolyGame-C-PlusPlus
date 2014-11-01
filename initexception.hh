/// \file initexception.hh
///
/// \brief Simple exception hierarchy for init excetions
// 

#ifndef INIT_EXCEPTION_HH
#define INIT_EXCEPTION_HH

#include <string>

/// A general error in init file handling
class InitException
{
public:
   virtual ~InitException(){};
};

/// Error in reading the init file
class FileError: public InitException
{
public:
   FileError( const std::string& desc ): errDesc_( desc ){}
   virtual ~FileError(){};
   std::string description() const{ return errDesc_; }

private:
   std::string errDesc_;
};

/// Type conversion failed (e.g. from string to int)
class TypeConversionError: public InitException
{
public:
   virtual ~TypeConversionError(){};
};

/// Indexing error
class IndexError: public InitException
{
public:
   virtual ~IndexError(){};
};


#endif
