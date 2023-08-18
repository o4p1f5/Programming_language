# 20204306 오민진

import numpy as np


def average_list(data):
    sum1 = 0
    for x in range(len(data)):
        sum1 += data[x]
    average = sum1 / len(data)

    return average


def get_key_with_max_value(data):
    max1 = 0
    max2 = 0
    key = list(data.keys())
    val = list(data.values())
    for i in range(len(key)):
        if max1 < val[i]:
            max1 = val[i]
            max2 = key[i]
    return max2


def conditional_average(data, threshold):
    new_data = data[data > threshold]
    sum1 = 0
    for i in range(len(new_data)):
        sum1 += new_data[i]
    average = sum1 / len(new_data)

    return average


def mean_arrays(foo, bar):
    if foo.shape != bar.shape:
        raise ValueError('different shapes')
    else:
        sum1 = foo + bar
        average = sum1 / 2

    return average


