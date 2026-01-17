for _ in range(int(input())):
    n = int(input())
    barray = input()

    if barray[0] == '1' or barray[(n*2)-2] == '1':
        print('Alice')
    else:
        print('Bob')