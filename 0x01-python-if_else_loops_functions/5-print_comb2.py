#!/usr/bin/python3
result = ""
for i in range(0, 100):
    result += "{:02d}".format(i)
    if result != "" and i != (100 - 1):
        result += ", "
print(result)
