from enum import Enum, unique

class Version:
    
    @unique
    class Stage(Enum):
        unknown = 0
        snapshot = 1      
        alpha = 2
        beta = 3
        rc = 4
        release = 5
        
    def __init__(self):
        self.major = -1
        self.minor = -1
        self.patch = -1
        self.stage = Version.Stage.unknown
        self.build = 0
        
    def toString(self):
        ver = ""
        if self.major >= 0:
            ver += str(self.major)
        if self.minor >= 0:
            ver += "."
            ver += str(self.minor)
        if self.patch >= 0:
            ver += "."
            ver += str(self.patch)
        
        if self.stage == Version.Stage.snapshot:
            ver += str("-snapshot")
        elif self.stage == Version.Stage.alpha:
            ver += str("-alpha")
        elif self.stage == Version.Stage.beta:
            ver += str("-beta")
        elif self.stage == Version.Stage.rc:
            ver += str("-rc")
        elif self.stage == Version.Stage.release:
            ver += str("-release")
             
        return ver
 
    def setNumbers(self,major,minor,patch):
        self.major = major
        self.minor = minor
        self.patch = patch
        
    def setStage(self,stage):
        self.stage = stage
        
        
    def setBuild(self,build):
        self.build = build
        
    
		
def getPakageVersion():
    version = Version()
    version.setNumbers(3,7,1)
    version.setStage(Version.Stage.snapshot)
    return version
    
def getPakageName():
    return "toolkit-common"


