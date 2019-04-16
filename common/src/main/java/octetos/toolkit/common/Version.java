
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
	alpha,
	beta,
        rc,
	release
    };
		
    private int major;
    private int minor;
    private int patch;
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
	this.stage = Stage.unknown;
    }
    public Version(int major,int minor,int patch,Stage stage)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
	this.stage = stage;
    }
    public void set(int major,int minor,int patch,Stage stage)
    {
	this.major = major;
	this.minor = minor;
	this.patch = patch;
	this.stage = stage;    
    }
    @Override
    public String toString()
    {
	if((major < 0) | (minor < 0) | (patch < 0) | stage == Stage.unknown | stage == null)
	{//falla devido a que no esta inicializado
            return "";
	}
		
	String ver = "";
	ver += major;
	ver += ".";
	ver += minor;
	ver += ".";
	ver += patch;		

	switch (stage) 
        {
            case alpha:
                ver += "-alpha";
                break;
            case beta:
                ver += "-beta";
                break;
            case release:
                ver += "-release";
                break;
            default:
                break;
        }

	return ver;
    }
    
    public static final Version versionPakage = new Version(2,3,0,Version.Stage.beta);
}
