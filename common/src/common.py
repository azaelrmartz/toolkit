class Version:
	from enum import Enum
	class Stage(Enum):
		unknown=0
		alpha=1
		beta=2
		release=3
	major = 0
	minor = 0
	patch = 0
	stage = Stage.alpha

	def __init__(self):
		temp = 0
	
	def toString(self):
		ver = ""
		if self.major > -1 :
			ver = ver + str(self.major)
		if self.minor > -1:	
			if self.major > -1:		
				ver = ver + "."			
			ver = ver + str(self.minor)	
		if self.patch > -1:
			if self.major > -1 or self.minor > -1:
				ver = ver + "."
			ver = ver + str(self.patch)
		if self.stage == Version.Stage.alpha:
			ver = ver + "-alpha"
		elif self.stage == Version.Stage.beta:
			ver = ver + "-beta"
		elif self.stage == Version.Stage.release:
			ver = ver + "-release"

		return ver



