#ifndef toolkit_clientdb_er_hpp
#define toolkit_clientdb_er_hpp

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
        bool insert(Connector& connector,const std::string& n1);
        bool insert(Connector& connector,const std::string& n1,const std::string& am);
        bool insert(Connector& connector,const std::string& n1,const std::string& am,const std::string& ap);
		bool download(Connector& connector);
        bool selectRandom(Connector& connector);
		
        virtual const char* toString();
        virtual void clean();
    };

}
}
#endif
