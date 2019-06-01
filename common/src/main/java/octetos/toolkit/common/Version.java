
package octetos.toolkit.common;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import org.apache.maven.model.Model;
import org.apache.maven.model.io.xpp3.MavenXpp3Reader;
import org.codehaus.plexus.util.xml.pull.XmlPullParserException;

/**
 *
 * @author areyes
 */
public class Version extends Object
{
    public enum Stage
    {
	unknown,
        snapshot,
	alpha,
	beta,
        rc,
	release
    };
		
    private short major;
    private short minor;
    private short patch;
    private long build;
    private Stage stage;
    private String name;
    
    
    public short getMajor()
    {
        return major;
    }
    public short getMinor()
    {
	return minor;
    }
    public short getPatch()
    {
	return patch;
    }    
    public Stage getStage()
    {
        return stage;
    }
    public long getBuild()
    {
        return this.build;
    }
    public String getName()
    {
        return name;
    }
    public Version()
    {
	this.major = -1;
	this.minor = -1;
	this.patch = -1;
	this.stage = Stage.unknown;
        this.build = 0;
        this.name = "";
    }
    
    
    public void set(short major,short minor,short patch,Stage stage,long build,String name)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
	this.stage = stage;
        this.build = build;
        this.name = name;
    }
    
    public void setNumbers(short major,short minor,short patch)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
    }
    public void setNumbers(short major,short minor)
    {
	this.major = major;
	this.minor = minor;
    }
    public void setNumbers(short major)
    {
	this.major = major;
    }
    public void setStage(Stage stage)
    {
        this.stage = stage;
    }
    public void setBuild(long build)
    {
        this.build = build;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public Version(short major,short minor,short patch,Stage stage)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
	this.stage = stage;
    }
    @Override
    public String toString()
    {		
	String ver = "";
        if(major >= 0)
        {
            ver += major;
        }
        if(minor >= 0)
        {
            ver += ".";
            ver += minor;
        }
        if(patch >= 0)
        {
            ver += ".";
            ver += patch;		
        }
        
	switch (stage) 
        {
            case snapshot:
                ver += "-snapshot";
                break;
            case alpha:
                ver += "-alpha";
                break;
            case beta:
                ver += "-beta";
                break;
            case rc:
                ver += "-rc";
            case release:
                ver += "-release";
                break;
            default:
                break;
        }

	return ver;
    }
    
    public void parseString(String str)
    {
        
    }
    
    public static Version getPakageVersion() throws XmlPullParserException, FileNotFoundException, IOException 
    {
        MavenXpp3Reader reader = new MavenXpp3Reader();
        Model model = reader.read(new FileReader("pom.xml"));
        System.out.println(model.getId());
        System.out.println(model.getGroupId());
        Version version = new Version();
        version.parseString(model.getVersion());
        version.setName(model.getArtifactId());
        return version;
    }
}
