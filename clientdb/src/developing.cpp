#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>

#include "clientdb-er.hpp"

int main(int argc, char **argv)
{
    toolkit::clientdb::DatconectionMySQL mysqlConnector;
    mysqlConnector.host = "192.168.0.101";
    mysqlConnector.database = "business.alpha";
    mysqlConnector.usuario = "root";
    mysqlConnector.password = "k3yL0c41";
    mysqlConnector.port = 3306;    
    toolkit::clientdb::Connector connector;
    
    toolkit::Message flag = connector.connect(mysqlConnector);
    if(flag.isPass())
    {
        printf("SQL Server version: %s\n", connector.serverDescription());
    }
    else
    {
        std::cerr<<"Fallo la conexion el servidor de datos el cual respondio; "<< flag.what() << std::endl;
    }
    
    srand (time(NULL));
	int random = rand() % 10000 + 1;
    
    toolkit::clientdb::Persons* person1 = new toolkit::clientdb::Persons();
    std::string n1 = "n1-";
    n1 += std::to_string(random);
    if(person1->insert(connector,n1))
    {
		std::cout << "Inserted "<< n1 << std::endl;
	}
	else
	{
		std::cerr << "Fail "<< n1 << std::endl;
	}
    
    if(connector.commit())
    {
		std::cout << "Commit done " << std::endl;
	}
	else
	{
		std::cerr << "Commit fail"<< std::endl;
	}
	
    toolkit::clientdb::Persons* person2 = new toolkit::clientdb::Persons();
    if(person2->selectRandom(connector))
    {
		std::cout << "Select Random "<< person2->toString() << std::endl;
	}
	else
	{
		std::cerr << "Fail Slected random "<< n1 << std::endl;
	}
    
}
