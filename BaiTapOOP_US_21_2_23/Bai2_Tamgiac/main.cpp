#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct ToaDo{
    double x, y;
};

struct TamGiac{
    ToaDo dinh1, dinh2, dinh3;
};

//Tinh khoang cach giua hai dinh
//Input toa do 2 dinh dinh1 dinh2
//Output khoang cach giua hai dinh1 va dinh 2
double distance2(ToaDo toado1, ToaDo toado2){
    return sqrt(pow(toado1.x-toado2.x, 2) + pow(toado1.y-toado2.y,2));
}

//Ham check xem tam giac co hop le khong
//Input nhap vao 1 TamGiac
//Output check xem tam giac nay co hop le khong
bool checkTamGiac(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);

    if (kc12 +kc13<=kc23 || kc12+kc23<=kc13||kc13+kc23<=kc12){
        return false;
    }
    return true;
}

//Tinh dien tich tam giac
//Input tamgiac
//Output dien tich tam giac
double Area(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);
    double p = (kc12 + kc13 + kc23) / 2;
    return sqrt(p * (p - kc12) * (p - kc13) * (p - kc23));
}

//Tinh Chu vi tam giac
//Input tamgiac
//Output Chu vi tam giac
double Perimeter(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);

    return kc12 + kc13 + kc23;
}

bool checkTamGiacDeu(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);

    if (kc12==kc23 && kc12 ==kc13){
        return true;
    }
    return false;
}

bool checkTamGiacCan(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);

    if (kc12==kc23 || kc12 ==kc13 || kc23==kc13){
        return true;
    }
    return false;
}

bool checkTamGiacVuong(TamGiac tamgiac){
    double kc12 = distance2(tamgiac.dinh1, tamgiac.dinh2);
    double kc13 = distance2(tamgiac.dinh1, tamgiac.dinh3);
    double kc23 = distance2(tamgiac.dinh2, tamgiac.dinh3);

    if (pow(kc12,2)+pow(kc13,2)==pow(kc23,2) || pow(kc23,2)+pow(kc13,2)==pow(kc12,2) 
    || pow(kc12,2)+pow(kc23,2)==pow(kc13,2)){
        return true;
    }
    return false;
}

//Ham nhap thong tin toa do tam giac tu du lieu trong file fileName
//Input bien tamgiac can nhap, ten fileName chua du lieu
//Output khong co, nhung tamgiac da mang toa do 3 dinh
void inputTamGiac(TamGiac &tamgiac, string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open()){
        // cout << "Nhap tao do dinh1: " << endl;
        // cout << "X: ";
        myFile >> tamgiac.dinh1.x;
        // cout << "Y: ";
        myFile >> tamgiac.dinh1.y;

        // cout << "Nhap tao do dinh2: " << endl;
        // cout << "X: ";
        myFile >> tamgiac.dinh2.x;
        // cout << "Y: ";
        myFile >> tamgiac.dinh2.y;

        // cout << "Nhap tao do dinh3: " << endl;
        // cout << "X: ";
        myFile >> tamgiac.dinh3.x;
        // cout << "Y: ";
        myFile >> tamgiac.dinh3.y;
    }
    else{
        cout << "File cann't open" << endl;
    }
    myFile.close();
}


//Ham viet ra toa do 3 dinh vao file fileOut
//Input du lieu toa do tamgiac, fileOut de ghi toa do vao
//Output khong co, ghi truc tiep vao file Out toa do 3 dinh
void outputTamGiac(TamGiac tamgiac, string fileOut){
    fstream myFile;
    myFile.open(fileOut, ios::out);
    if (myFile.is_open()){
        myFile << "Xuat tao do dinh1: " << endl;
        myFile << "X: " << tamgiac.dinh1.x << " ; "
            << "Y: " << tamgiac.dinh1.y << endl;

        myFile<< "Xuat tao do dinh2: " << endl;
        myFile << "X: " << tamgiac.dinh2.x << " ; "
            << "Y: " << tamgiac.dinh2.y << endl;

        myFile << "Xuat tao do dinh3: " << endl;
        myFile << "X: " << tamgiac.dinh3.x << " ; "
            << "Y: " << tamgiac.dinh3.y << endl;

        if (checkTamGiac(tamgiac)){
            myFile << "Tam giac nay la hop le" << endl;
        }
        else{
            myFile << "Tam giac nay khong hop le" << endl;
        }
    }
    else{
        cout << "myFile cann't open";
    }

    myFile.close();
}

int main(){
    TamGiac tamgiac1;
    string fileName= "data.txt";
    string fileOut = "out.txt";
    inputTamGiac(tamgiac1,fileName);
    outputTamGiac(tamgiac1,fileOut);

    cout << endl
         << "hello world" << endl;
    return 0;
}