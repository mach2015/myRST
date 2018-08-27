#include "Derived.H"

namespace Foam
{

	Base::addMrsConstructorToTable<Derived> addDerivedTypeMrsConstructorToBaseTable_;

	const word Derived::typeName("Derived");
	
	void Derived::hello() const
	{
		Info << "hello from "<< typeName << endl;
	}

	Derived::Derived(const dictionary& dict)
		:Base(dict){}

	Derived::Derived(const word& tpname)
		: Base(tpname){}


	//Base::addMrConstructorToTable<Derived> addDerivedTypeMrConstructorToBaseTable_;
	//Derived(const std::string& tpname){}

}
