# -*- coding: UTF-8 -*-

import re

in1 = raw_input().decode('utf-8')
in2 = raw_input().decode('utf-8')
#  items = u'singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪'
#  items = u'周杰伦'
#  ss = u'请播放周杰伦的七里香给我听'

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
