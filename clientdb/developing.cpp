#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>



#include "clientdb-mysql.hpp"

int main(int argc, char **argv)
{
	std::cout << octetos::toolkit::clientdb::getPakageName() << " v" << octetos::toolkit::clientdb::getPakageVersion().toString()<<std::endl;
        
        octetos::toolkit::clientdb::mysql::Datconnect mysqlSQLDat("192.168.0.101",3306,"sis","develop","123456");  
        octetos::toolkit::clientdb::mysql::Connector* connector = new octetos::toolkit::clientdb::mysql::Connector(); 
        bool flag = false;  
        try
        {
                flag = connector->connect(&mysqlSQLDat);
        }
	catch(octetos::toolkit::clientdb::SQLException ex)
	{
		std::cerr<<ex.what()<< std::endl;
	}
        if(flag)
        {
                printf("MySQL client version: %s\n", connector->serverDescription());
        }
        else
        {
                std::cerr<<"Fallo la conexion el servidor."<< std::endl;
        }        
        
        octetos::toolkit::clientdb::Datresult* dt = connector->query("show tables");
        octetos::toolkit::clientdb::Row*  row =  new octetos::toolkit::clientdb::mysql::Row (NULL);   
        octetos::toolkit::clientdb::Row*  rowT = row;
        /*do
        {
                delete row; //elimina el row anterior
                row = dt->next();// next crea un row mediante new Row() por lo que hay que liberar esta memoria posterior mente
                std::cout << (*row)[0] << std::endl;
        }
        while((*row)[0] != NULL);*/
        
#ifdef COLLETION_ASSISTANT
        std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
        delete rowT;
        delete dt;
        delete connector;
        return 0;    
}
