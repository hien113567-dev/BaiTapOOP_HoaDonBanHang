#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class KhachHang;
class HangHoa;
class HoaDon;
class KhachHang{
	private:
		string hoTen, diaChi, dienThoai;
	public:
		KhachHang();
		KhachHang(string ten, string dc, string dt);
		void NhapDuLieu();
		void InDuLieu();
	friend class HoaDon;
};
KhachHang::KhachHang(){
	hoTen = "";
	diaChi = "";
	dienThoai = "";
}
KhachHang::KhachHang(string ten, string dc, string dt){
	hoTen = ten;
	diaChi = dc;
	dienThoai = dt;
}
void KhachHang::NhapDuLieu(){
	cout << "\nNhap ten khach hang: ";
	getline(cin,this->hoTen);
	cout << "Nhap dia chi: ";
	getline(cin,this->diaChi);
	cout << "Nhap so dien thoai: ";
	getline(cin,this->dienThoai);
}
void KhachHang::InDuLieu(){
	cout << "\nHo ten khach hang: " << this->hoTen << "..... DT: " << this->dienThoai;
	cout << "\nDia Chi: " << this->diaChi;
}

class HangHoa{
	private:
		string tenHangHoa, donViTinh;
		int soLuong;
		double donGia;
	public:
		HangHoa(){
			tenHangHoa="";
			donViTinh = "";
			soLuong = 0;
			donGia = 0.0;
		};
		HangHoa(string ten, string donvi, int SL, double gia);
		void NhapSoLieu();
		double ThanhTien();
	friend class HoaDon;
};
HangHoa::HangHoa(string ten, string donvi, int SL, double gia){
	tenHangHoa = ten;
	donViTinh = donvi;
	soLuong = SL;
	donGia = gia;
}
double HangHoa::ThanhTien(){
	return this->soLuong*this->donGia;
}
void HangHoa::NhapSoLieu(){
	cout << "\nNhap ten hang hoa: ";
	getline(cin, this->tenHangHoa);
	//cin >> this->tenHangHoa;
	cout << "Nhap don vi tinh: ";
	getline(cin, this->donViTinh);
	//cin >> this->donViTinh;
	cout << "Nhap so luong: ";
	cin >> this->soLuong;
	cout << "Nhap don gia: ";
	cin >> this->donGia;
	cin.ignore();
	//cout << "\nThanh tien: " << this->ThanhTien();
}


class HoaDon{
	KhachHang x;
	int smh;
	HangHoa *a;
	
	public:
		void Nhap();
		void In();
};
void HoaDon::Nhap(){
	cout << "\nNhap thong tin khach hang: ";
	x.NhapDuLieu();
	cout << endl;
	cout << "\nNhap so mat hang: ";
	cin >> smh;
	cin.ignore(1);
	a = new HangHoa[smh+1];
	for(int i = 1; i<=smh; ++i){
		cout << "\nNhap thong tin hang hoa thu " << i << ": ";
		a[i].NhapSoLieu();
	}
	
}
void HoaDon::In(){
	cout << "\nHOA DON BAN HANG\n";
	x.InDuLieu();
	cout << "\n";
	cout << left
	<< setw(10) << "So TT" 
	<< setw(50) << "TEN HANG HOA VA QUY CACH SAN PHAM" 
	<< setw(20) << "Don Vi Tinh" 
	<< setw(20) << "So Luong" 
	<< setw(20) << "Don Gia" 
	<< setw(20) << "Thanh Tien";
	cout << "\n";
	
	double tongTien = 0;
	for(int i = 1; i<=smh; ++i){
			cout << setw(10) << i 
			<< setw(50) << a[i].tenHangHoa 
			<< setw(20) << a[i].donViTinh 
			<< setw(20) << a[i].soLuong
			<< setw(20) << a[i].donGia
			<< setw(20) << a[i].ThanhTien();
			cout << "\n";
		tongTien +=a[i].ThanhTien();
	}
	cout << left 
	<< setw(10) << "" 
	<< setw(25) << fixed << setprecision(2)<< "CONG: " 
	<< setw(25) << tongTien 
	<< setw(20) << "" 
	<< setw(20) << "" 
	<< setw(20) << "" 
	<< setw(20) << "";
}

int main(){
	HoaDon a;
	a.Nhap();
	a.In();
	
}

