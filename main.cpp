#include <iostream>
#include <string>
using namespace std;

class Phim {
public:
    string ma;
    string ten;
    string theLoai;
    float diem;
};

int main() {
    Phim ds[100];
    int n = 0;
    int chon;

    do {
        cout << "\n===== QUAN LY PHIM CHIEU RAP =====\n";
        cout << "1. Them phim moi\n";
        cout << "2. Hien thi tat ca phim\n";
        cout << "3. Tim phim theo ma\n";
        cout << "4. Hien thi phim co diem cao nhat\n";
        cout << "5. Hien thi phim co diem thap nhat\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {

        case 1: {
            string ma;
            bool trung = false;

            cout << "Nhap ma phim: ";
            cin >> ma;
            for (int i = 0; i < n; i++) {
                if (ds[i].ma == ma)
                    trung = true;
            }

            if (trung) {
                cout << "Ma phim da ton tai!\n";
                break;
            }
            ds[n].ma = ma;
            cin.ignore();
            cout << "Nhap ten phim: ";
            getline(cin, ds[n].ten);
            cout << "Nhap the loai phim: ";
            getline(cin, ds[n].theLoai);
            do {
                cout << "Nhap diem danh gia (1-10): ";
                cin >> ds[n].diem;
            } while (ds[n].diem < 1 || ds[n].diem > 10);

            n++;
            cout << "Them phim thanh cong!\n";
            break;
        }
        case 2:
            if (n == 0)
                cout << "Danh sach phim rong!\n";
            else {
                cout << "Danh sach phim:\n";
                for (int i = 0; i < n; i++)
                    cout << ds[i].ma << " - "
                         << ds[i].ten << " - "
                         << ds[i].theLoai << " - "
                         << ds[i].diem << endl;
            }
            break;
        case 3: {
            string ma;
            cout << "Nhap ma phim can tim: ";
            cin >> ma;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (ds[i].ma == ma) {
                    cout << ds[i].ma << " - "
                         << ds[i].ten << " - "
                         << ds[i].theLoai << " - "
                         << ds[i].diem << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Khong tim thay phim!\n";
            break;
        }
        case 4: {
            if (n == 0) {
                cout << "Chua co phim nao!\n";
                break;
            }

            float max = ds[0].diem;
            for (int i = 1; i < n; i++)
                if (ds[i].diem > max)
                    max = ds[i].diem;
            cout << "Phim co diem danh gia cao nhat:\n";
            for (int i = 0; i < n; i++)
                if (ds[i].diem == max)
                    cout << ds[i].ma << " - "
                         << ds[i].ten << " - "
                         << ds[i].theLoai << " - "
                         << ds[i].diem << endl;
            break;
        }
        case 5: {
            if (n == 0) {
                cout << "Chua co phim nao!\n";
                break;
            }
            float min = ds[0].diem;
            for (int i = 1; i < n; i++)
                if (ds[i].diem < min)
                    min = ds[i].diem;
            cout << "Phim co diem danh gia thap nhat:\n";
            for (int i = 0; i < n; i++)
                if (ds[i].diem == min)
                    cout << ds[i].ma << " - "
                         << ds[i].ten << " - "
                         << ds[i].theLoai << " - "
                         << ds[i].diem << endl;
            break;
        }
        case 0:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
    return 0;
}
