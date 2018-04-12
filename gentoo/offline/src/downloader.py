
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
		       line = file.readline()
		   	       		
		finally:
		    file.close()
		    
    def display(self):		
		for key in self.listing:
			print(key)
        print('Scheduled {} downloads.'.format(len(self.listing)))

    def generate(self,filenameOut,dirDownload):
        fileOut= open(filenameOut,"w+")
		for key in self.listing:
			if isinstance(self.listing[key],str):
				fileOut.write('wget -P ' + dirDownload + self.listing[key])
			elif isinstance(self.listing[key],list):
				fileOut.write('wget -P ' + dirDownload + self.listing[key][0])
		
		fileOut.close()
		
					

            
            
            
            
print("Downloader 0.1")
downloader  = Downloader('d1.txt')
downloader.fragment()
downloader.display()
