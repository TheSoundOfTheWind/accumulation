import json
import re
import requests


# 基金代码、名称、简拼进行基金搜索 '''

search = '160632' 

url = 'http://fundsuggest.eastmoney.com/FundSearch/api/FundSearchAPI.ashx?m=1&key=' + search 

result = requests.post(url) # 发送请求

print('##############查询结果##############')

print(result.text) # 返回数据  

''' 通过基金编码获取估值 '''
code = '001532'
url = 'http://fundgz.1234567.com.cn/js/%s.js' % code
result = requests.get(url)
# 发送请求
data = json.loads(re.match(".*?({.*}).*", result.text, re.S).group(1))
print('##############基金详情##############')
print('基金编码：%s' % data['fundcode'])
print('基金名称：%s' % data['name'])
print('单位净值：%s' % data['dwjz'])
print('净值日期：%s' % data['jzrq'])
print('估算值：%s' % data['gsz'])
print('估算增量：%s%%' % data['gszzl'])
print('估值时间：%s' % data['gztime'])
