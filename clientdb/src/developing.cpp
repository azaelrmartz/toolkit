#include <stdio.h>
#include <iostream>
#include "Serdata.hpp"

int main(int argc, char **argv)
{
    toolkit::serdata::DatconectionMySQL mysqlConnector;
    mysqlConnector.host = "192.168.0.101";
    mysqlConnector.database = "business.alpha";
    mysqlConnector.usuario = "root";
    mysqlConnector.password = "k3yL0c41";
    mysqlConnector.port = 3306;    
    toolkit::serdata::Connector connector;
    
    toolkit::Message flag = connector.connect(mysqlConnector);
    if(flag.isPass())
    {
        printf("MySQL client version: %s\n", connector.serverDescription());
    }
    else
    {
        std::cerr<<"Fallo la conexion el servidor de datos el cual respondio; "<<flag.what()<<std::endl;
    }
    
}
