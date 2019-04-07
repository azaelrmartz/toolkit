import toolkit.common.Version;

public class Main 
{
	public static void main(String[] args) 
	{
		// Prints "Hello, World" to the terminal window.
		Version version = new Version(0,1,1,Version.Stage.alpha);
		System.out.println("Version :" + Version.versionPakage.toString());
		//System.out.println("Hello");
	}
}
