#ifndef __BusinessDatabase_H__
#define __BusinessDatabase_H__

/* Add function prototypes here */

//const char* serverDescription();

struct DataconectionMySQL
{
    const char *host;
    const char *usuario;
    const char *password;
    const char *database;
    unsigned int puerto;
    const char *unix_socket;
    unsigned long client_flag;
};







class Connector
{
private:
    void* serverCennector;
public:
    Connector(DataconectionMySQL& connector);
    const char* serverDescription();
    bool connect(DataconectionMySQL& connector);
}

#endif
