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
        const char* n1;
        const char* n2;
        const char* ns;
        const char* ap;
        const char* am;
        static const char* TABLE_NAME;
        ID id;

    public:
        bool insert(Connector& connector,const char* n1);
        bool insert(Connector& connector,const char* n1,const char* am);
        bool insert(Connector& connector,const char* n1,const char* am,const char* ap);
		bool download(Connector& connector);
		
        virtual const char* toString();
        virtual void clean();
    };

}
}
#endif
