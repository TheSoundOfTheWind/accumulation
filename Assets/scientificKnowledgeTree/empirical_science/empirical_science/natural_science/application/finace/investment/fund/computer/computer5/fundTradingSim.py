#!/usr/bin/python3
import math
import datetime
import re
import dateutil.parser as parser
import pandas as pd
import requests
import numpy as np
def fundHightLow(filename, id):
    f = open(filename, "r")
    for line in f:
        if line[0] == '#':
            continue
        a = line.split( )
        if len(a) == 0:
            continue
        b = a[0]
        if b == id:
            return a

def get_fund_k_history(fund_code: str, pz: int = 40000) -> pd.DataFrame:
    '''
    根据基金代码和要获取的页码抓取基金净值信息

    Parameters
    ----------
    fund_code : 6位基金代码
    page : 页码 1 为最新页数据

    Return
    ------
    DataFrame : 包含基金历史k线数据
    '''
    # 请求头
    EastmoneyFundHeaders = {
        'User-Agent': 'EMProjJijin/6.2.8 (iPhone; iOS 13.6; Scale/2.00)',
        'GTOKEN': '98B423068C1F4DEF9842F82ADF08C5db',
        'clientInfo': 'ttjj-iPhone10,1-iOS-iOS13.6',
        'Content-Type': 'application/x-www-form-urlencoded',
        'Host': 'fundmobapi.eastmoney.com',
        'Referer': 'https://mpservice.com/516939c37bdb4ba2b1138c50cf69a2e1/release/pages/FundHistoryNetWorth',
    }
    # 请求参数
    data = {
        'FCODE': f'{fund_code}',
        'appType': 'ttjj',
        'cToken': '1',
        'deviceid': '1',
        'pageIndex': '1',
        'pageSize': f'{pz}',
        'plat': 'Iphone',
        'product': 'EFund',
        'serverVersion': '6.2.8',
        'version': '6.2.8'
    }
    url = 'https://fundmobapi.eastmoney.com/FundMNewApi/FundMNHisNetList'
    json_response = requests.get(
        url, headers=EastmoneyFundHeaders, data=data).json()
    rows = []
    columns = ['日期', '单位净值', '累计净值', '涨跌幅']
    if json_response is None:
        return pd.DataFrame(rows, columns=columns)
    datas = json_response['Datas']
    if len(datas) == 0:
        return pd.DataFrame(rows, columns=columns)
    rows = []
    for stock in datas:
        date = stock['FSRQ']
        rows.append({
            '日期': date,
            '单位净值': stock['DWJZ'],
            '累计净值': stock['LJJZ'],
            '涨跌幅': stock['JZZZL']
        })

    df = pd.DataFrame(rows)
    df['单位净值'] = pd.to_numeric(df['单位净值'], errors='coerce')

    df['累计净值'] = pd.to_numeric(df['累计净值'], errors='coerce')

    df['日期'] = pd.to_datetime(df['日期'], errors='coerce')
    return df
        

print("//----------------------------------------------------------------")
id  = input("fund id:")
list = fundHightLow("../../buy_fund/混合基金.txt", id)
print("id %s" % list[0])
print("name %s" % list[1])
print("volatility %s" % list[2])
print("sharpe rate %s" % list[3])
print("maximum drawdown %s" % list[4])
print("maximum fund equity %s" % list[5])
print("unit principal %s" % list[7])
A = float(list[7])
B = float(list[5])
D = float(list[4])/100.0
F = float(list[3])

df = get_fund_k_history(list[0])
#df = np.arrary(df)
df2 = tuple(df['累计净值'])
df3 = str(df2)
df3=df3.lstrip('(')
df3=df3.rstrip(')')
df3 = df3.strip(',').split(',')
#fund_list = (df.values).to_list()
#print(df3)
max_v = 0.0
rate_o = 0.0
for data in df3[::-1]:
    cur_v = float(data)
    if (max_v<cur_v):
        max_v=cur_v
    if(cur_v<max_v):
        i1 = (max_v-cur_v)
        i2 = (max_v)
        rate=i1/i2
        if(rate>rate_o):
            rate_o=rate
            print("i1 %f i2 %f cur_v %f max_v %f rate %f" %(i1,i2,cur_v,max_v,rate_o))            
print(rate_o)
C = input("current cumulative net worth:")
C = float(C)
X = (B-C)/(B*D)

print("down %f" % X)
X = (X*10)/2.0
print("index %f" % X)
X = (math.pow(2.0, X))
print("multiple %f" % X)
Y = A*F*X
print ("suggested single investment amount: %.2f " % Y)
