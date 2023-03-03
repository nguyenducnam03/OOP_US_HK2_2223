//yeu cau co ban
//xu ly file van ban co cac chuc nanwg
//tao file, view noi dung file, xoa file
//doi ten file, copy file, cat cong file
//Vi vay mac dinh xu ly file trong truong hop nay la file txt

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
//Tao file txt
void taofile(){
    string nameFile;
    cout << "nhap ten file ban can tao (mac dinh .txt): ";
    cin >> nameFile;
    fstream myFile;
    myFile.open(nameFile+".txt", ios::out);
    myFile.close();
}

//view noi dung file
//input ten file
//output, viet vao file output noi dung file can xem (output la file mac dinh)
void xemndfile(string fileName){
    fstream myFile;
    
    myFile.open(fileName, ios::in);
    if (myFile.is_open()){
        string temp;
        while (getline(myFile, temp)) {
            cout << temp << endl;
        }
            myFile.close();
    }   
    else{
        cout << "file cann't open" << endl;
    }
}

//copy noi dung file txt file1 sang file2
void copyFile(string file1, string file2){
    fstream myF1, myF2;
    myF1.open(file1, ios::in);
    myF2.open(file2, ios::out);

    if (!myF1.is_open()){
        cout << "file 1 cann't open" << endl;
        return;
    }
    if (!myF2.is_open()){
        cout << "file 2 cann't open" << endl;
        return;
    }
    string temp;
    while(getline(myF1,temp)){
        myF2 << temp << endl;
    }
    myF1.close();
    myF2.close();
}

int main(){
    // taofile();
    // string fileName;
    // fileName = "input.txt";
    // xemndfile(fileName);
    // remove("ducnam2.txt");
    // rename("input.txt", "output.txt");
    // rename("output.txt","input.txt");
    // string input1 = "input.txt", input2 = "input2.txt";
    // copyFile(input1, input2);
    cout << endl
         << "hello world" << endl;
    return 0;
}