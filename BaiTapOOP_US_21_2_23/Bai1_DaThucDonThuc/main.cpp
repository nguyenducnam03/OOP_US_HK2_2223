#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string nhapdonthuc(string &rs, string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open()){
        int bac = 0, sohang = 0;
        // cout << "nhap bac cua don thuc: ";
        myFile >> bac;
        // cout << "nhap so hang cua don thuc ";
        myFile >> sohang;
        rs = to_string(sohang) + "x^" + to_string(bac);
        myFile.close();
        return rs;
    }
    else{
    cout << "file cann't open" << endl;
    }
    return rs;
}

string nhapdathuc(string &rs, string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open()){
        int bacMax = 0, sohang = 0;
        // cout << "nhap bac cao nhat cua da thuc: ";
        myFile >> bacMax;
        // cout << "nhap so hang cua cac phan tu da thuc thuc thu tu giam dan";
        for (int i = 0; i <= bacMax;i++){
            myFile >> sohang;
            rs = rs + to_string(sohang) + "x^" + to_string(i);
            if (i<bacMax){
                rs = rs + " + ";
            }
        }
        myFile.close();
        return rs;
    }
    else{
    cout << "file cann't open" << endl;
    }
    return rs;
}

double fdonthuc(string rsdon, int x){
    string sohang = "", somu = "";
    int i = 0;
    for (; i < rsdon.length();i++){
        if (rsdon[i]=='x'){
            break;
        }
        else{
            sohang = sohang + rsdon[i];
        }
    }
    i = i + 2;//dua den vi tri so mu
    for (; i < rsdon.length();i++){
        somu = somu + rsdon[i];
    }
    double kq = atoi(sohang.c_str()) * pow(x, atoi(somu.c_str()));
    // cout << sohang << " : " << somu << endl;
    return kq;
}

double fdathuc(string rsda, int x){
    string rsdon = "";
    double kq = 0;
    for (int i = 0; i < rsda.length();i++){
        if (rsda[i]==' ' || i==rsda.length()-1){
            kq = kq + fdonthuc(rsdon, x);
            rsdon = "";
        }
        else{
            rsdon = rsdon + rsda[i];
        }
    }
    return kq;
}

//xet truong hop nay la hoac hai don thuc cung bac, hoac cos 1 la rong
//input hai don thuc
//output donthuc ket qua
string conghaidonthuc(string a, string b){
    if (a==""){
        return b;
    }
    else if (b==""){
        return a;
    }
    string bac1 = "", bac2 = "";
    for (int i = 0; i < a.length();i++){
        if (a[i]=='^'){
            break;
        }
        bac1 = bac1 + a[i];
    }
    for (int i = 0; i < b.length();i++){
        if (b[i]=='^'){
            break;
        }
        bac2 = bac2 + b[i];
    }
    bac1 = to_string(atoi(a.c_str()) + atoi(b.c_str()));
    string result = "";
    for (int i = a.length() - 1; i > 0;i--){
        if (a[i]=='x'){
            result = a[i] + result;
            break;
        }
        result = a[i] + result;
    }
    result = bac1 + result;
    return result;
}

//tim ket qua don thuc cong mot da thuc
//input a la don thuc, b la da thuc
//output da thuc ket qua
string doncongdathuc(string a, string b){
    string result = "";
    string mudon = "";
    for (int i = a.length() - 1; i > 0;i--){
        if (a[i]=='x'){
            mudon = a[i] + mudon;
            break;
        }
        mudon = a[i] + mudon;
    }
    if (b.find(mudon)<b.length())
    {
        int pos2 = b.find(mudon);
        pos2 = pos2 - 1;
        string temphs = "";
        while(b[pos2]!=' ' && pos2!=-1){
            temphs = b[pos2] + temphs;
            pos2--;
        }
        string hesodon = "";
        for (int i = 0; i < a.length();i++){
            if (a[i]=='x'){
                break;
            }
            hesodon = hesodon + a[i];
        }
        string hesocuoi = to_string(atoi(hesodon.c_str()) + atoi(temphs.c_str()));
        b.replace(pos2 + 1, b.find(mudon) - pos2 - 1, hesocuoi);
        return b;
    }
    else{
        b = b + " + " + a;
        return b;
    }
}

//cong hai da thuc
//input hai da thuc
//output ket qua phep cong
//nen tang la su dung hai ham tren don cong don, dong cong da
//tim ra tung ham don trong a xong cong don voi b
string conghaidathuc(string a, string b){
    string don1 = "";
    int len1 = a.length();
    for (int i = 0; i <= len1;i++){
        if (a[i]==' '|| a[i] == '+' || i==len1){
            if (don1==""){
                continue;
            }
            b = doncongdathuc(don1, b);
            don1 = "";
        }else{
            don1 = don1 + a[i];
        }
    }
    return b;
}

string socuadonthuc(string a){
    string temp = "";
    int i = 0;
    while (a[i]!='x'){
        temp = temp + a[i];
        i++;
    }
    return temp;
}

string mucuadonthuc(string a){
    string temp = "";
    int i = a.length()-1;
    while (a[i]!='^'){
        temp = a[i] + temp;
        i--;
    }
    return temp;
}

//tuong tu phep nhan no se giong phep cong
//nen tang la nhan don voi don, nhan don voi da
string donnhandonthuc(string a, string b){
    int temp1 = atoi(socuadonthuc(a).c_str());
    int temp2 = atoi(socuadonthuc(b).c_str());
    string so = to_string(atoi(socuadonthuc(a).c_str()) * atoi(socuadonthuc(b).c_str()));
    string mu = to_string(atoi(mucuadonthuc(a).c_str()) + atoi(mucuadonthuc(b).c_str()));
    return so + "x^" + mu;
}

//b la da thuc
string donnhandathuc(string a, string b){
    string don1 = "";
    string result = "";
    int len1 = b.length();
    for (int i = 0; i <= len1;i++){
        if (b[i]==' '|| b[i] == '+' || i==len1){
            if (don1==""){
                continue;
            }
            string temp = donnhandonthuc(don1, a);
            if (i==len1){
                result = result + temp;
            }
            else{
                result = result + temp + " + ";
            }

            don1 = "";
        }else{
            don1 = don1 + b[i];
        }
    }
    return result;
}

string danhandathuc(string a, string b){
    string don1 = "";
    string result = "";
    int len1 = a.length();
    for (int i = 0; i <= len1;i++){
        if (a[i]==' '|| a[i] == '+' || i==len1){
            if (don1==""){
                continue;
            }
            string temp = donnhandathuc(don1, b);
            result = conghaidathuc(result, temp);
            don1 = "";
        }else{
            don1 = don1 + a[i];
        }
    }
    return result;
}


int main(){

    string rsdon, rsda, rsdon2, rsda2;
    string fileNamedonthuc = "input.txt";
    string fileNamedathuc = "inputdathuc.txt";
    nhapdonthuc(rsdon, fileNamedonthuc);
    cout << "don thuc da nhap: " << rsdon << endl;
    nhapdathuc(rsda, fileNamedathuc);
    cout << "da thuc da nhap1: " << rsda << endl;
    nhapdathuc(rsda2, "input2.txt");
    cout << "da thuc da nhap2: " << rsda2 << endl;

    // cout << "don cong don: "<<conghaidonthuc("54x^6", "123x^6") << endl;
    // cout << "don cong da: " << doncongdathuc("2x^0", rsda) << endl;
    // cout << "da cong da: " << conghaidathuc("2x^0 + 3x^2 + 6x^4", rsda);

    // cout << socuadonthuc(rsdon) << endl;
    // cout << mucuadonthuc(rsdon) << endl;

    // cout << "don nhan don thuc:" << donnhandonthuc(rsdon, rsdon2) << endl;
    // cout << "don nhan da thuc:" << donnhandathuc(rsdon, rsda) << endl;
    // cout << "da nhan da thuc:" << danhandathuc(rsda, rsda2) << endl;



    cout << endl
         << "hello world" << endl;
    return 0;
}