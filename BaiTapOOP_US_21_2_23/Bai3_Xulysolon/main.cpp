#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Ham nhap thong tin toa do tam giac tu du lieu trong file fileName
//Input bien tamgiac can nhap, ten fileName chua du lieu
//Output khong co, nhung tamgiac da mang toa do 3 dinh
void inputNumber(string &number1, string &number2, string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open()){
        myFile >> number1>> number2;
    }
    else{
        cout << "File cann't open" << endl;
    }
    myFile.close();
}

int min(int a, int b){
    if (a<=b){
        return a;
    }
    return b;
}

//Ham tinh tong hai so lon toi da 100 chu so nguyen duong a+b
//Dau vao hai so lon dang string
//Ouput tong cua hai so lon dang string
//Cach thuc: cong tu phai qua trai, nho 1 don vi vao temp
string conghaisolonnguyenduong(string number1, string number2){
    int len1 = number1.length();
    int len2 = number2.length();
    int sizeMin = min(len1, len2);
    string result = "";
    int i = 0, temp = 0, sumLast = 0;
    for (; i < sizeMin;i++){
        sumLast = temp + (int)number1[len1 - 1 - i] - 48 + (int)number2[len2 - 1 - i] - 48;
        temp = sumLast / 10;
        sumLast = sumLast % 10;
        result = to_string(sumLast)+result;
    }
    if (len1>len2){
        for (; i < len1;i++){
            sumLast = temp + (int)number1[len1 - 1 - i] - 48;
            temp = sumLast / 10;
            sumLast = sumLast % 10;
            result = to_string(sumLast)+result;
        }
    }
    else{
        for (; i < len2;i++){
            sumLast = temp + (int)number2[len2 - 1 - i] - 48;
            temp = sumLast / 10;
            sumLast = sumLast % 10;
            result = to_string(sumLast)+result;
        }
    }
    if (temp==1){
        result = to_string(temp)+result;
    }
    return result;
}

//Ham check xem so a co lon hon so b hay khong (a,b>0)
//input hai so string a,b
//output, true neu a>b, nguoc lai false
bool checkGreater(string a, string b){
    int len1 = a.length();
    int len2 = b.length();
    if (len1<len2){
        return false;
    }
    else if (len1==len2){
        for (int i = 0; i < len1;i++){
            if (a[i] < b[i]) {
                return false;
            }
            else if (a[i]>b[i]){
                return true;
            }
        }
    }
    return true;
}

//Ham tinh tru hai so lon toi da 100 chu so duong va a-b
//Dau vao hai so lon dang string
//Ouput tru cua hai so lon dang string
//Cach thuc: 
string truhaisolonnguyenduong(string number1, string number2){
    int len1 = number1.length();
    int len2 = number2.length();
    if (!checkGreater(number1,number2)){
        return "-" + truhaisolonnguyenduong(number2, number1);
    }
    int sizeMin = min(len1, len2);
    string result = "";
    int i = 0, temp = 0, sumLast = 0;
    for (; i < sizeMin;i++){
        sumLast = number1[len1 - 1 - i] - number2[len2 - 1 - i] - temp;
        if (sumLast<0){
            temp = 1;
            sumLast = sumLast + 10;
            result = to_string(sumLast) + result;
        }
        else{
            temp = 0;
            result = to_string(sumLast) + result;
        }
    }
    if (temp==1){
        for (; i < len1;i++){
            sumLast = (int)number1[len1-i-1] - 48 - temp;
            if (sumLast<0){
                temp = 1;
                sumLast = sumLast + 10;
                result = to_string(sumLast) + result;
            }
            else{
                temp = 0;
                result = to_string(sumLast) + result;
            }
        }
    }
    else{
        for (; i < len1;i++){
            result = number1[len1-1-i] + result;
        }
    }
    return result;
}

string conghaisolon(string a, string b){
    if (a[0]!='-' && b[0]!='-')
    {
        return conghaisolonnguyenduong(a, b);
    }
    else if (a[0]=='-'&&b[0]=='-'){
        return "-" + conghaisolonnguyenduong(a.substr(1, a.length() - 1), b.substr(1, b.length() - 1));
    }
    else if (b[0]=='-'){
        return truhaisolonnguyenduong(a, b.substr(1,b.length()-1));
    }
    else
        return truhaisolonnguyenduong(b, a.substr(1,a.length()-1));
}

string nhanhaisonguyenduong(string a, string b){
    int len1 = a.length();
    int len2 = b.length();
    int ketquanhan=0, temp = 0;
    string result = "";
    string result2 = "";
    for (int j = len2 - 1; j >= 0;j--){
        ketquanhan = 0;
        temp = 0;
        result2 = "";
        for (int i = len1 - 1; i >= 0;i--){
            ketquanhan = ((int)a[i] - 48) * ((int)b[j] - 48) + temp;
            temp = ketquanhan / 10;
            ketquanhan = ketquanhan % 10;
            result2 = to_string(ketquanhan) + result2;
        }
        if (temp>0){
            result2 = to_string(temp) + result2;
        }
        for (int k = len2 - 1; k > j;k--){
            result2 = result2 + '0';
        }
            // cout << "result2: " << result2 << endl;
        result = conghaisolonnguyenduong(result, result2);
    }
    return result;
}

bool sosanhhaisolon(string a, string b){
    if (a==""){
        return false;
    }
    if (a.length()>b.length()){
        return true;
    }
    else if (a.length() < b.length()){
        return false;
    }
    else{
        for (int i = 0; i < a.length();i++){
            if (a[i]>b[i]){
                return true;
            }
            else if (a[i]<b[i]){
                return false;
            }
        }
    }
    return true;
}

//chia hai so co cung do dai
string chiaachob(string a, string b){
    string index = "1";
        while (sosanhhaisolon(a,nhanhaisonguyenduong(b,index))){
        int temp = atoi(index.c_str());
        temp++;
        index = to_string(temp);
    }
    int temp = atoi(index.c_str());
    temp--;
    index = to_string(temp);
    return index;
}
//mac dinh la a > b
string chiahaisonguyenduong(string a, string b){
    int index = 0;
    int len1 = a.length();
    int len2 = b.length();
    string temp = "";
    int r = 0;
    string result = "";
    while (a!=""){
        while (!sosanhhaisolon(temp,b)){
            temp = temp + a[0];
            a.erase(0, 1);
            if (!sosanhhaisolon(temp,b)){
                result = result + '0';
                if (a==""){
                    return result;
                }
            }
        }
        r = atoi(chiaachob(temp, b).c_str());
        result = result + to_string(r);
        temp = truhaisolonnguyenduong(temp, nhanhaisonguyenduong(b, to_string(r)));
        while (temp[0]=='0'){
            temp.erase(0,1);
        }
    }   
    while (result[0]=='0'){
        result.erase(0,1);
    }
    return result;
}

int main(){
    string number1, number2;
    string fileName = "input.txt";
    inputNumber(number1, number2, fileName);
    cout << number1 << endl;
    cout << number2 << endl;
    // cout << "result: " << conghaisolon(number1, number2);
    // cout << "result: " << nhanhaisonguyenduong(number1, number2) << endl;
    // cout << "chia: " << chiaachob(number1, number2) << endl;
    // cout << "chia: " << chiahaisonguyenduong(number1, number2) << endl;
    cout << chiahaisonguyenduong(number1, number2);

    cout << endl
         << "hello world" << endl;
    return 0;
}