#ifndef TOOLKIT_COMMON_LICENCE
#define TOOLKIT_COMMON_LICENCE

#include "Version.hpp"


namespace octetos
{
namespace toolkit
{
	
	class Licence
	{
	public:
		enum Type
		{
			GPL,
			LGPL
		};
		
		Type type;
	};
	
}
}

#endif
