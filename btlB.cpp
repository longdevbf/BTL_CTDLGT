#include <bits/stdc++.h>
#include "func_vector.cpp"
#include "file_set.cpp"

using namespace std;

class Dictionary {
private:
    Set<string> dictionary;

public:
    void readFile(const string& myfile) {
        ifstream file(myfile);
        if (!file) {
            cerr << "khong the mo file: " << myfile << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                dictionary.insert_set(word);
            }
        }
        cout << "Doc file thanh cong!" << endl;
        file.close();
    }

    bool contains(const string& word) {
        return dictionary.find(word) != dictionary.end();
    }

    void displayWords(const Vector<string>& text) {
        cout << "Tu loi sai: ";
        bool found = false;
        for (int i = 0; i < text.getsize(); ++i) {
            string word = text[i];
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            if (!contains(word)) {
                cout << word << " ";
                found = true;
            }
        }
        if (!found) {
            cout << "Khong co tu nao sai";
        }
        cout << endl;
    }
     void saveDictionary(const string &filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto &word : dictionary) {
                file << word << endl;
            }
            file.close();
            cout << "Da ghi tu dien vao file : " << filename << endl;
        } else {
            cerr << "Khong the ghi duoc : " << filename << endl;
        }
    }
};

int main() {
    Dictionary dict;
    dict.readFile("dictionary.txt");

    cout << "Nhap vao doan van ban (xuong dong + nhap exit + enter -> out program) : " << endl;
    string input;
    Vector<string> words;
    while (true) {
        getline(cin, input);
        if (input == "exit") {
            break;
        }
        stringstream ss(input);
        string word;
        while (ss >> word) {
            words.pushBack(word);
        }
    }
    dict.displayWords(words);
    dict.saveDictionary("output.txt");
    return 0;
}
