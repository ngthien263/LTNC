ds_msv = [21021372, 21021383]
ds_ten = ["Vương Ngọc Thiện", "NgThien"]
ds_diem = [9.5,3.1]

def danhsach():
    print("MSV", end='')
    for i in range(7):
        print(" ", end='')
    print("Tên", end='')
    for i in range(max(len(ten) for ten in ds_ten) - 1):
        print(" ", end='')
    print("Điểm")
    for i in range(len(ds_msv)):
        print(ds_msv[i], end='')
        for j in range(2):
            print(" ", end='')
        print(ds_ten[i], end='')
        for j in range(max(len(ten) for ten in ds_ten) - len(ds_ten[i]) + 2):
            print(" ", end='')
        print(ds_diem[i])

def add_sv(msv, ten, diem):
    ds_msv.append(msv)
    ds_ten.append(ten)
    ds_diem.append(diem)

def sua_sv(input, new_input):
    if isinstance(input, int) and isinstance(new_input, int):
        if input in ds_msv:
            i = ds_msv.index(input)
            ds_msv[i] = new_input
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, str) and isinstance(new_input, str):
        if input in ds_ten:
            i = ds_ten.index(input)
            ds_ten[i] = new_input
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, float) and isinstance(new_input, float):
        if input in ds_diem:
            i = ds_diem.index(input)
            ds_diem[i] = new_input
        else:
            print("Không tìm thấy sinh viên này")
    else:
        print("Đầu vào không hợp lệ")


def xoa_sv(input = None):
    if isinstance(input, int):
        if input in ds_msv:
            i = ds_msv.index(input)
            ds_msv.remove(ds_msv[i])
            ds_ten.remove(ds_ten[i])
            ds_diem.remove(ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, float):
        if input in ds_diem:
            i = ds_diem.index(input)
            ds_msv.remove(ds_msv[i])
            ds_ten.remove(ds_ten[i])
            ds_diem.remove(ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, str):
        if input in ds_ten:
            i = ds_ten.index(input)
            ds_msv.remove(ds_msv[i])
            ds_ten.remove(ds_ten[i])
            ds_diem.remove(ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    else:
        print("Không tìm thấy sinh viên này")

def timkiem(input = None):
    if isinstance(input, int):
        if input in ds_msv:
            i = ds_msv.index(input)
            print("MSV:", ds_msv[i], "Ten:", ds_ten[i], "Diem:", ds_diem[i])

        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, float):
        if input in ds_diem:
            i = ds_diem.index(input)
            print("MSV:", ds_msv[i], "Ten:", ds_ten[i], "Diem:", ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(input, str):
        if input in ds_ten:
            i = ds_ten.index(input)
            print("MSV:", ds_msv[i], "Ten:", ds_ten[i], "Diem:", ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    else:
        print("Không tìm thấy sinh viên này")


while():