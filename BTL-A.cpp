#include <bits/stdc++.h>
#define Duc_Long main

using namespace std;

class student {
private:
    string name;
    int age;
    int masinhvien;
    float diem;

public:
    student(int age = 0, string name = "", int masinhvien = 0, float diem = 0)
        : age(age), name(name), masinhvien(masinhvien), diem(diem) {
    }

    friend istream& operator>>(istream& is, student& s) {
        cout << "Nhap vao ten sinh vien : " << endl;
        is.ignore();
        getline(is, s.name);
        cout << "Nhap ma sinh vien : " << endl;
        is >> s.masinhvien;
        cout << "Nhap tuoi cua sinh vien : " << endl;
        is >> s.age;
        cout << "Nhap diem cua sinh vien : " << endl;
        is >> s.diem;
        return is;
    }

    friend ostream& operator<<(ostream& os, const student& s) {
        os << left << setw(10) << s.masinhvien
           << setw(20) << s.name << setw(7)
           << s.age << setw(7) << s.diem;
        return os;
    }

    bool operator<(const student& other) const {
        return this->diem < other.diem;
    }

    int getid() const {
        return masinhvien;
    }

    string getname() const {
        return name;
    }
};

class control_student {
private:
    vector<student> v;

public:
   void readFile() {
    ifstream myfile("myfile.txt");
    if (myfile.is_open()) {
        cout << "Mo file thanh cong !" << endl;
    } else {
        cout << "Khong doc duoc file !" << endl;
        return;
    }

    string name;
    int masinhvien;
    int age;
    float diem;

    while (getline(myfile, name)) {
        myfile >> masinhvien;
        myfile >> age;
        myfile >> diem;
        myfile.ignore(numeric_limits<streamsize>::max(), '\n');
        
        student st(age, name, masinhvien, diem);
        push_vao_vector(st);
    }
    myfile.close();
}


    void push_vao_vector(const student& st) {
        v.push_back(st);
    }

    void xuat() const {
        cout << left << setw(11) << "ID : "
             << setw(20) << "Name" << setw(5)
             << "Age" << setw(5) << "Mark" << endl;

        cout << string(40, '-') << endl;
        for (const auto& k : v) {
            cout << k << endl;
        }
    }

    void find_student() {
        cout << "Nhap vao ma sinh vien can tim : " << endl;
        int msv;
        cin >> msv;
        auto res = find_if(v.begin(), v.end(), [msv](const student& l) {
            return l.getid() == msv;
        });
        if (res != v.end()) {
            cout << "Da tim thay sinh vien !" << endl;
            cout << *res;
        } else {
            cout << "Khong tim thay sinh vien co ma sinh vien nhu tren !" << endl;
        }
    }

    void xoa() {
        cout << "Nhap ma sinh vien cua sinh vien can xoa : " << endl;
        int msv;
        cin >> msv;
        auto it = find_if(v.begin(), v.end(), [msv](const student& u) {
            return u.getid() == msv;
        });
        if (it != v.end()) {
            v.erase(it);
            cout << "Da xoa thanh cong" << endl;
        } else {
            cout << "Khong tim thay sinh vien can xoa !" << endl;
        }
    }

    void add() {
        student o;
        cin >> o;
        push_vao_vector(o);
        cout << "Da them sinh vien thanh cong !" << endl;
    }

    void max() {
        if (v.empty()) {
            cout << "Danh sach sinh vien rong !" << endl;
            return;
        } else {
            auto maxStudent = max_element(v.begin(), v.end());
            cout << "Sinh vien co diem cao nhat la : " << endl<<*maxStudent << endl;
        }
    }

    void min() {
        if (v.empty()) {
            cout << "Danh sach sinh vien rong !" << endl;
            return;
        } else {
            auto minStudent = min_element(v.begin(), v.end());
            cout << "Sinh vien co diem thap nhat la : " <<endl<< *minStudent << endl;
        }
    }
};

Duc_Long() {
    control_student s;
    int x;
    do{
    	cout<<"0.Thoat !"<<endl;
    	cout<<"1. Doc thong tin sinh vien co san tu file !"<<endl;
    	cout<<"2. In danh sach sinh vien ra ngoai man hinh !"<<endl;
    	cout<<"3. Them sinh vien vao danh sach !"<<endl;
    	cout<<"4. Tim sinh vien khi biet so bao danh ."<<endl;
    	cout<<"5. Xoa sinh vien khi biet so bao danh ."<<endl;
    	cout<<"6. Tim sinh vien co so diem lon nhat ."<<endl;
    	cout<<"7. Tim sinh vien co so diem nho nhat ."<<endl;
    	cout<<"Moi ban chon : "<<endl;
    cin>>x;
    	switch(x){
    		case 1: s.readFile();break;
    		case 2: s.xuat();break;
    		case 3: s.add();break;
    		case 4: s.find_student();break;
    		case 5: s.xoa();break;
    		case 6: s.max();break;
    		case 7: s.min();break;
    		default: cout<<"Chuc nang khong hop le !"<<endl;
	    }
    }while(x != 0);
    
    
}
