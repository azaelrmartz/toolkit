#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <libpq-fe.h>

#include "clientdb-postgresql.hpp"

int main(int argc, char **argv)
{
    //comman psql -h 192.168.0.101 -U develop -d sis
    toolkit::clientdb::postgresql::Datasource postgreSQLSource("192.168.0.101",0,"sis","develop","123456");  
    toolkit::clientdb::postgresql::Connector connector; 
    bool flag = false;  
    try
    {
		flag = connector.connect(postgreSQLSource);
	}
	catch(toolkit::clientdb::SQLException ex)
	{
		std::cerr << ex.what()<< std::endl;
	}
    if(flag)
    {
        int lib_ver = PQlibVersion();
        printf("Version of libpq: %d\n", lib_ver);
    }
    else
    {
        std::cerr<<"Fallo la conexion el servidor."<< std::endl;
    }
    
    std::vector<std::vector<const char*>> lst;
    connector.query("select * from Persons",lst);
    for(auto row : lst)
    {
        std::cout << row[1] << std::endl;
    }
    
    int id = connector.insert("INSERT INTO Persons(name,age) VALUES('Juan',15.3)");
    std::cout<<"ID: " << id << std::endl;
    
    connector.close();
    return 0;    
}
