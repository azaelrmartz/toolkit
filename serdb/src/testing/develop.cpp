#include <stdio.h>

#include "../Serdata.hpp"

int main(int argc, char **argv)
{
    business::serdata::DatconectionMySQL mysqlConnector;
    mysqlConnector.host = "192.168.0.101";
    mysqlConnector.database = "business.alpha";
    mysqlConnector.usuario = "root";
    mysqlConnector.password = "k3yL0c41";
    business::serdata::Connector connector(mysqlConnector);
    printf("MySQL client version: %s\n", connector.serverDescription());
    connector.connect(mysqlConnector);
}
