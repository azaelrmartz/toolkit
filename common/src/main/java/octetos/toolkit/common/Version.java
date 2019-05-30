
package octetos.toolkit.common;

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
				
    public int getMajor()
    {
        return major;
    }
    public int getMinor()
    {
	return minor;
    }
    public int getPatch()
    {
	return patch;
    }    
    public Version()
    {
	this.major = -1;
	this.minor = -1;
	this.patch = -1;
	this.stage = Stage.unknown;
        this.build = 0;
    }
    public void set(short major,short minor,short patch,Stage stage)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
	this.stage = stage;
    }
    public void set(short major,short minor,short patch)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
    }
    public void set(short major,short minor)
    {
	this.major = major;
	this.minor = minor;
    }
    public void set(short major)
    {
	this.major = major;
    }
    public void set(Stage stage)
    {
        this.stage = stage;
    }
    public void set(long build)
    {
        this.build = build;
    }
    
    /**
     * @return the build
     */
    public long getBuild() {
        return build;
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
    
    public static final Version versionPakage = new Version((short)2,(short)3,(short)0,Version.Stage.beta);

}
