import re
s=raw_input();
a = raw_input();
b = raw_input();

a = a.replace('*', '[a-z]*')
a = '^' + a + '$'
if re.match(a, b):
    print "YES"
else:
    print "NO"