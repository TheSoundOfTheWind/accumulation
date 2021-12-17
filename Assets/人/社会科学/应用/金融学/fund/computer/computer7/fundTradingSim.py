#!/usr/bin/python3
import json
import requests
import math
import datetime
import re
import dateutil.parser as parser
import pandas as pd
import requests
import numpy as np
import time
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

def getFundValue(fundId):
    code = fundId
    url = 'http://fundgz.1234567.com.cn/js/%s.js' % code
    result = requests.get(url)
    # 发送请求
    data = json.loads(re.match(".*?({.*}).*", result.text, re.S).group(1))
    return data

    

def printFund(list):
    df = get_fund_k_history(list[0])
    df2 = tuple(df['累计净值'])
    df3 = str(df2)
    df3=df3.lstrip('(')
    df3=df3.rstrip(')')
    df3 = df3.strip(',').split(',')
    max_v = 0.0
    max_o = 0.0
    rate_o = 0.0
    cur_v = 0.0
    list_a =[]
    for data in df3[::-1]:
        cur_v = float(data)
        if (max_v<cur_v):
            max_v=cur_v
        if(cur_v<max_v):
            i1 = (max_v-cur_v)
            i2 = (max_v)
            rate=i1/i2
            if(rate>rate_o or max_v > max_o):
                rate_o=rate
                max_o = max_v
               # print("max_o %.4f rate_o %.4f" % (max_o, rate_o))
                a_tuple=(max_o,rate_o)
                list_a.append(a_tuple)
    max_t = list_a[0][0]
    rate_t = 0.0
    list_b = []
    for tup in list_a:
        if(max_t != tup[0]):
            tup2=(max_t, rate_t)
            list_b.append(tup2)
            max_t = tup[0]
            rate_t=0.0
        if(tup[1] > rate_t):
            rate_t = tup[1]
    list_b.sort(key=lambda x:x[1],reverse=True)
#    print(list_b[0:3])
    rate_o = list_b[0][1]*0.7+list_b[1][1]*0.2+list_b[2][1]*0.1
    A = float(list[7])
    B = max_v
    data = getFundValue(list[0])
    C = float(data['gszzl'])
    C_t = int(time.strftime('%H',time.localtime(time.time())))
    C_tt = C
    C = cur_v + cur_v*C*0.01
    if(C_t >= 15):
        C = cur_v
    D = rate_o
    F = float(list[3])
    X = (B-C)/(B*D)
    sell = X
    X = (X*10)/2.0
    X = (math.pow(2.0, X))
    Y = A*F*X
    sell_str = ""
    if(sell > 0.1 and sell < 0.3):
        sell_str="1/3"
    if(sell > 0.3 and sell < 0.5):
        sell_str="2/3"
    if(sell>0.5):
        sell_str="3/3"
    if (C_tt < 0):
        print ("%s: %.2f %.2f $$ %.2f %s" %(list[1], D*10.0, Y, sell, sell_str))
    else:
        print ("%s: %.2f %.2f" %(list[1], D*10.0, Y))


print("//----------------------------------------------------------------")
f = open("../../buy_fund/data2.txt", "r")
for line in f:
    a = line.split( )
    if line[0] == '#':
        if len(a) != 1:
            continue
        print(line)
        continue
    if (len(a) != 8):
        continue
    printFund(a)

