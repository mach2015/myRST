#ifndef myBASE_H
#define myBASE_H

#include "word.H"
#include "Istream.H"
#include "scalar.H"
#include "dictionary.H"
#include "label.H"
#include "tmp.H"
//#include "string.H"
#include "foamString.H"
#include "HashTable.H"

namespace Foam
{

class Base
//	:public refCount
{
public:
	
    virtual void hello() const; 

    static const word typeName;

	typedef autoPtr<Base>(*MrConstructorPtr)(const dictionary& dict);

	//typedef Base(*MrsConstructorPtr)
	//(
	//const label& place,
	//const scalar& magnitude,
	//const Istream& dataFlow
	//);
	
	
//------------------------------------------------------------------------------------
	typedef HashTable<MrConstructorPtr, word, string::hash> MrConstructorTable;

	static MrConstructorTable* MrConstructorTablePtr_;

	static void constructMrConstructorTables();
	static void destroyMrConstructorTables();
	
	// given an extra subclass whose constructor inserts new entries into the hash table, templated on the Derived type:
	template<class DerivedType>
	class addMrConstructorToTable
	{
	public:

		static autoPtr<Base> New(const dictionary& dict)
		{
			return autoPtr<Base>(new DerivedType(dict));
		}

		addMrConstructorToTable
			(
			const word& lookup = DerivedType::typeName
			)
		{
			constructMrConstructorTables();
			MrConstructorTablePtr_->insert(lookup, New);
		}

		~addMrConstructorToTable()
		{
			destroyMrConstructorTables();
		}
	};

	//- Return a pointer to a new Derived created on freestore
	//  from dictionary
	static autoPtr<Base> New(const dictionary&);
//--------------------------------------------------------------------------
	typedef autoPtr<Base>(*MrsConstructorPtr)(const word&);

	typedef HashTable<MrsConstructorPtr, word, string::hash> MrsConstructorTable;

	static MrsConstructorTable* MrsConstructorTablePtr_;

	static void constructMrsConstructorTables();
	static void destroyMrsConstructorTables();

	// given an extra subclass whose constructor inserts new entries into the hash table, templated on the Derived type:
	template<class DerivedType>
	class addMrsConstructorToTable
	{
	public:

		static autoPtr<Base> New(const word& tpname)
		{
			return autoPtr<Base>(new DerivedType(tpname));
		}

		addMrsConstructorToTable
			(
			const word& lookup = DerivedType::typeName
			)
		{
			constructMrsConstructorTables();
			MrsConstructorTablePtr_->insert(lookup, New);
		}

		~addMrsConstructorToTable()
		{
			destroyMrsConstructorTables();
		}
	};

	//- Return a pointer to a new Derived created on freestore
	//  from dictionary
	
	static autoPtr<Base> New(const word&);
//-------------------------------------------------------------------------

	Base(const dictionary&){}

	Base(const word&){}

	virtual ~Base(){}

private:

};


} // End namespace Foam

#endif

// **************************************
