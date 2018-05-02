#ifndef __BusinessSerdataER_hpp__
#define __BusinessSerdataER_hpp__


#include "Serdata.hpp"


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
