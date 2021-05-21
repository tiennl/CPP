def solve(price):
    i = 1
    res = 0
    coints = []
    while (price > 0):
        res += 1
        coints.append(i)
        price -= i
        i *= 2
    print(res)
    for item in coints:
        print(item, end = ' ')
    print()
def main():
    nTest = int(input())
    for iTest in range(nTest):
        price = int(input())
        solve(price)

if __name__ == "__main__": 
    main()  