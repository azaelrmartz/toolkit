#include <stdio.h>
#include <iostream>
#include "clientdb.hpp"

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
        std::cerr<<"Fallo la conexion el servidor de datos el cual respondio; "<<flag.what()<<std::endl;
    }
    
}
