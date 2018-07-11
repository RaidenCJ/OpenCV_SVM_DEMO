# author by LYS 2017/5/24
# for Deep Learning course
'''
1. read the whole files under a certain folder
2. chose 10000 files randomly
3. copy them to another folder and save
'''
import os, random, shutil
 
 
def copyFile(fileDir):
    # 1
	pathDir = os.listdir(fileDir)
 
    # 2
	sample = random.sample(pathDir, 8)
	print sample
	
	# 3
	for name in sample:
		shutil.copyfile(fileDir+name, targetDir+name)
if __name__ == '__main__':
	fileDir = "./frameByframe/"
	targetDir = './random_pick_pictures/'
	copyFile(fileDir)