import os 
from pywinauto import application
import subprocess
import time
import pyautogui

class OpenReader():
	
	def OpenProgram1(self):
		Xpos=806
		Ypos=950
		nmbr_tabs=10

		pyautogui.PAUSE = 1			#Wait 1 second pause after each function call	
		pyautogui.FAILSAFE = True 	#move the mouse far up to the left corner will crash the program

		path_to_Hrpt_Reader = 'C:\\Ruag_program\\hrpt-reader.3.0.8\\ReadHRPT'		#Path to the HRPT Reader
		path_to_file1 = 'C:\\Ruag_program\\pictures\\2012-09-22_1134_M02.hpt'		#Path to the processed file 
		path_to_file2 = 'C:\\Ruag_program\\pictures\\FY3B_2012-05-01_1419.C10'		#Path to the processed file 


		p=subprocess.Popen([path_to_Hrpt_Reader, path_to_file1], stdout=subprocess.PIPE, stdin=subprocess.PIPE) 			#Opens a subprocess and then goes directly to the next line in the code

		time.sleep(5)
		pyautogui.press('enter')

		time.sleep(10)

		p.open([path_to_file2])

		print("hej")

	def OpenProgram2(self): #Robustare än new program
		
		path_to_Hrpt_Reader = 'C:\\Tools\\Satsignal\\hrpt-reader.3.0.8\\ReadHRPT'		#Path to the HRPT Reader
		path_to_file1 = 'C:\\Ruag_program\\pictures\\2012-09-22_1134_M02.hpt'		#Path to the processed file 
		path_to_file2 = 'C:\\Ruag_program\\pictures\\FY3B_2012-05-01_1419.C10'		#Path to the processed file 
		app = application.Application().start(path_to_Hrpt_Reader)					#Måste startas med denna
		app.HRPT_Reader_from_David_Taylor.MenuSelect('File->Open')
		# app.[window title].[control name]...
		app.Öppna.Edit.SetText('MetopA_2012-09-22_113446')
		app.Öppna.Öppna.Click()
		app.Open.WaitNot('visible')			
		
		app['HRPT Reader - '].MenuSelect('File->Open')			#Programmet ändrar namn beroende på vilken fil som öppnas
		app.Open.Edit.SetText('FY3B_2012-05-01_1419.C10')
		app.Open.Open.Click()
	def OpenNewFile(self):													#Hacksolution if time try to solve better 
		
		Xpos=806
		Ypos=950
		nmbr_tabs=10


		pyautogui.press('enter')

		for x in range(1,nmbr_tabs):
			pyautogui.press('tab')

		pyautogui.press('down')
		pyautogui.press('up')
		pyautogui.press('enter')
		#pyautogui.press('enter')

if __name__ == '__main__':
	try:
		openreader=OpenReader()
		openreader.OpenProgram2()
		#openreader.OpenNewFile()
	except KeyboardInterrupt:
		print("stop")