og_array = list(set([2,8,9,48,8,22,-12,2]))
new_array = list(set([x+2 for x in og_array]))
array[:] = list(set(og_array))

print(og_array)
print(array)