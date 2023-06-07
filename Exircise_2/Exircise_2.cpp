#include <iostream>
using namespace std;

class Bidangdatar {
private:
	int x;  //variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    Bidangdatar() { //constructor
        x = 0;
    }
    virtual void input() = 0;   //fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    virtual float Luas(int a) = 0; //fungsi untuk menghitung luas
    virtual float Keliling(int a) = 0; //fungsi untuk menghitung keliling
    void setX(int a) { //fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    int getx() {    //fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public Bidangdatar {
public:
    void input() {
        cout << "masukkan jari-jari: ";
        int r;
        cin >> r;
        setX(r);
    }
    float Luas(int r) {
        return 3.14 * r * r;
    }
    float keliling(int r){
        return 3.14 * r;
    }
};

class Bujursangkar : public Bidangdatar {
public:
    void input() {
        cout << "masukkan sisi: ";
        int s;
        cin >> s;
        setX(s);
    }
    float Luas(int s) {
        return s * s;
    }
    float keliling(int s) {
        return 4 * s;
    }
};

int main() {
    Bidangdatar* bdtr;

    cout << "Lingkaran dibuat" << endl;
    bdtr = new Lingkaran();
    bdtr->input();
    int r = bdtr->getx();
    cout << "Luas Lingkaran = " << bdtr->Luas(r) << endl;
    cout << "Keliling Lingkaran = " << bdtr->Keliling(r) << endl;

    cout << "\nBujursangkar dibuat" << endl;
    bdtr = new Bujursangkar();
    bdtr->input();
    int s = bdtr->getx();
    cout << "Luas Bujursangkar = " << bdtr->Luas(s) << endl;
    cout << "Keliling Bujursangkar = " << bdtr->Keliling(s) << endl;

    delete bdtr;
    return 0;
}