#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#include <string>

#include "Message.hpp"
#include "Object.hpp"
#include "Version.hpp"
#include "Package.hpp"
#include "Licence.hpp"


namespace octetos
{
namespace toolkit
{
	/**
	 * \brief retorna la version actual de componente
	 **/
	Version getPakageVersion();
	std::string getPakageName();
	
	/**
	 * \brief retorna la informacion del paquete usese ne lugar getPakageVersion y getPakageName
	 **/
	Package getPackageInfo();
	
}
}
#endif
