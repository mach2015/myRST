#include "Base.H"

namespace Foam
{
	class Derived
		:public Base
	{
		
	public:
		static const word typeName;

		virtual void hello() const;
		//Derived();
		Derived(const word&);
		Derived(const dictionary&);
		//~Derived();
		~Derived(){}
	};



}