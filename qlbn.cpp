#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std; 
class benhNhan {
    string ho,ten,gioiTinh,cccd,sdt,hoNT,tenNT,sdtNT;
    int day,month,year,tuoi,hapMin,hapMax,nhipTim;
    string phong;
public:
    benhNhan() {};
// Ham nhap thong tin benh nhan tu ban phim //
void nhap() {
    cout << "Nhap ho benh nhan: ";
    getline(cin, ho);
    cout << "Nhap ten benh nhan: ";
    getline(cin, ten);
    cout << "Nhap gioi tinh benh nhan (Nam/Nu): ";
    getline(cin, gioiTinh);
    do {
        cout << "Nhap ngay sinh cua benh nhan: ";
        cin >> day;
        if(day <= 0 || day > 31) cout << "Ngay sinh khong hop le. Nhap lai!" << endl;
    } while(day <= 0 || day > 31);
    do {
        cout << "Nhap thang sinh cua benh nhan: ";
        cin >> month;
        if(month <= 0 || month > 12) cout << "Thang sinh khong hop le. Nhap lai!" << endl;
    } while(month <= 0 || month > 12);
    
    do {
        cout << "Nhap nam sinh cua benh nhan: ";
        cin >> year;
        if(year <= 1900 || year >=9999) cout << "Nam sinh khong hop le. Nhap lai!"<<endl;
    } while(year <= 1900 || year >=9999);
    
    do {
        cout << "Nhap tuoi cua benh nhan: ";
        cin >> tuoi;
        if(tuoi <= 0 || tuoi>100) cout << "Tuoi khong hop le. Nhap lai!" << endl;
    } while(tuoi <= 0 || tuoi>100);
    cin.ignore();
    cout << "Nhap CCCD: ";
    getline(cin, cccd);
    cout << "Nhap so dien thoai benh nhan: ";
    getline(cin, sdt);
    cout << "Nhap ho nguoi than benh nhan: ";
    getline(cin, hoNT);
    cout << "Nhap ten nguoi than benh nhan: ";
    getline(cin, tenNT);
    cout << "Nhap so dien thoai nguoi than cua benh nhan: ";
    getline(cin, sdtNT);
    do {
        cout << "Nhap chi so huyet ap cao cua benh nhan: ";
        cin >> hapMax;
        if(hapMax <= 0) cout << "Chi so huyet ap cao khong duoc be hon hoac bang 0. Nhap lai!" << endl;
    } while(hapMax <= 0);
    
    do {
        cout << "Nhap chi so huyet ap thap cua benh nhan: ";
        cin >> hapMin;      
        if(hapMin <= 0) cout << "Chi so huyet ap thap khong duoc be hon hoac bang 0. Nhap lai!"<< endl;
    } while(hapMin <= 0);
    do {
        cout << "Nhap chi so nhip tim cua benh nhan: ";
        cin >> nhipTim;
        if(nhipTim<= 0) cout << "Chi so nhip tim khong duoc be hon hoac bang 0. Nhap lai!"<< endl;
    } while(nhipTim<= 0);
}
// Ham nhap thong tin benh nhan tu file //
void nhaptufile(std::ifstream& file) {
    char comma;
    getline(file, ho, ',');
    getline(file, ten, ',');
    getline(file, gioiTinh, ',');
    file >> day >> comma >> month >> comma >> year;
    file >> comma >> tuoi;
    file.ignore();
    getline(file, cccd, ',');
    getline(file, sdt, ',');
    getline(file, hoNT, ',');
    getline(file, tenNT, ',');
    getline(file, sdtNT, ',');
    file >> hapMax >> comma >> hapMin;
    file >> comma >> nhipTim;
    file.ignore();
} 
// Ham hien thi thong tin benh nhan //
void hienThiThongTin() const {
        cout << "=== Thong tin benh nhan ===" << endl;
        cout <<"1.  ho ten cua benh nhan la : " << ho << " " << ten << endl;
        cout <<"2.  gioi tinh cua benh nhan la : " << gioiTinh << endl;
        cout <<"3.  sinh ngay " << day << "-" << month << "-" << year << endl;
        cout <<"4.  so can cuoc cong dan cua benh nhan la : " << cccd << endl;
        cout <<"5.  so dien thoai cua benh nhan la :  " << sdt << endl;
        cout <<"6.  ho ten nguoi than cua benh nhan la : " << hoNT << " " << tenNT << endl;
        cout <<"7.  so dien thoai cua nguoi than benh nhan la : " << sdtNT << endl;
        cout <<"cac chi so so bo cua benh nhan la: " << endl;
        cout <<"8.  chi so huyet ap : " << hapMax << " / " << hapMin << endl;
        cout <<"9. nhip tim cua benh nhan : " << nhipTim<< endl; 
        cout <<"10. phong: " << phong << endl;
    }
// Ham hien thi thong tin ngan gon //
void hienThiNganGon() const {
    cout << left
       // Để STT ở ngoài
         << setw(15) << ho
         << setw(28) << ten
         << setw(13) << tuoi
         << setw(16) << gioiTinh
         << setw(18) << sdt
         << setw(12) << phong
         << endl;
}
void chinhSuaThongTin() {
    int lc; 
    cout << "Chon thuoc tinh can chinh sua: ";
    cin >> lc;
    cin.ignore();
    if (lc == 1) {
        cout << "Nhap ho moi: ";
        getline(cin, ho);
        cout << "Nhap ten moi: ";
        getline(cin, ten);
    } else if (lc == 2) {
        cout << "Nhap gioi tinh moi: ";
        getline(cin, gioiTinh);
    } else if (lc == 3) {
        cout << "Nhap ngay sinh moi: ";
        cin >> day;
        if (day <= 0 || day > 31) {
            cout << "Ngay sinh khong hop le. Nhap lai!" << endl;
            return;
        }
        cout << "Nhap thang sinh moi: ";
        cin >> month;
        if (month <= 0 || month > 12) {
            cout << "Thang sinh khong hop le. Nhap lai!" << endl;
            return;
        }
        cout << "Nhap nam sinh moi: ";
        cin >> year;
        if (year <= 1900 || year >= 9999) {
            cout << "Nam sinh khong hop le. Nhap lai!" << endl;
            return;
        }
    } else if (lc == 4) {
        cout << "Nhap so CCCD moi: ";
        getline(cin, cccd);
    } else if (lc == 5) {
        cout << "Nhap so dien thoai moi: ";
        getline(cin, sdt);
    } else if (lc == 6) {
        cout << "Nhap ho nguoi than moi: ";
        getline(cin, hoNT);
        cout << "Nhap ten nguoi than moi: ";
        getline(cin, tenNT);
    } else if (lc == 7) {
        cout << "Nhap so dien thoai nguoi than moi: ";
        getline(cin, sdtNT);
    } else if (lc == 8) {
        cout << "Nhap chi so huyet ap cao moi: ";
        cin >> hapMax;
        cout << "Nhap chi so huyet ap thap moi: ";
        cin >> hapMin;
    } else if (lc == 9) {
        cout << "Nhap chi so nhip tim moi: ";
        cin >> nhipTim;
    } else if (lc == 10) {
        cout << "Nhap phong moi: ";
        getline(cin, phong);
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
}
// Cac ham getter de tra ve //
string getHo() const {
    return ho;
}
string getTen() const {
    return ten;
}
string getGioiTinh() const {
    return gioiTinh;
}
string getCCCD() const {
    return cccd;
}
string getSDT() const {
    return sdt;
}
string getHoNT() const { 
    return hoNT;
}
string getTenNT() const { 
    return tenNT;
}
string getSdtNT() const {
    return sdtNT;
}
int getDay() const {
    return day;
}
int getMonth() const { 
    return month;
}
int getYear() const {
    return year;
}
int getTuoi() const {
    return tuoi;
}
int getHapmax() const {
    return hapMax;
}
int getHapmin() const {
    return hapMin;
}
int getNhiptim() const {
    return nhipTim;
}
string getPhong() const { return phong; }
void setNhiptim(int val) { nhipTim= val; }
void setHapmax(int val) { hapMax = val; }
void setHapmin(int val) { hapMin = val; }
void setPhong(const string& p) { phong = p; }
// Sap xep theo tuoi //
bool operator >= (const benhNhan& benhNhanKhac) const {
    if (this->getYear() != benhNhanKhac.getYear()) {
        return this->getYear() > benhNhanKhac.getYear();
    }
    if (this->getMonth() != benhNhanKhac.getMonth()) {
        return this->getMonth() > benhNhanKhac.getMonth();
    }
    if (this->getDay() != benhNhanKhac.getDay()) {
        return this->getDay() > benhNhanKhac.getDay();
    }
    return true;
}
// sap xep theo ten //
bool operator <= ( const benhNhan benhNhanKhac) const{
    if (this ->getTen() != benhNhanKhac.getTen()) {
        return this ->getTen() < benhNhanKhac.getTen();
    }
    if (this ->getHo() != benhNhanKhac.getHo()) {
        return this ->getHo() < benhNhanKhac.getHo();
    }
    return true;
}
};
class quanLy {
private:
    benhNhan* danhSach;
    int soLuong=0;
public: 
    // ham tao //
    quanLy() {
    danhSach = nullptr;
    soLuong = 0;
}   
    // ham huy //
    ~quanLy() {
    if (danhSach != nullptr)
        delete[] danhSach;
}
// tao mang soBenhNhanTrongPhong //
static const int SO_PHONG = 5;  // Số lượng phòng
static const int SO_BENH_NHAN_MOT_PHONG = 5; // Số lượng bệnh nhân tối đa trong một phòng
int soBenhNhanTrongPhong[SO_PHONG] = {0};
// ham doc thong tin benh nhan tu file //
void themBenhNhanTuFile(const string& tenFile) {
    ifstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }
    while (file.peek() != EOF) {
        benhNhan bn;
        bn.nhaptufile(file);
        if (!bn.getHo().empty()) // kiểm tra hợp lệ
            themBenhNhan(bn);
    }
    file.close();
    cout << "Da them cac benh nhan tu file.\n";
}
// Ham them benh nhan vao danh sach //
void themBenhNhan(benhNhan& benhNhanMoi) {
    // Tìm phòng còn chỗ
    int phongDuocChon = -1;
    for (int i = 0; i < SO_PHONG; i++) {
        if (soBenhNhanTrongPhong[i] < SO_BENH_NHAN_MOT_PHONG) {
            phongDuocChon = i + 1; // Phòng đánh số từ 1
            soBenhNhanTrongPhong[i]++;
            break;
        }
    }
    if (phongDuocChon == -1) {
        cout << "Tat ca cac phong da day, khong the them benh nhan moi!\n";
        return;
    }
    benhNhanMoi.setPhong("Phong " + to_string(phongDuocChon));

    // Thêm vào danh sách
    benhNhan* temp = new benhNhan[soLuong + 1];
    for (int i = 0; i < soLuong; i++) {
        temp[i] = danhSach[i];
    }
    temp[soLuong] = benhNhanMoi;
    if (danhSach != nullptr) delete[] danhSach;
    danhSach = temp;
    soLuong++;
    cout << "Da them benh nhan " << benhNhanMoi.getHo() << " " << benhNhanMoi.getTen()
         << " vao danh sach va vao " << benhNhanMoi.getPhong() << "." << endl;
}
void chinhSuaThongTinBenhNhan () {
    hienThiDanhSachNganGon();
    int stt;
    cout << "Nhap STT cua benh nhan can chinh sua: ";
    cin >> stt;
    cin.ignore();
    if (stt < 1 || stt > soLuong) {
        cout << "STT khong hop le!\n";
        return;
    }
    danhSach[stt - 1].hienThiThongTin();
    danhSach[stt - 1].chinhSuaThongTin();
}
void xoaBenhNhanBangCCCD(const string& cccd) {
    bool found = false;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getCCCD() == cccd) {
            found = true;
            int nhipTimMoi, hapMaxMoi, hapMinMoi;
            cout << "Nhap chi so nhip tim hien tai cua benh nhan: ";
            cin >> nhipTimMoi;
            cout << "Nhap chi so huyet ap cao hien tai cua benh nhan: ";
            cin >> hapMaxMoi;
            cout << "Nhap chi so huyet ap thap hien tai cua benh nhan: ";
            cin >> hapMinMoi;
            if (nhipTimMoi < 0 || hapMaxMoi < 0 || hapMinMoi < 0) {
                cout << "Chi so khong hop le!" << endl;
                return;
            }
            if (nhipTimMoi <= 100 && hapMaxMoi <= 120 && hapMinMoi >= 80 && hapMaxMoi > hapMinMoi) {
                // Dịch chuyển các phần tử phía sau lên trên
                for (int j = i; j < soLuong - 1; j++) {
                    danhSach[j] = danhSach[j + 1];
                }
                soLuong--;
                cout << "Da xoa benh nhan co CCCD: " << cccd << endl;
            } else {
                cout << "Chi so huyet ap va nhip tim chua on dinh, khong the xoa benh nhan" << endl;
            }
            return;}
    }
    if (found == false){
    cout << "Khong tim thay benh nhan co CCCD: " << cccd << endl;
    }
}
// Ham xoa benh nhan khoi danh sach bang ten //
void xoaBenhNhanBangHoTen(const string& hoTen) {
    bool found = false;
    for (int i = 0; i < soLuong; i++) {
        string fullName = danhSach[i].getHo() + " " + danhSach[i].getTen();
        if (fullName == hoTen) {
            found = true;
            int nhipTimMoi, hapMaxMoi, hapMinMoi;
            cout << "Nhap chi so nhip tim hien tai cua benh nhan: ";
            cin >> nhipTimMoi;
            cout << "Nhap chi so huyet ap cao hien tai cua benh nhan: ";
            cin >> hapMaxMoi;
            cout << "Nhap chi so huyet ap thap hien tai cua benh nhan: ";
            cin >> hapMinMoi;
            if (nhipTimMoi < 0 || hapMaxMoi < 0 || hapMinMoi < 0) {
                cout << "Chi so khong hop le!" << endl;
                return;
            }
            if (nhipTimMoi <= 100 && hapMaxMoi <= 120 && hapMinMoi >= 80 && hapMaxMoi > hapMinMoi) {
                for (int j = i; j < soLuong - 1; j++) {
                    danhSach[j] = danhSach[j + 1];
                }
                soLuong--;
                cout << "Da xoa benh nhan co ten: " << hoTen << endl;
            } else {
                cout << "Chi so huyet ap va nhip tim chua on dinh, khong the xoa benh nhan" << endl;
            }
            return;
        }
    }
    if (found == false){
    cout << "Khong tim thay benh nhan co ten: " << hoTen << endl;
    }
}
// Ham sap xep benh nhan giam dan theo ngay sinh //
void sapXepBenhNhanTheoNgaySinh() {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (danhSach[i] >= danhSach[j]) {
                benhNhan temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}
// Ham sap xep benh nhan tang dan theo ten //
void sapXepBenhNhanTheoTen() {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (!(danhSach[i] <= danhSach[j])) {
                benhNhan temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}
// Ham tim kiem benh nhan theo ten //
void timKiemBenhNhanTheoTen(const string& ten) const {
    bool found = false;
    cout << "Ket qua tim kiem benh nhan co ten: " << ten << endl;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getTen() == ten) {
            cout << "Benh nhan " << i + 1 << ":" << endl;
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay benh nhan co ten: " << ten << endl;
    }
}
// Ham tim kiem benh nhan theo CCCD //
void timKiemBenhNhanTheoCCCD(const string& cccd) const {
    bool found = false;
    cout << "Ket qua tim kiem benh nhan co CCCD: " << cccd << endl;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getCCCD() == cccd) {
            cout << "Benh nhan " << i + 1 << ":" << endl;
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay benh nhan co CCCD: " << cccd << endl;
    }
}
//hien thi danh sach ngan gon //
void hienThiDanhSachNganGon() const {
    if (soLuong == 0) {
        cout << "Danh sach benh nhan dang trong." << endl;
        return;
    }
    cout << left
         << setw(5)  << "STT"
         << setw(15) << "Ho"
         << setw(25) << "Ten"
         << setw(10) << "Tuoi"
         << setw(15) << "Gioi tinh"
         << setw(18) << "SDT"
         << setw(12) << "Phong"
         << endl;
    cout << left
         << setw(5)  << "---"
         << setw(15) << string(13, '-')
         << setw(25) << string(23, '-')
         << setw(10) << string(8, '-')
         << setw(15) << string(13, '-')
         << setw(18) << string(16, '-')
         << setw(12) << string(10, '-')
         << endl;
    for (int i = 0; i < soLuong; i++) {
        cout << setw(5) << (i + 1);
        danhSach[i].hienThiNganGon();
    }
}
// Ham hien thi danh sach chi tiet //
void hienThiDanhSachChiTiet() const {
    if (soLuong == 0) {
        cout << "Danh sach benh nhan dang trong." << endl;
        return;
    }
    for (int i = 0; i < soLuong; i++) {
        cout << "=== Benh nhan so " << (i + 1) << " ===" << endl;
        danhSach[i].hienThiThongTin();
        cout << "------------------------" << endl;
    }
}
//Ham thong ke do tuoi benh nhan //
void thongkeTuoi() const {
    if (soLuong == 0) {
        cout << "Danh sach benh nhan rong!" << endl;
        return;
    }

    int duoi18 = 0, tu18_40 = 0, tu41_60 = 0, tren60 = 0;
    for (int i = 0; i < soLuong; i++) {
        int tuoi = danhSach[i].getTuoi();
        if (tuoi < 18) duoi18++;
        else if (tuoi <= 40) tu18_40++;
        else if (tuoi <= 60) tu41_60++;
        else tren60++;
    }
    cout << "Thong ke do tuoi benh nhan:\n";
    cout << "Duoi 18 tuoi: " << duoi18 << endl;
    cout << "Tu 18 - 40 tuoi: " << tu18_40 << endl;
    cout << "Tu 41 - 60 tuoi: " << tu41_60 << endl;
    cout << "Tren 60 tuoi: " << tren60 << endl;
}
// ...existing code...
void xuatDanhSachRaFile(const string& tenFile) const {
    ofstream file(tenFile);
    if (!file.is_open()) {
        cout << "Khong the mo file de ghi!\n";
        return;
    }
    for (int i = 0; i < soLuong; i++) {
        file << danhSach[i].getHo() << ','
             << danhSach[i].getTen() << ','
             << danhSach[i].getGioiTinh() << ','
             << danhSach[i].getDay() << ','
             << danhSach[i].getMonth() << ','
             << danhSach[i].getYear() << ','
             << danhSach[i].getTuoi() << ','
             << danhSach[i].getCCCD() << ','
             << danhSach[i].getSDT() << ','
             << danhSach[i].getHoNT() << ','
             << danhSach[i].getTenNT() << ','
             << danhSach[i].getSdtNT() << ','
             << danhSach[i].getHapmax() << ','
             << danhSach[i].getHapmin() << ','
             << danhSach[i].getNhiptim() << ','
             << danhSach[i].getPhong()
             << '\n';
    }
    file.close();
    cout << "Da luu danh sach benh nhan ra file: " << tenFile << endl;
}
};
// ...existing code...
int main () {
    quanLy ql;
    int luachon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them benh nhan\n";
        cout << "2. Them benh nhan tu file\n";
        cout << "3. Xoa benh nhan bang CCCD\n";
        cout << "4. Xoa benh nhan bang ten\n";
        cout << "5. Sap xep theo tuoi\n";
        cout << "6. Sap xep theo ten\n";
        cout << "7. Tim kiem theo ten\n";
        cout << "8. Tim kiem theo CCCD\n";
        cout << "9. Hien thi danh sach\n";
        cout << "10. Thong ke do tuoi benh nhan\n";
        cout << "11. Chinh sua thong tin benh nhan\n"; 
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;
        cin.ignore();
    // Xu ly lua chon cua nguoi dung //
    if (luachon == 1) {
            benhNhan bn;
            bn.nhap();
            ql.themBenhNhan(bn);
    } else if (luachon == 2) {
        string tenFile;
        cout << "Nhap ten file: ";
        getline(cin, tenFile);
        ql.themBenhNhanTuFile(tenFile);
    } else if (luachon == 3) {
        string cccd;
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
        ql.xoaBenhNhanBangCCCD(cccd);
    } else if (luachon == 4) {
        string ho, ten;
        cin.ignore();
        cout << "Nhap ho: ";
        getline(cin, ho);
        cout << "Nhap ten: ";
        getline(cin, ten);
        string hoTen = ho + " " + ten;
    ql.xoaBenhNhanBangHoTen(hoTen);
    } else if (luachon == 5) {
        ql.sapXepBenhNhanTheoNgaySinh();
        ql.hienThiDanhSachNganGon();
        cout << "Da sap xep danh sach benh nhan theo tuoi giam dan.\n";
    } else if (luachon == 6) {
        ql.sapXepBenhNhanTheoTen();
        ql.hienThiDanhSachNganGon();
        cout << "Da sap xep danh sach benh nhan theo ten tang dan.\n";
    } else if (luachon == 7) {
        string ten;
        cout << "Nhap ten can tim: ";
        getline(cin, ten);
        ql.timKiemBenhNhanTheoTen(ten);    
    } else if (luachon == 8) {
        string cccd;
        cout << "Nhap CCCD can tim: ";
        getline(cin, cccd);
        ql.timKiemBenhNhanTheoCCCD(cccd);
    } else if (luachon == 9) {
        cout << "1. Hien thi danh sach ngan gon\n";
        cout << "2. Hien thi danh sach chi tiet\n";
        int sub;
        cout << "Nhap lua chon: ";
        cin >> sub;
        cin.ignore();
        if (sub == 1) ql.hienThiDanhSachNganGon();
        else if (sub == 2) ql.hienThiDanhSachChiTiet();
        else cout << "Lua chon khong hop le!\n";
    } else if (luachon == 10) {
        ql.thongkeTuoi();
    } else if (luachon == 11) {
        ql.chinhSuaThongTinBenhNhan(); // Thêm dòng này để gọi hàm chỉnh sửa
    } else if (luachon == 0) {
        string tenFile;
        cout << "Nhap ten file de luu danh sach: ";
        cin.ignore();
        getline(cin, tenFile);
        ql.xuatDanhSachRaFile(tenFile);
        cout << "Cam on ban da su dung chuong trinh!\n";
    } else {
        cout << "Lua chon khong hop le!\n";
    }
    } while (luachon != 0);
    return 0;
}