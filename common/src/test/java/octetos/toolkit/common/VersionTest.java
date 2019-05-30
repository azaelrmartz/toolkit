
package octetos.toolkit.common;


import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import org.apache.maven.model.Model;
import org.apache.maven.model.io.xpp3.MavenXpp3Reader;
import org.codehaus.plexus.util.xml.pull.XmlPullParserException;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

/**
 *
 * @author areyes
 */
public class VersionTest {
    
    public VersionTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() throws XmlPullParserException, FileNotFoundException, IOException {      
        MavenXpp3Reader reader = new MavenXpp3Reader();
        Model model = reader.read(new FileReader("pom.xml"));
        System.out.println(model.getId());
        System.out.println(model.getGroupId());
        System.out.println(model.getArtifactId());
        System.out.println(model.getVersion());
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of getMajor method, of class Version.
     */
    @Test
    public void testGetMajor() {
        System.out.println("getMajor");
    }

    /**
     * Test of getMinor method, of class Version.
     */
    @Test
    public void testGetMinor() {
        System.out.println("getMinor");
    }

    /**
     * Test of getPatch method, of class Version.
     */
    @Test
    public void testGetPatch() {
        System.out.println("getPatch");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_4args() {
        System.out.println("set");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_3args() {
        System.out.println("set");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_short_short() {
        System.out.println("set");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_short() {
        System.out.println("set");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_VersionStage() {
        System.out.println("set");
    }

    /**
     * Test of set method, of class Version.
     */
    @Test
    public void testSet_long() {
        System.out.println("set");
    }

    /**
     * Test of toString method, of class Version.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
    }

    /**
     * Test of getBuild method, of class Version.
     */
    @Test
    public void testGetBuild() {
        System.out.println("getBuild");
    }

    /**
     * Test of setBuild method, of class Version.
     */
    @Test
    public void testSetBuild() {
        System.out.println("setBuild");
    }
    
}
