import os
chu_cai_tv = ['a', 'á', 'à', 'ạ', 'ă', 'ắ', 'ằ', 'ặ', 'â', 'ấ', 'ầ', 'ậ', 'đ', 'e', 'é', 'è', 'ẹ', 'ê', 'ế','ề', 'ệ' , 'o', 'ó', 'ò', 'ọ', 'ô','ố','ồ','ộ', 'ơ', 'ớ', 'ờ', 'ợ','u','ú','ù','ụ', 'ư', 'ứ', 'ừ', 'ự', ' A ' ,' Á ' ,' À ' ,' Ạ ' ,' Ă ' ,' Ắ ' ,' Ằ ' ,' Ặ ' ,' Â ' ,' Ấ ' ,' Ầ ' ,' Ậ ' ,' Đ ' ,' E ' ,' É ' ,' È ' ,' Ẹ ' ,' Ê ' ,' Ế ' ,' Ề ' ,' Ệ ' ,' O ' ,' Ó ' ,' Ò ' ,' Ọ ' ,' Ô ' ,' Ố ' ,' Ồ ' ,' Ộ ' ,' Ơ ' ,' Ớ ' ,' Ờ ' ,' Ợ ' ,' U ' ,' Ú ' ,' Ù ' ,' Ụ ' ,' Ư ' ,' Ứ ' ,' Ừ ' ,' Ự ']
ds_msv = [21021372, 21021373, 21021374, 21021375, 21021376, 21021377, 21021378, 21021379, 21031380, 21021381]
ds_ten = ["Vương Ngọc Thiện", "Vương Ngọc Thiện", " ", " ", "Vương Ngọc Thiện", " ", " ", " ", " ", " "]
ds_diem = [9.5, 3.25, 4.25, 8.25, 10, 9.5, 8.5, 5.5, 6.5, 7.25]
def is_float(n):
    parts = n.split('.')
    if len(parts) == 2 and parts[0].isdigit() and parts[1].isdigit():
        return True
    return False

def check_str(s):
    count = 0
    for i in range(len(s)):
        if 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z' or s[i] in chu_cai_tv or s[i] == ' ':
            count += 1
    if count == len(s):
        return 1
    return 0

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

def add_sv():
    msv = input("Nhập mã sinh viên: ")
    while not msv.isdigit() or int(msv) in ds_msv:
        if not msv.isdigit():
            print("MSV chỉ được nhập số")
        else:
            print("MSV đã tồn tại trong danh sách")
        msv = input("Nhập mã sinh viên: ")
    while not msv.isdigit():
        print("MSV chỉ được nhập số")
        msv = input("Nhập mã sinh viên: ")
    ds_msv.append(int(msv))
    ten = input("Nhập tên của sinh viên: ")
    while check_str(ten) == 0:
        print("Tên chỉ được nhập chữ")
        ten = input("Nhập tên của sinh viên: ")
    ds_ten.append(ten)
    diem = input("Nhập điểm của sinh viên: ")
    while not is_float(diem) and not diem.isdigit():
        print("Điểm chỉ được nhập số thực hoặc số nguyên")
        diem = input("Nhập điểm của sinh viên: ")
    if diem.isdigit():
        diem = float(diem)
    ds_diem.append(diem)
    print("Đã thêm sinh viên", msv, " - ", ten, "- điểm số", diem)

def sua_sv():
    inp = input("Nhập mã sinh viên hoặc tên: ")
    while not inp.isdigit() and not check_str(inp):
        print("Chỉ được nhập số hoặc chữ")
        inp = input("Nhập mã sinh viên hoặc tên: ")

    if inp.isdigit():
        if int(inp) in ds_msv:
            new_input = input("Nhập mã sinh viên thay đổi:")
            while not new_input.isdigit():
                print("MSV chỉ được nhập số")
                new_input = input("Nhập mã sinh viên thay đổi:")
            i = ds_msv.index(int(inp))
            ds_msv[i] = int(new_input)
        else:
            print("Không tìm thấy sinh viên ")
    elif isinstance(inp, str):
        if inp in ds_ten:
            new_input = input("Nhập tên thay đổi:")
            while check_str(new_input) == 0:
                print("Tên chỉ được nhập chữ")
                new_input = input("Nhập tên thay đổi:")
            i = ds_ten.index(inp)
            ds_ten[i] = new_input
        else:
            print("Không tìm thấy sinh viên")

def xoa_sv():
    inp = input("Nhập mã sinh viên hoặc tên: ")
    while not inp.isdigit() and not isinstance(inp, str):
        print("Chỉ được nhập số hoặc chữ")
        inp = input("Nhập mã sinh viên hoặc tên: ")

    if inp.isdigit():
        if int(inp) in ds_msv:
            i = ds_msv.index(int(inp))
            ds_msv.remove(ds_msv[i])
            ds_ten.remove(ds_ten[i])
            ds_diem.remove(ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")
    elif isinstance(inp, str):
        if inp in ds_ten:
            i = ds_ten.index(inp)
            ds_msv.remove(ds_msv[i])
            ds_ten.remove(ds_ten[i])
            ds_diem.remove(ds_diem[i])
        else:
            print("Không tìm thấy sinh viên này")

def timkiem():
    inp = input("Nhập mã sinh viên, tên, hoặc điểm: ")
    while not inp.isdigit() and not isinstance(inp, str) and not is_float(inp):
        print("Input chỉ được nhập số, chữ, hoặc số thực")
        inp = input("Nhập mã sinh viên, tên, hoặc điểm: ")

    found = False
    if inp.isdigit():
        if int(inp) in ds_msv:
            i = ds_msv.index(int(inp))
            print("MSV:", ds_msv[i], "Tên:", ds_ten[i], "Điểm:", ds_diem[i])
            found = True
    elif is_float(inp):
        for i in range(len(ds_diem)):
            if float(inp) == ds_diem[i]:
                print("MSV:", ds_msv[i], "Tên:", ds_ten[i], "Điểm:", ds_diem[i])
                found = True
    elif isinstance(inp, str):
        for i in range(len(ds_ten)):
            if inp == ds_ten[i]:
                print("MSV:", ds_msv[i], "Tên:", ds_ten[i], "Điểm:", ds_diem[i])
                found = True

    if not found:
        print("Không tìm thấy sinh viên.")



while True:
    #menu
    print("1. Danh sách sinh viên")
    print("2. Thêm sinh viên")
    print("3. Sửa thông tin của sinh viên")
    print("4. Xóa thông tin của sinh viên")
    print("5. Tìm kiếm sinh viên")
    print("Ấn x để tắt chương trình")
    choice = input("Nhập lựa chọn: ")
    if choice == '1':
        danhsach()
    elif choice == '2':
        add_sv()
    elif choice == '3':
        sua_sv()
    elif choice == '4':
        xoa_sv()
    elif choice == '5':
        timkiem()
    elif choice == 'x' or choice == 'X':   #Thoát khỏi chương trình từ menu
        print("Kết thúc chương trình")
        break
    else:
        print("Lựa chọn không hợp lệ. Hãy chọn lại")

    #Tiếp tục chương trình
    cont = input("Bạn có muốn tiếp tục không? (Y/N): ")
    while cont.upper() != 'Y' and cont.upper() != 'N':
        print("Ký tự không hợp lệ. Xin hãy nhập lại")
        cont = input("Bạn có muốn tiếp tục không? (Y/N): ")
    if cont == 'Y':
        os.system('cls')
    elif cont == 'N':
        print("Kết thúc chương trình")
        break