def garden_operations(operation_number: int):
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        100 / 0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        "aaa" + 1
    else:
        return