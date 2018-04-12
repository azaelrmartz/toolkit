
import wget
import os.path

class Downloader(object):
	def __init__(self, filename):
		self.filename = filename
        
	def fragment(self):	
		self.listing = {}
		try:
			file = open(self.filename,'r') 
			line = file.readline()
			while line:
				urls = line.split()				
				for i in range(len(urls)):			       
					splits = urls[i].split('/')
					key = splits[len(splits)-1]
					#si ya existe la llave
					if(self.listing.has_key(key)):					   					   
						#a gregar el nuevo valor
						if isinstance(self.listing[key],str):
							strOld = self.listing[key]
							newList = []
							newList.extend(strOld)
							newList.extend(urls[i])
						elif isinstance(self.listing[key],list):
							self.listing[key].extend(urls[i])
					else:
						self.listing[key] = urls[i]
						
				#print(line)#print(key + ' => ' + urls[i])				
					
				line = file.readline()   		
		finally:
			file.close()

	def display(self):		
		for key in self.listing:
			print(key)
		print('Scheduled {} downloads.'.format(len(self.listing)))
    
	def download(self,dirDownload):
		for key in self.listing:
			print('\n')
			if isinstance(self.listing[key],str):	
				if not os.path.lexists(dirDownload + '/' + key):
					print('Donwloading {} from {}..\n'.format(key,self.listing[key]))				
					downFilename = wget.download(self.listing[key],out=dirDownload)
				else:
					print('Already exist ' + dirDownload + '/' + self.listing[key])	
			elif isinstance(self.listing[key],list):
				for i in len(self.listing[key]):
					if not os.path.exists(dirDownload + '/' + key):
						print('Donwloading {} from {}...\n'.format(key,self.listing[key][i]))
						downFilename = wget.download(self.listing[key][i],out=dirDownload)
						if(downFilename):
							break
					else:
						print('Already exist ' + dirDownload + '/' + self.listing[key][i])
					

            
            
            
            
print("Downloader 0.1")
downloader  = Downloader('download.txt')
downloader.fragment()
downloader.display()
downloader.download('download')
