#include "Base.H"

namespace Foam
{
	
	void Base::hello() const
	{
		Info << "hello from "<< typeName << endl;
	}

	const word Base::typeName("Base");

	//This line is needed because it is static
	Base::MrConstructorTable* Base::MrConstructorTablePtr_ = NULL;

	void Base::constructMrConstructorTables()
	{
		static bool constructed = false;
		// this is necessary because it will be called many times
		if (!constructed)
		{
			Base::MrConstructorTablePtr_ = new Base::MrConstructorTable;

			constructed = true;
		}
	}

	void Base::destroyMrConstructorTables()
	{
		if (Base::MrConstructorTablePtr_)
		{
			delete Base::MrConstructorTablePtr_;
			Base::MrConstructorTablePtr_ = NULL;
		}
	}

	autoPtr<Base> Base::New(const Foam::dictionary& dict)
	{
		// omitting error catching and debug statements

		word DerivedType(dict.lookup("type"));

		typename MrConstructorTable::iterator cstrIter
			= MrConstructorTablePtr_->find(DerivedType);

		return cstrIter()(dict);
	}
	//-------------------------------------------------------------
	Base::MrsConstructorTable* Base::MrsConstructorTablePtr_ = NULL;

	void Base::constructMrsConstructorTables()
	{
		static bool constructed = false;
		// this is necessary because it will be called many times
		if (!constructed)
		{
			Base::MrsConstructorTablePtr_ = new Base::MrsConstructorTable;

			constructed = true;
		}
	}

	void Base::destroyMrsConstructorTables()
	{
		if (Base::MrsConstructorTablePtr_)
		{
			delete Base::MrsConstructorTablePtr_;
			Base::MrsConstructorTablePtr_ = NULL;
		}
	}

	Foam::autoPtr<Base> Base::New(const word& tpname)
	{
		// omitting error catching and debug statements

		//word DerivedType(dict.lookup("type"));

		typename MrsConstructorTable::iterator cstrIter
			= MrsConstructorTablePtr_->find(tpname);

		return cstrIter()(tpname);
	}

}