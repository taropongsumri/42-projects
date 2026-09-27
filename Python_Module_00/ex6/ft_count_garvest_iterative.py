def ft_count_harvest_iterative():
    harvest_day = int(input('Days until harvest: '))
    i = 1
    while i <= harvest_day:
        print(f'Day {i}')
        i += 1
    print('Harvest time!')