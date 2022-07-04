#!/usr/bin/python3
def replace_in_list(my_list, idx, element):
    listCount = len(my_list)
    if idx < 0 or idx >= listCount:
        return my_list
    my_list[idx] = element
    return my_list
