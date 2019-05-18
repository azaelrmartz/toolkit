
package octetos.toolkit.clientdb;

/**
 *
 * @author areyes
 */
public class Datconnect 
{
    public enum ServerType
    {
        MySQL,
        PostgreSQL
    }
    private ServerType serverType;
    private String host;
    private String user;
    private String password;
    private String database;
    private int port;
    
    public Datconnect(ServerType serverType,String host,int port,String database,String user,String password)
    {
        this.host = host;
        this.user = user;
        this.password = password;
        this.database = database;
        this.port = port;
        this.serverType = serverType;
    }

    /**
     * @return the serverType
     */
    public ServerType getServerType() {
        return serverType;
    }

    /**
     * @return the host
     */
    public String getHost() {
        return host;
    }

    /**
     * @return the user
     */
    public String getUser() {
        return user;
    }

    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @return the database
     */
    public String getDatabase() {
        return database;
    }

    /**
     * @return the port
     */
    public int getPort() {
        return port;
    }
}
