# -*- coding: UTF-8 -*-

import re

#  items = raw_input()
#  out = raw_input()
items = u"singer_�ܽ�|�ܽ���|���»�|������;song_����|������ӭ��|������;actor_�ܽ���|��ٳ"
ss = u"�벥���ܽ��׵������������"

type1 = items.split(u'|')

aa = []
for i in type1:
    aa.append(i.split('_'))
dict0 = dict(zip())


