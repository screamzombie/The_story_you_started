# Python程序设计 自主学习任务一 实验环境:python 3.7 win10
import requests  # 下载requests库  pip install requests
import re  # python 自带的正则表达式模块
import random  # python 自带的随机数模块
import os

path = ''  # 储存图片的文件地址


def mkdir(key):
    global path  # 当然是全局变量了啊
    path = 'F:\\'+key
    if os.path.exists(path):  # 判断文件夹存不存在
        path += str(random.randint(1, 100))  # 存在的话就增加一个随机数在后面
        os.makedirs(path)  # 创建文件夹
    else:
        os.makedirs(path)  # 不存在同名文件夹就直接创建


keyword = input("请输入要搜索的关键字")
page = 0  # 等一下用来表示页数
PAGE = int(input("想要下载多少页呢?"))  # 随便搜一个小姐姐有20000+张图片，全部下载，我硬盘估计要爆
mkdir(keyword)  # 这是我自己写的函数，虽然名字很有官方那味
for i in range(PAGE):  # 第一页第二页。。。。。。
    url = 'https://image.baidu.com/search/flip?tn=baiduimage&ie=utf-8&word={}&pn={}'.format(
        keyword, page)  # 百度图片的url，旧版，新版貌似没有翻页功能也许是我太菜了，但是在首页上也只能看到部分图片，无所谓
    result = requests.get(url)  # 访问网址，也就是百度的url啦，上面的填好后可以复制到浏览器地址栏中访问，验明真身
    temp = result.text  # 得到网页的源码
    ls = re.findall(r'"objURL":"(.*?)"', temp, re.S)  # 正则表达式，搜索到图片链接，返回的是一个列表
    for arr in ls:
        print('当前页数：'+str(i+1)+" 正在搜索：" + str(arr))
        try:  # 因为图片不一定下载的了啊
            pics = requests.get(arr, timeout=7)  # 下载图片，timeout=7 表示超过七秒钟，就报错
        except:
            print('链接错误')
            continue
        fq = open(path+'//'+keyword +
                  (str(random.randrange(0, 1000, 1))+'.jpg'), 'wb')  # 以二进制的形式打开一个文件，当然现在它还是空空的
        fq.write(pics.content)  # 把二进制数据写进去
        # fp.close()#对不起我傻逼了，这句不要！！！！
    page += 20  # 因为旧版百度图片一页只会显示20张图片，每次翻页后pn就会增加20，详细的自己打开网址查看

print('下载完毕！')  # 你的小姐姐下载好了啊！
