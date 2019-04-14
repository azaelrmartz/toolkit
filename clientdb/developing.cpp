#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>
#include <mysql.h>

#include "toolkit-clientdb-mysql.hpp"

int main(int argc, char **argv)
{
    toolkit::clientdb::mysql::Datconnect mysqlSQLSource("192.168.0.101",3306,"sis","develop","123456");  
    toolkit::clientdb::mysql::Connector connector; 
    bool flag = false;  
    try
    {
		flag = connector.connect(mysqlSQLSource);
	}
	catch(toolkit::clientdb::SQLException ex)
	{
		std::cerr<<ex.what()<< std::endl;
	}
    if(flag)
    {
        printf("MySQL client version: %s\n", mysql_get_client_info());
    }
    else
    {
        std::cerr<<"Fallo la conexion el servidor."<< std::endl;
    }
    
    /*
     std::vector<std::vector<const char*>> lst;
    if(connector.query("show tables",lst) == false)
    {
        std::cout << "Fallo la consuta" << std::endl;
    }
    for(auto row : lst)
    {
        std::cout << row[0] << std::endl;
    }
    */
        toolkit::clientdb::Datresult& dt = connector.query("show tables");
        toolkit::clientdb::mysql::Row rowMy(NULL);
        toolkit::clientdb::Row& row(rowMy);
        while((row = dt.next())[0]  != NULL)
        {
                std::cout << row[0] << std::endl;
        }
   
        
    
    
    
    connector.close();
    return 0;    
}
