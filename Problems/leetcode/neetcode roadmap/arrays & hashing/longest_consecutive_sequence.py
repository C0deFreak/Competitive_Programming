nums = [100, 4, 200, 1, 3, 2]

# Da ne pregledava duplikate
nums = set(nums)
ans = 0
for n in nums:
    temp = 1
    # Ne trebaš provjeravat jeli u nekoj check hashmapi jer će pregledavat samo "početni" broj, gubiš space bzvz
    if n-1 in nums:
        continue
    
    while n+temp in nums:
        temp += 1
    # Provjerit s if je brže, al ovo je ljepše
    ans = max(ans, temp)
print(ans)