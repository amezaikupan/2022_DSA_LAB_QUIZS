//21120308_N2.cpp
// 21CTT3-N2
// Include cac thu vien
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Bai 01 ----------------------------------------------------------
struct Student {
    string name;
    float maths, literature;
};


//1.1
Student ReadStudent(string line) {
    string temp = "";
    vector <string> res;

    int i = 0;
    while (i < line.length()) {
        if (line[i] != ' ') {
            temp += line[i];
        }
        else {
            res.push_back(temp);
            temp = "";
        }
        i++;
    }
    res.push_back(temp);

    Student s;
    s.name = res[0];
    s.maths = stof(res[1]);
    s.literature = stof(res[2]);

    return s;

}

vector<Student> ReadStudents(string fileName) {
    //Read from file
    ifstream file (fileName);

    vector <Student> sList;
    Student s;

    string line = "";

    while (getline(file, line)) {
        s = ReadStudent(line);
        sList.push_back(s);
        line = "";
    }
    return sList;
}

//1.2
//Swap student functions
void swapStudent(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

void SortStudent(vector<Student> &list) {
    float max;
    int maxId;

    for (int i = 0; i < list.size(); i++) {
        max = list[i].literature;
        maxId = i;
        for (int j = i; j < list.size(); j++) {
            if (max < list[j].literature) {
                max = list[j].literature;
                maxId = j;
            }
        }
        swapStudent(list[maxId], list[i]);
    };
}

void Display(vector<Student> listStudents) {
    // TODO
    SortStudent(listStudents);

    for (int i = 0; i < listStudents.size(); i++) {
        cout << i << ". Student: " << listStudents[i].name
            << " - Math: " << listStudents[i].maths
            << " - Literature: " << listStudents[i].literature << endl;
    }
}

void Bai01() {
    vector<Student> listStudents;
    // Doc danh sach tu file
    listStudents = ReadStudents("data.txt");
    // Hien thi theo thu tu tang dan diem Van
    Display(listStudents);
}

// Bai 02 ----------------------------------------------------------
int RecursiveBinarySearch(int* a, int left, int right, int key) {
    // TODO
    int mid = left + (right - left) / 2;

    if (key == a[mid]) return mid;
    else if (key < a[mid]) return RecursiveBinarySearch(a, mid + 1, right, key);
    else return RecursiveBinarySearch(a, left, mid - 1, key);
}

void Bai02() {
    int a[7] = { 15, 12, 11, 10, 8, 7, 5 };
    int n = 7;
    int key = 11;
    cout << "The position of " << key << " in array: " << RecursiveBinarySearch(a, 0, n - 1, key) << "\n";
}

// Bai 03 ----------------------------------------------------------
int f(int n) {
    // TODO
    if (n == 0 || n == 1 || n == 2) return 1;
    else if (n == 3) return 2;
    else return f(n - 1) * f(n - 2) - f(n - 1);
}

void Bai03() {
    int n = 4;
    cout << "f(" << n << ") = " << f(n) << "\n";
}

// -----------------------------------------------------------------
int main() {
    Bai01();
    Bai02();
    Bai03();
    return 0;
}

// Comment nhung bai lam chua hoan thanh de tranh bien dich loi
// Bai RecursionBinarySearch co loi va chua bien dich duoc