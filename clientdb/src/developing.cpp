#include <stdio.h>
#include <iostream>
#include <stdlib.h> 

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
        std::cerr<<"Fallo la conexion el servidor de datos el cual respondio; "<<flag.what()<<std::endl;
    }
    
    
    srand((unsigned)time(0)); 
    int randNumber = 0;
    
    randNumber = (rand() % 10000) + 1;
    std::string n1 = "n1-";
    n1 += std::to_string(randNumber);
    toolkit::clientdb::Persons person1;
    if(person1.insert(connector,n1.c_str()))
    {
        //std::cout<<"Inserting "<< n1 << "..." <<std::endl;
    }
    else
    {
        //std::cerr<<"Fail "<< n1 << "..." <<std::endl;        
    }
    randNumber = (rand() % 10000) + 1;
    std::string am = "am-";
    am += std::to_string(randNumber);
    if(person1.insert(connector,n1.c_str(),am.c_str()))
    {
        //std::cout<<"Inserting "<< n1 << " "<< am << "..." <<std::endl;
    }
    else
    {
        //std::cerr<<"Fail "<< n1 <<" "<< am << "..." <<std::endl;        
    }
    randNumber = (rand() % 10000) + 1;
    std::string ap = "ap-";
    ap += std::to_string(randNumber);
    if(person1.insert(connector,n1.c_str(),am.c_str(),ap.c_str()))
    {
        //std::cout<<"Inserting "<< n1 << " "<< am << " " << ap << "..." <<std::endl;
    }
    else
    {
        //std::cerr<<"Fail "<< n1 <<" "<< am << " " << ap << "..." <<std::endl;        
    }
    
    //std::cout<<"comiting..."<<std::endl;
    
    connector.commit();
    
    if(person1.download(connector))
    {
        //std::cout<<"prev person1.toString(): "<<std::endl;
        std::cout<<"person1: " << person1.toString()<<std::endl;
        //std::cout<<"post person1.toString(): "<<std::endl;
    }
    else
    {
        std::cerr<<"person1: view Fail."<<std::endl;
    }   
}
