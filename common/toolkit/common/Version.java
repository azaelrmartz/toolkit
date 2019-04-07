
package toolkit.common;


public class Version
{
	public enum Stage
	{
		unknown,
		alpha,
		beta,
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
	
	}
	public Version(int major,int minor,int patch,Stage stage)
	{
		this.major = major;
		this.minor = minor;
		this.patch = patch;
		this.stage = stage;
	}
	public void set(int major,int minor,int patch,Stage stage)
	{}
	public String toString()
	{
		if((major < 0) | (minor < 0) | (patch < 0) | stage == Stage.unknown)
		{//falla devido a que no esta inicializado
			return "";
		}
		
		String ver = "";
		ver += major;
		ver += ".";
		ver += minor;
		ver += ".";
		ver += patch;		

		if(stage == Stage.alpha)
		{
			ver += "-alpha";
		}
		else if(stage == Stage.beta)
		{
			ver += "-beta";
		}
		else if(stage == Stage.release)
		{
			ver += "-release";
		}

		return ver;
	}
}
