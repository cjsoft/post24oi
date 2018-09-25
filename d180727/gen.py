import random
import sys
n = 15
sys.stdout.write(str(n) + '\n')
for i in range(n):
    sys.stdout.write(str(random.randint(0,n * 3)) + ' ')
sys.stdout.write('\n0\n')
