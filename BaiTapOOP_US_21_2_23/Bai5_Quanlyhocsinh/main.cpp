//quan ly hoc sinh, thuc hien cac thao tac
//them hoc sinh (MHS, TenHs, diem cac mon hoc (Toan, van ly hoa ngoai ngu), dia chu, ghichu)
//cap nhap thong tin hoc sinh
//xoa hoc sinh
//xem danh sach hoc sinh mhs tang dan, giam dan
//diem tang dan, giam dan
//tinh diem trung binh, xep loai hinh sinh
//luu danh sach hoc sinh
//import/exprt danh sach hoc sinh ra file text


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Monhoc{
    double Toan, Van, Ly, Hoa, Ngoaingu;
};

struct Hocsinh{
    string MHS, TenHS, DiaChi, GhiChu;
    Monhoc monhoc;
};

//Them vao sau danh sach hoc sinh
//input list danh sacsh hoc sinh ban dau
//output danh sach hoc sinh moi sau khi nhap them
void themhs(vector<Hocsinh> &list, string fileIn){
    fstream myFile;
    myFile.open(fileIn, ios::in);
    if (myFile.is_open()){
    // cout << "========them hoc sinh=======" << endl;
        Hocsinh temp;
        // cout << "nhap ma hs: ";
        for (int i = 0; i < 5;i++){
        getline(myFile, temp.MHS);
        // cout << "nhap Ten hs: ";
        getline(myFile,temp.TenHS);
        // cout << "nhap diem cac mon hoc." << endl;
        // cout << "toan: ";
        myFile >> temp.monhoc.Toan;
        // cout << "ly: ";
        myFile >> temp.monhoc.Ly;
        // cout << "hoa: ";
        myFile >> temp.monhoc.Hoa;
        // cout << "ngoai ngu: ";
        myFile >> temp.monhoc.Ngoaingu;
        myFile.ignore();
        // cout << "nhap dia chi: ";
        getline(myFile,temp.DiaChi);
        // cout << "nhap ghi chu: ";
        getline(myFile,temp.GhiChu);
        list.push_back(temp);
        // cout << "======end======" << endl;
        }
        myFile.close();
    }
    else{
        cout << "file cann't open" << endl;
    }
}

//In ra toan bo hoc sinh trong danh sacsh
void printListHS(vector<Hocsinh> list){
    cout << "=======print list hs======" << endl;
    for (int i = 0; i < list.size();i++){
        cout << "****hoc sinh " << i << " ****: " << endl;
        cout << "in ma hs: ";
        cout << list[i].MHS<<endl;
        cout << "in Ten hs: ";
        cout << list[i].TenHS<<endl;
        cout << "in diem cac mon hoc." << endl;
        cout << "toan: ";
        cout << list[i].monhoc.Toan<<endl;
        cout << "ly: ";
        cout << list[i].monhoc.Ly<<endl;
        cout << "hoa: ";
        cout << list[i].monhoc.Hoa<<endl;
        cout << "ngoai ngu: ";
        cout << list[i].monhoc.Ngoaingu<<endl;
        cout << "in dia chi: ";
        cout << list[i].DiaChi<<endl;
        cout << "in ghi chu: ";
        cout << list[i].GhiChu<<endl;
    }
    cout << "=======end======" << endl;
}

//Cap nhap thong tin hoc sinh tai vi tri index trong list
//Input list hoc sinh, va index tai vi tri can chinh sua
//Ouput danh sacsh sau khi da cap nhap hoc isnh tai vi tri index
void updateInfoHS(vector<Hocsinh> &list, int index){
    cout << "====Info hoc sinh cu====" << endl;
    cout << "****hoc sinh " << index << " ****: " << endl;
        cout << "in ma hs: ";
        cout << list[index].MHS<<endl;
        cout << "in Ten hs: ";
        cout << list[index].TenHS<<endl;
        cout << "in diem cac mon hoc." << endl;
        cout << "toan: ";
        cout << list[index].monhoc.Toan<<endl;
        cout << "ly: ";
        cout << list[index].monhoc.Ly<<endl;
        cout << "hoa: ";
        cout << list[index].monhoc.Hoa<<endl;
        cout << "ngoai ngu: ";
        cout << list[index].monhoc.Ngoaingu<<endl;
        cout << "in dia chi: ";
        cout << list[index].DiaChi<<endl;
        cout << "in ghi chu: ";
        cout << list[index].GhiChu<<endl;
    cout << "====end updating====" << endl;

    cout << "========cap nhap thong tin hoc sinh=======" << endl;
    Hocsinh temp;
    cout << "nhap ma hs: ";
    getline(cin,temp.MHS);
    cout << "nhap Ten hs: ";
    getline(cin,temp.TenHS);
    cout << "nhap diem cac mon hoc." << endl;
    cout << "toan: ";
    cin >> temp.monhoc.Toan;
    cout << "ly: ";
    cin >> temp.monhoc.Ly;
    cout << "hoa: ";
    cin >> temp.monhoc.Hoa;
    cout << "ngoai ngu: ";
    cin >> temp.monhoc.Ngoaingu;
    cin.ignore();
    cout << "nhap dia chi: ";
    getline(cin,temp.DiaChi);
    cout << "nhap ghi chu: ";
    getline(cin,temp.GhiChu);

    list[index] = temp;
    cout << "======end======" << endl;
}

void removeHS(vector<Hocsinh> &list, int index){
    list.erase(list.begin() + index);
}

bool compareByMHS(const Hocsinh &a, const Hocsinh &b){
    return a.MHS < b.MHS;
}

bool compareByPoint(const Hocsinh &a, const Hocsinh &b){
    return (a.monhoc.Toan + a.monhoc.Van + a.monhoc.Ly + a.monhoc.Hoa + a.monhoc.Ngoaingu) <
           (b.monhoc.Toan + b.monhoc.Van + b.monhoc.Ly + b.monhoc.Hoa + b.monhoc.Ngoaingu);
}

double diemtrungbinh(Hocsinh a){
    return (a.monhoc.Toan + a.monhoc.Van + a.monhoc.Ly + a.monhoc.Hoa + a.monhoc.Ngoaingu) / 5;
}

int main(){
    string fileIn = "input2.txt", fileOut = "output.txt";
    vector<Hocsinh> list1;
    themhs(list1,fileIn);
    // printListHS(list1);
    // updateInfoHS(list1, 3);
    // removeHS(list1, 2);
    // printListHS(list1);

    //sortHS via MHS
    // sort(list1.begin(), list1.end(), compareByMHS);

    //sortHS via Diem (tinh theo diem tong)
    // sort(list1.begin(), list1.end(), compareByPoint);     
    // printListHS(list1);

    // cout << "diem trung binh hoc sinh 3" << endl;
    // cout << diemtrungbinh(list1[3]) << endl;
    //if else de ra xep loai hoc sinh

    //luu danh sach hoc sinh (dang excel)

    cout << endl
         << "hello world" << endl;
    return 0;
}