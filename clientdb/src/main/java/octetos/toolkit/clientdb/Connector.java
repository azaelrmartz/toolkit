
package octetos.toolkit.clientdb;


import com.microsoft.sqlserver.jdbc.SQLServerDataSource;
import com.mysql.cj.jdbc.MysqlDataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sql.DataSource;

/**
 *
 * @author areyes
 */
public class Connector 
{
    private Connection serverConnector;
    private DataSource datconection;
    
        
    public ResultSet query(String sql) throws SQLException
    {
        java.sql.Statement stmt = serverConnector.createStatement();
        return stmt.executeQuery(sql);
    }
    
    public void close() 
    {
        try 
        {
            if(serverConnector != null)serverConnector.close();
        } 
        catch (SQLException ex) 
        {
            Logger.getLogger(getClass().getName()).log(Level.SEVERE, null, ex);
        }
    }

    public boolean connect(DataSource ds) throws ClassNotFoundException, SQLException
    {
        if(ds == null) return false;
                
        if(ds instanceof MysqlDataSource)
        {
            Class.forName("com.mysql.cj.jdbc.Driver");        
        }
        else if(ds instanceof SQLServerDataSource)
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        }
        else
        {
            throw new SQLException("La instacia del datasource es desconocida.");
        }
            
        serverConnector = ds.getConnection();  
        
        if(ds instanceof MysqlDataSource)
        {
            serverConnector.setAutoCommit(false);            
        }
        else if(ds instanceof SQLServerDataSource)
        {
            serverConnector.setReadOnly(true);
        }
        else
        {
            throw new SQLException("La instacia del datasource es descnocida.");
        }
        datconection = ds;
        return true;
    }
}
