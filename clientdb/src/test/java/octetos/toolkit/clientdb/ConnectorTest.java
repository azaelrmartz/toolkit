
package octetos.toolkit.clientdb;

import com.mysql.cj.jdbc.MysqlDataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sql.DataSource;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author areyes
 */
public class ConnectorTest 
{
    Connector connector;
    
    public ConnectorTest() 
    {
    }
    
    @BeforeClass
    public static void setUpClass() 
    {
    }
    
    @AfterClass
    public static void tearDownClass() 
    {
    }
    
    @Before
    public void setUp() 
    {
        MysqlDataSource ds = new MysqlDataSource();
        ds.setServerName("192.168.0.101");
        ds.setPort(3306);
        ds.setUser("develop");
        ds.setPassword("123456");
        ds.setDatabaseName("sis");
        try 
        {
            ds.setServerTimezone("UTC");
        } 
        catch (SQLException ex) 
        {
            //Logger.getLogger(ConnectorTest.class.getName()).log(Level.SEVERE, null, ex);
            fail(ex.getMessage());
        }
        
        connector = new Connector();
        try 
        {
            if(!connector.connect(ds))
            {
                fail("Fallo la conexion al servidor con el datasoruce " + ds);
            }
        } 
        catch (ClassNotFoundException | SQLException ex) 
        {
            //Logger.getLogger(ConnectorTest.class.getName()).log(Level.SEVERE, null, ex);
            fail(ex.getMessage());
        }
    }
    
    @After
    public void tearDown() 
    {
        connector.close();
        connector = null;
    }

    /**
     * Test of query method, of class Connector.
     */
    @Test
    public void testQuery()
    {
        System.out.println("Testing Connector.query");
        try 
        {
            ResultSet rs = connector.query("show tables");
            while (rs.next()) 
            {
                System.out.println(rs.getString(1));
            }
        } 
        catch (SQLException ex) 
        {
            //Logger.getLogger(ConnectorTest.class.getName()).log(Level.SEVERE, null, ex);
            fail(ex.getMessage());
        }
    }

    /**
     * Test of close method, of class Connector.
     */
    @Test
    public void testClose() 
    {
        
    }

    /**
     * Test of connect method, of class Connector.
     */
    @Test
    public void testConnect() throws Exception 
    {
        
    }
    
}
