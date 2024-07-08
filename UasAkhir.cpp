//Muhammad Ihsan Putra Riadi Kelas: B
//20220140041 Pemograman dasar UAS 

#include <iostream>
using namespace std;

class MataKuliah
{
protected:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    MataKuliah()
    {
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
    }

    virtual void namaMataKuliah() { return; }

    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }

    float getPresensi()
    {
        return presensi;
    }

    void setActivity(float nilai)
    {
        this->activity = nilai;
    }

    float getActivity()
    {
        return activity;
    }

    void setExercise(float nilai)
    {
        this->exercise = nilai;
    }

    float getExercise()
    {
        return exercise;
    }

    void setTugasAkhir(float nilai)
    {
        this->tugasAkhir = nilai;
    }

    float getTugasAkhir()
    {
        return tugasAkhir;
    }

    virtual float hitungNilaiAkhir() = 0;

    virtual void cekKelulusan() = 0;
};

class Pemrograman : public MataKuliah
{
public:
    void namaMataKuliah()
    {
        cout << "Pemrograman" << endl;
    }

    float hitungNilaiAkhir()
    {
        return (presensi * 100) + (activity * 90) + (exercise * 87) + (tugasAkhir * 70);
    }

    void cekKelulusan()
    {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        if (nilaiAkhir >= 82.1)
            cout << "Selamat anda dinyatakan Lulus" << endl;
        else
            cout << "Anda dinyatakan Tidak Lulus" << endl;
    }
};

class Jaringan : public MataKuliah
{
public:
    void namaMataKuliah()
    {
        cout << "Jaringan" << endl;
    }

    float hitungNilaiAkhir()
    {
        return (activity * 45) + (exercise * 90);
    }

    void cekKelulusan()
    {
        float nilaiAkhir = hitungNilaiAkhir();
        cout << "Nilai Akhir : " << nilaiAkhir << endl;
        if (nilaiAkhir >= 63)
            cout << "Selamat anda dinyatakan Lulus" << endl;
        else
            cout << "Anda dinyatakan Tidak Lulus" << endl;
    }
};

int main()
{
    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    while (true)
    {
        cout << "Pilih Mata Kuliah :" << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
            mataKuliah = &pemrograman;
            break;
        case '2':
            mataKuliah = &jaringan;
            break;
        case '3':
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
            continue;
        }

        float nilai;
        cout << "Masukkan nilai presensi : ";
        cin >> nilai;
        mataKuliah->setPresensi(nilai);

        cout << "Masukkan nilai activity : ";
        cin >> nilai;
        mataKuliah->setActivity(nilai);

        cout << "Masukkan nilai exercise : ";
        cin >> nilai;
        mataKuliah->setExercise(nilai);

        if (pilih == '1')
        {
            cout << "Masukkan nilai tugas akhir : ";
            cin >> nilai;
            mataKuliah->setTugasAkhir(nilai);
        }

        mataKuliah->cekKelulusan();
    }

    return 0;
}
