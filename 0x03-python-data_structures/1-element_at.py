#!/usr/bin/python3
def element_at(my_list, idx):
    listCount = len(my_list)
    if idx < 0 or idx > listCount:
        return None
    for i in range(0, listCount):
        if i == idx:
            return my_list[idx]
