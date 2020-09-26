from selenium import webdriver
import time
from PIL import Image
from selenium.webdriver.common.keys import Keys  # 导入 Keys库
import pytesseract
import re

# 获得验证码分区
driver = webdriver.Chrome()  # 打开浏览器

target = 'http://wxtp.hefei.cc/zt2020/tuanzhishum9_gcdxy/rank_t.php?type=detail&typename=%E7%9B%B4%E5%B1%9E%E9%AB%98%E6%A0%A1&typename1=%E5%AE%89%E5%BE%BD%E4%B8%AD%E5%8C%BB%E8%8D%AF%E5%A4%A7%E5%AD%A6&typename2=%E5%8C%BB%E8%8D%AF%E4%BF%A1%E6%81%AF%E5%B7%A5%E7%A8%8B%E5%AD%A6%E9%99%A2&typename3=2019%E7%BA%A7%E8%AE%A1%E7%AE%97%E6%9C%BA%E4%B8%8E%E6%8A%80%E6%9C%AF%E7%A7%91%E5%AD%A6%284%29%E7%8F%AD'

driver.get(target)  # 青年大学习网址
driver.maximize_window()  # 我们直接最大化
time.sleep(1)  # 沉睡俩秒

driver.save_screenshot('full_screen_image.png')  # 保存网页截图

element_code_img = driver.find_element_by_id('code-img')

left = element_code_img.location['x']
top = element_code_img.location['y']
right = element_code_img.location['x'] + element_code_img.size['width']
bottom = element_code_img.location['y'] + element_code_img.size['height']
im = Image.open('full_screen_image.png')
im = im.crop((left, top, right, bottom))
im.save('test.png')

words = pytesseract.image_to_string(Image.open('test.png'))

push_words = ''
for i in words:
    if i != ' ':
        push_words += i
element_seccode = driver.find_element_by_id('seccode')
element_seccode.click()  # 点击一下
element_seccode.send_keys(push_words)
element_seccode.send_keys(Keys.ENTER)  # 敲击一下ENTER键
source = driver.page_source  # 获得网页源码

time.sleep(5)
f = open('青年大学习网页源码.txt', 'w', encoding='GB2312')
f.write(source)
f.close()
driver.quit()  # 关闭浏览器，释放内存
with open('青年大学习网页源码.txt', 'r', encoding='gbk') as f:
    young_man_study = f.read()
    m = re.findall('[\u4e00-\u9fa5]+', young_man_study)
    print(m)
