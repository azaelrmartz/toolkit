#ifndef TOOLKIT_COMMON_OBJECT_HPP
#define TOOLKIT_COMMON_OBJECT_HPP

#ifndef DEBUG
        #define COLLETION_ASSISTANT
#endif


namespace octetos
{
namespace toolkit
{
        class Object
        {
        public:        
                Object();
                virtual ~Object();
                
#ifdef COLLETION_ASSISTANT
        protected:
                void addChild(Object*);
                void removeChild(Object*);
                unsigned int getCountChilds();                               
        private:
                unsigned int countChilds;
                Object* parent;
                const char* createdFile;
                unsigned int line;                
#endif
        };
}
}

#endif
