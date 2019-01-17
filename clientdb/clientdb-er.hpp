#ifndef TOOLKIT_CLIENTDB_ER_HPP
#define TOOLKIT_CLIENTDB_ER_HPP

#include "clientdb.hpp"


namespace toolkit
{
namespace clientdb
{
	typedef unsigned int ID;
	
    class ER
    {
    public:
        virtual const char* toString() = 0;
        virtual void clean() = 0;
    };

	
    class Persons : public ER
    {
    private:
        std::string n1;
        std::string n2;
        std::string ns;
        std::string ap;
        std::string am;
        static const char* TABLE_NAME;
        ID id;

    public:
        bool insert(connectors::MySQL& connector,const std::string& n1);
        bool insert(connectors::MySQL& connector,const std::string& n1,const std::string& am);
        bool insert(connectors::MySQL& connector,const std::string& n1,const std::string& am,const std::string& ap);
		bool download(connectors::MySQL& connector);
        bool selectRandom(connectors::MySQL& connector);
		
        virtual const char* toString();
        virtual void clean();
    };

}
}
#endif
