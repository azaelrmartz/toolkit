#ifndef TOOLKIT_COMMON_PACKAGE
#define TOOLKIT_COMMON_PACKAGE

#include "Version.hpp"
#include "Licence.hpp"

namespace octetos
{
namespace toolkit
{
	class Package : public Object
	{
	public:
		std::string name;
		std::string name_decorated;
		std::string brief;
		std::string url;
		Version version;
		Licence licence;
	};
	
}
}

#endif
