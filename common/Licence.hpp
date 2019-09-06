#ifndef TOOLKIT_COMMON_LICENCE
#define TOOLKIT_COMMON_LICENCE

#include "Version.hpp"


namespace octetos
{
namespace toolkit
{
	
	class Licence : public Object
	{
	public:
		enum Type
		{
			GPL,
			LGPL
		};
		
		Type type;
		short year;
		std::string owner;
		std::string name_public;
		
		std::string getBrief() const;
	};
	
}
}

#endif
