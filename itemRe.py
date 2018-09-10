# -*- coding: UTF-8 -*-

import re

#  items = raw_input()
#  out = raw_input()
items = u"singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪"
ss = u"请播放周杰伦的七里香给我听"

type1 = items.split(u'|')

aa = []
for i in type1:
    aa.append(i.split('_'))
dict0 = dict(zip())


