# -*- coding: UTF-8 -*-

import re

in1 = raw_input().decode('utf-8')
in2 = raw_input().decode('utf-8')
#  items = u'singer_�ܽ�|�ܽ���|���»�|������;song_����|������ӭ��|������;actor_�ܽ���|��ٳ'
#  items = u'�ܽ���'
#  ss = u'�벥���ܽ��׵������������'

entyTypes = re.split(u';', in1)
itemInEachType = []
for type1 in entyTypes:
    itemInEachType.append(re.split(u'_', type1))

res = []
keys = []
values = []

for item in itemInEachType:
    aa = re.split(u'\|', item[1])
    keys.append(item[0])
    values.append(aa)
res = dict(zip(keys, values))

aa = []
bb = []
ll = dict()
for type2 in res:
    for name in res[type2]:
        if re.search(name , in2):
            ll[type2] = []
            ll[type2].append(re.search(name , in2).group())

out = in2            
for it in ll:
    out = re.sub(ll[it][0], u' ' + ll[it][0] + u'/' + it, out)


out = re.sub(u' +', ' ', out)

print out
