import os

direct_path = 'C:\\Users\\15250\\Desktop\\math_list'  # 打开的文件夹
write_direct_path = 'C:\\Users\\15250\\Desktop\\Student_name\\un_online_student.txt' #这是等会要写进去名字的文件路径
file_list = os.listdir(direct_path)
#print(file_list)
name_list = open('class_name', 'r', encoding='utf-8')
class_name = name_list.read()
class_name = class_name.split()
num = 1  # 表示这是第几个文件
write_file = open(write_direct_path,'a',encoding='utf-8')
for f in file_list:
    #print(write_file)
    #write_file.write('这是第{}个文件'.format(num)+'\n')
    print('这是第{}个文件'.format(num))
    get_file = direct_path+'\\'+f
    #print(get_file)
    file = open(get_file, 'r', encoding='utf-8')  # 打开文件
    online_student = file.read()  # 这是一个str 从列表中判断人在不在这个大字符串中
    time_list = online_student.split() #切分列表要的是时间
    #write_file.write('上课时间是'+str(time_list[1])+'\n')
    print('时间是',time_list[1])
    for people in class_name:
        if people in online_student:
            pass
        else:
            write_file.write(people+'\n')
            print(people+'没来')
    num += 1
    file.close()
    #exit()
write_file.close()