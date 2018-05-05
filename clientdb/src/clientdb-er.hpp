#ifndef toolkit_clientdb_er_hpp
#define toolkit_clientdb_er_hpp

#include "clientdb.hpp"


namespace toolkit
{
namespace clientdb
{
	
    class ER
    {
    public:
        virtual std::string toString() = 0;
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
        bool insert(Connector& connector,const char* n1);
        bool insert(Connector& connector,const char* n1,const char* am);
        bool insert(Connector& connector,const char* n1,const char* am,const char* ap);
		bool download(Connector& connector);
        bool selectRamdom(Connector& connector);
		
        virtual std::string toString();
        virtual void clean();
    };

}
}
#endif
