#coding:utf-8
#读取文件目录,保存到txt文件中
#并再次读出,保存到list中
 
import os
 
#删除之前的列表文件
if os.path.exists('traininglist.txt'):
    os.remove('./traininglist.txt')
if os.path.exists('testlist.txt'):
    os.remove('./testlist.txt')

#创建training list 文件
fp = open('./traininglist.txt','w+')
Img_list = os.listdir('./pos/train')
for Name in Img_list:
    fp.write('cropped/pos/train/' + Name + ' '+ '1' + '\n')
Img_list = os.listdir('./neg/train')
for Name in Img_list:
    fp.write('cropped/neg/train/' + Name + ' '+ '0' + '\n')
	
#创建test list 文件
fp = open('./testlist.txt','w+')
Img_list = os.listdir('./pos/test')
for Name in Img_list:
    fp.write('cropped/pos/test/' + Name + '\n')
Img_list = os.listdir('./neg/test')
for Name in Img_list:
    fp.write('cropped/neg/test/' + Name + '\n')
	
fp.close()
