#ifndef TOOLKIT_COMMON_ERROR_HPP
#define TOOLKIT_COMMON_ERROR_HPP

#include <string>
#include <exception>


namespace octetos
{
namespace toolkit
{
        class Error : public std::exception
        {
        public:
                /**
                 *\brief Codigo de erros genericos
                 * */
                enum Codes
                {
                        ERROR_NOTADDRESSED=1,
                        ERROR_FAILONCONTRUCTOR,
                        
                        ROOFCODE = 1001
                };                
                
                virtual ~Error() throw();
                virtual const char* what() const throw();
                Error(const std::string&, int code) throw();
                Error(const std::string&, int code,const std::string& filename,int lineNumber) throw();
                //contructor de copias
                Error(const Error&);
                //
                std::string getFilename();
                int getLineNumber();
                
                /**
                 * \brief returna una copia del objeto error y limpa el registro
                 * 
                 * */
                static Error get();                
                /**
                 * \brief Verifica si hay error en el registro.
                 * 
                 * \return returna true si hay un erro en el registro o falso en otro caso.
                 * */
                static bool check();    
                /**
                 * \brief registra un nuevo error
                 * 
                 * \return true si registro el error y falso si fallo(muy provablemento devido a que ya habia un error registrado)
                 * */
                static bool write(const Error& e);
	private:
                std::string brief;
                int code;
                static const Error* error;
                std::string filename;
                int lineNumber;
        };
}
}

#endif
