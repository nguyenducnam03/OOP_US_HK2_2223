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
string conghaisolon(string number1, string number2){
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
string truhaisolon(string number1, string number2){
    int len1 = number1.length();
    int len2 = number2.length();
    if (!checkGreater(number1,number2)){
        return "-" + truhaisolon(number2, number1);
    }
    int sizeMin = min(len1, len2);
    string result = "";
    int i = 0, temp = 0, sumLast = 0;
    for (; i < sizeMin;i++){
        
    }
}

int main(){
    string number1, number2;
    string fileName = "input.txt";
    inputNumber(number1, number2, fileName);
    cout << number1 << endl;
    cout << number2 << endl;
    // cout << "result: " << conghaisolon(number1, number2);
    // cout << "result: " << truhaisolon(number1, number2);

    string a = "23456789";
    string b = "23456887";
    cout << checkGreater(a, b);

    cout << endl
         << "hello world" << endl;
    return 0;
}