# import requests
# import json
#
# response = requests.get("https://form-check-hixwog3m7q-uc.a.run.app/2021-09-19")
# print(json.dumps(response.json(), indent=3))
# print(response)

from scipy.signal import argrelextrema
import numpy as np

values_array1 = [0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 6, 5, 4]
values_array = np.array(values_array1)

max_ind = argrelextrema(values_array, np.greater)
min_ind = argrelextrema(values_array, np.less)
print(max_ind)
print(min_ind)

good_pushups_top = []
good_pushups_bot = []
bad_pushups = []
total_pushups = len(min_ind[0])

for counter, index in enumerate(max_ind[0]):
    degree = values_array[index]
    #percentage = (degree/90)*100
    if degree >= 8:
        good_pushups_top.append([counter, degree])
    else:
        bad_pushups.append([counter, degree])

for counter, index in enumerate(min_ind[0]):
    degree = values_array[index]
    #percentage = (degree/90)*100
    if degree <= 1:
        good_pushups_bot.append([counter, degree])
    else:
        bad_pushups.append([counter, degree])

good_counter = 0
final_good_pushups = []

for i in good_pushups_top:
    for j in good_pushups_bot:
        if i[0] == j[0]:
            good_counter += good_counter
            average_percentage = (i[1]+j[1])/2
            final_good_pushups.append([i[0], average_percentage])

bad_counter = total_pushups - good_counter

print(total_pushups)
print(good_counter)
print(final_good_pushups)
print(bad_counter)
print(bad_pushups)

print(good_pushups_top)
print(good_pushups_bot)
