import time
from selenium import webdriver
from selenium.webdriver.common.by import By

def change_name(name0):
    driver = webdriver.Chrome("./chromedriver/chromedriver.exe")

    try:
        driver.get('https://www.11meigui.com/tools/currency')

        name1 = driver.find_element(By.XPATH, "/html/body/main/div/table/tbody/'name0'/td/table[1]/tbody/tr[3]/td[5]")

        return name1


    except Exception as e:
        print(f'Error: {str(e)}')
        return None

    finally:
        driver.quit()


def get_selling_rate(date, currency_code):
    driver = webdriver.Chrome("./chromedriver/chromedriver.exe")

    try:
        # 打开网站
        driver.get('https://www.boc.cn/sourcedb/whpj/')
        # driver.get('https://srh.bankofchina.com/search/whpj/search_cn.jsp')
        # 输入日期
        date_input = driver.find_element(By.ID, 'erectDate')
        date_input.clear()
        date_input.send_keys(date)
        #
        date_input = driver.find_element(By.ID, 'nothing')
        date_input.clear()
        date_input.send_keys(date)

        # 选择货币
        currency_select = driver.find_element(By.ID, 'pjname')
        currency_select.send_keys(currency_code)

        # 点击查询按钮
        query_button = driver.find_element(By.CSS_SELECTOR, '#.main .search_btn')
        query_button.click()

        # 获取现汇卖出价
        selling_rate = driver.find_element(By.XPATH, '/html/body/div/div[4]/table/tbody/tr[2]/td[5]').text

        with open('result.txt', 'w') as f:
            f.write(selling_rate)

        return selling_rate

    except Exception as e:
        print(f'Error: {str(e)}')
        return None

    finally:
        # 关闭浏览器
        # time.sleep(20)
        driver.quit()


# 使用示例
date = '20211231'
currency_code = 'USD'
name = change_name((currency_code))
selling_rate = get_selling_rate(date, name)
print(selling_rate)

