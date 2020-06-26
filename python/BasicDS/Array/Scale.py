scale = [int(x) for x in input().strip().split()]

cnt = 0

for i in range(len(scale) - 1):
    if scale[i] < scale[i + 1]:
        cnt += 1
    else:
        cnt -= 1

if cnt == 7:
    print("ascending")
elif cnt == -7:
    print("descending")
else:
    print("mixed")
