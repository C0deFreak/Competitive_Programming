"""
ID: grgurin1
LANG: PYTHON3
TASK: friday
"""

fin = open('friday.in', 'r')

n = int(fin.readline()) + 1900

year = 1900
month = 1
last_day = 0
ans = [0]*7


while year < n:
    for _ in range(12):
        ans[last_day] += 1
        diff = 31

        # Korištenje operacija
        if month == 2:
            diff = 28
            if year % 4 == 0 and year % 100 != 0:
                diff += 1
            elif year % 400 == 0:
                diff += 1
        elif month in (4, 6, 9, 11):
            diff = 30
        
        last_day = (diff+last_day) % 7
        
        month += 1
    month = 1
    year += 1



fout = open('friday.out', 'w')
fout.write(str(ans).strip(']').strip('[').replace(',', '')+'\n')
fout.close()


