"""
ID: grgurin1
LANG: PYTHON3
TASK: gift1
"""


with open('gift1.in', 'r') as fin:
    friends = {}
    np = int(fin.readline().strip())
    for _ in range(np):
        friends[fin.readline().strip()] = 0
    
    for _ in range(np):
        giver = fin.readline().strip()
        amount, recive = map(int, fin.readline().strip().split())

        # Čisti data types, nema puno algoa
        if recive != 0:
            if amount != 0:
                friends[giver] += -amount + (amount%recive)
                amount = amount//recive

            for _ in range(recive):
                friends[fin.readline().strip()] += amount

with open('gift1.out', 'w') as fout:
    for fri, amo in friends.items():
        fout.write(f'{fri} {amo}' + '\n')