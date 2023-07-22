import glob, time, os
from selenium.webdriver.remote.webelement import WebElement
import os.path
from selenium import webdriver
from selenium.webdriver.common.by import By
from webdriver_manager.microsoft import EdgeChromiumDriverManager

# 定義好會用到的函式
# 這邊參考了網路上有人提供的拖拉式放檔案的方法，可以用在所有「拖曳你的檔案至此」區塊
# JavaScript: HTML5 File drop
# source            : https://gist.github.com/florentbr/0eff8b785e85e93ecc3ce500169bd676
# param1 WebElement : Drop area element
# param2 Double     : Optional - Drop offset x relative to the top/left corner of the drop area. Center if 0.
# param3 Double     : Optional - Drop offset y relative to the top/left corner of the drop area. Center if 0.
# return WebElement : File input

JS_DROP_FILES = "var k=arguments,d=k[0],g=k[1],c=k[2],m=d.ownerDocument||document;for(var e=0;;){var f=d.getBoundingClientRect(),b=f.left+(g||(f.width/2)),a=f.top+(c||(f.height/2)),h=m.elementFromPoint(b,a);if(h&&d.contains(h)){break}if(++e>1){var j=new Error('Element not interactable');j.code=15;throw j}d.scrollIntoView({behavior:'instant',block:'center',inline:'center'})}var l=m.createElement('INPUT');l.setAttribute('type','file');l.setAttribute('multiple','');l.setAttribute('style','position:fixed;z-index:2147483647;left:0;top:0;');l.onchange=function(q){l.parentElement.removeChild(l);q.stopPropagation();var r={constructor:DataTransfer,effectAllowed:'all',dropEffect:'none',types:['Files'],files:l.files,setData:function u(){},getData:function o(){},clearData:function s(){},setDragImage:function i(){}};if(window.DataTransferItemList){r.items=Object.setPrototypeOf(Array.prototype.map.call(l.files,function(x){return{constructor:DataTransferItem,kind:'file',type:x.type,getAsFile:function v(){return x},getAsString:function y(A){var z=new FileReader();z.onload=function(B){A(B.target.result)};z.readAsText(x)},webkitGetAsEntry:function w(){return{constructor:FileSystemFileEntry,name:x.name,fullPath:'/'+x.name,isFile:true,isDirectory:false,file:function z(A){A(x)}}}}}),{constructor:DataTransferItemList,add:function t(){},clear:function p(){},remove:function n(){}})}['dragenter','dragover','drop'].forEach(function(v){var w=m.createEvent('DragEvent');w.initMouseEvent(v,true,true,m.defaultView,0,0,0,b,a,false,false,false,false,0,null);Object.setPrototypeOf(w,null);w.dataTransfer=r;Object.setPrototypeOf(w,DragEvent.prototype);h.dispatchEvent(w)})};m.documentElement.appendChild(l);l.getBoundingClientRect();return l"

def drop_files(element, files, offsetX=0, offsetY=0):
    driver = element.parent
    isLocal = not driver._is_remote or '127.0.0.1' in driver.command_executor._url
    paths = []

    # ensure files are present, and upload to the remote server if session is remote
    for file in (files if isinstance(files, list) else [files]) :
        if not os.path.isfile(file) :
            raise FileNotFoundError(file)
        paths.append(file if isLocal else element._upload(file))

    value = '\n'.join(paths)
    elm_input = driver.execute_script(JS_DROP_FILES, element, offsetX, offsetY)
    elm_input._execute('sendKeysToElement', {'value': [value], 'text': value})

WebElement.drop_files = drop_files

#開啟瀏覽器
driver = webdriver.Edge(EdgeChromiumDriverManager().install())
driver.get('https://www.instagram.com/accounts/login/')
time.sleep(2)

# 設定帳號密碼
login_id = "mundane_img_everyday"
login_pd = "Alfonso920702"

#登入
driver.find_element(by=By.NAME, value = "username").send_keys(login_id)
driver.find_element(by=By.NAME, value = "password").send_keys(login_pd)
driver.find_element(By.XPATH, '//button[normalize-space()="登入"]').click()
time.sleep(2)

#進入主畫面
driver.get(f"https://www.instagram.com/{login_id}/")
time.sleep(2)

#點擊上傳按鈕
new_post_button = driver.find_element(By.CSS_SELECTOR,'[aria-label="新貼文"]')
new_post_button.click()
time.sleep(2)
dropzone = driver.find_element(By.CSS_SELECTOR, '[aria-label="表示圖像或影片等影音素材的圖示"]')
# 選擇一個圖片、影片
image_path = r"~/Downlaod/1120517.jpg"     #注意把路徑前面加上r，這樣才不會因為路徑中特定的字元讓程式不認得
dropzone.drop_files(image_path)
time.sleep(2)
# 縮放 (這邊選擇原始比例，如果要1:1那可以直接跳過這段)
driver.find_element(By.CSS_SELECTOR, '[aria-label="選擇「裁切」"]').click()
time.sleep(2)
# 挑選你要的比例，其他的請註解掉(前面加上#的意思)
driver.find_element(By.XPATH, '//button[normalize-space()="原始"]').click()
# driver.find_element(By.XPATH, '//button[normalize-space()="1:1"]').click()
# driver.find_element(By.XPATH, '//button[normalize-space()="4:5"]').click()
# driver.find_element(By.XPATH, '//button[normalize-space()="16:9"]').click()
# 下一步
time.sleep(2)
driver.find_element(By.XPATH, '//button[normalize-space()="下一步"]').click()
# 濾鏡選擇，這邊不選擇，直接下一步
time.sleep(2)
driver.find_element(By.XPATH, '//button[normalize-space()="下一步"]').click()

# 內文設計
message = """
腳本測試
"""
# 填寫內文
post = driver.find_element(By.CSS_SELECTOR, '[aria-label="撰寫說明文字……"]')
post.send_keys(message)
time.sleep(2)

# 送出
driver.find_element(By.XPATH, '//button[normalize-space()="分享"]').click()

# 關閉浮動視窗
driver.find_element(By.CSS_SELECTOR, '[aria-label="關閉"]').click()
time.sleep(20)