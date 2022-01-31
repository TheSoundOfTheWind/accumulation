#!/usr/bin/python3
import sys
month = input("月份:")
print("==老婆资产汇总==")
tiantian1 = float(input("天天基金:"))
zhifubao1 = float(input("支付宝:"))
yinhangka1 = float(input("银行卡:"))
weixin1 = float(input("微信:"))
shouyijine1 = float(input("收益金额:"))
zongzichan1 = tiantian1 + zhifubao1 + yinhangka1 + weixin1
shouyilv1 = float(shouyijine1) / float(zongzichan1) * 100.0

print("==金海林资产汇总==")
tiantian2 = float(input("天天基金:"))
zhifubao2 = float(input("支付宝:"))
yinhangka2 = float(input("银行卡:"))
weixin2 = float(input("微信:"))
shouyijine2 = float(input("收益金额:"))
zongzichan2 = tiantian2 + zhifubao2 + yinhangka2 + weixin2
shouyilv2 = float(shouyijine2) / float(zongzichan2) * 100.0
tiantian = tiantian1+tiantian2
zhifubao = zhifubao1+zhifubao2
yinhangka = yinhangka1+yinhangka2
weixin = weixin1+weixin2
shouyijine = shouyijine1+shouyijine2
zongzichan = zongzichan1+zongzichan2
shouyilv=float(shouyijine)/(float(zongzichan)-float(shouyijine))*100.0
fileName1 = str(month) + "月资产统计"
fileName2 = str(month) + "月资产统计.txt"
print("                      =========%s=========\n" % (fileName1))
print("%-10s%-6s%-7s%-7s%-8s%-6s%-7s%-7s"
      % (" ","天天基金","支付宝","银行卡","微信","收益金额","收益率","总资产"))
print("%-8s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("老婆",tiantian1,zhifubao1,yinhangka1,weixin1,shouyijine1,shouyilv1,zongzichan1))
print("%-7s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("金海林",tiantian2,zhifubao2,yinhangka2,weixin2,shouyijine2,shouyilv2,zongzichan2))
print("%-8s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("汇总",tiantian,zhifubao,yinhangka,weixin,shouyijine,shouyilv,zongzichan))
sys.stdout = open(fileName2, "wt")
print("                      =========%s=========\n" % (fileName1))
print("%-10s%-6s%-7s%-7s%-8s%-6s%-7s%-7s"
      % (" ","天天基金","支付宝","银行卡","微信","收益金额","收益率","总资产"))
print("%-8s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("老婆",tiantian1,zhifubao1,yinhangka1,weixin1,shouyijine1,shouyilv1,zongzichan1))
print("%-7s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("金海林",tiantian2,zhifubao2,yinhangka2,weixin2,shouyijine2,shouyilv2,zongzichan2))
print("%-8s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.2f%-10.1f"
      % ("汇总",tiantian,zhifubao,yinhangka,weixin,shouyijine,shouyilv,zongzichan))

