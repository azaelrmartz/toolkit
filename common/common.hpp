#ifndef TOOLKIT_COMMON_HPP
#define TOOLKIT_COMMON_HPP

#include <string>
#ifndef DEBUG
        #define COLLETION_ASSISTANT
#endif
namespace octetos
{
namespace toolkit
{
        class Error : public std::exception
        {
        public:
                virtual ~Error() throw();
                virtual const char* what() const throw();
                Error(const std::string brief, int code) throw();
	private:
                std::string brief;
                int code;
        };
        
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
        
        
	/**
	 * \brief Informacion de Version
	 * 
	 **/
	class Version: public Object
	{
	public:		
		enum Stage
		{
                        unknown,
                        snapshot,       
			alpha,
			beta,
                        rc,
			release
		};
		
	private:	
		short major;
		short minor;
		short patch;
                short tweak;
                unsigned long build;
		Stage stage;
                std::string name;
                
	public:
		short getMajor() const;
		short getMinor() const;
		short getPatch() const;
		unsigned long getBuild() const;
		Stage getStage() const;
                const std::string& getName() const;
                
		Version();
                void set(short major,short minor,short patch,Stage stage,unsigned long build, const std::string& name);
                void setNumbers(short major,short minor,short patch);
                void setNumbers(short major,short minor);
                void setNumbers(short major);
                void setStage(Stage stage);
                void setBuild(unsigned long build);
                void setName(const std::string& name);
		std::string toString() const;                
                void from(std::string text);                
	};


	
	/**
	 * \brief retorna la version actual de componente
	 **/
	Version getPakageVersion();
        std::string getPakageName();
}
}
#endif
