#include <math.h>
#include <conio.h>
#include <string.h>
#include "windows.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

struct nut
{
    string masv;
    string hoten;
    string lop;
    float toan;
    float ly;
    float hoa;
    float diemtb;
    string xeploai;
    nut *next;
};
typedef nut *node;
node first;
int soLuongSinhVien(node first)
{
    int n = 0;
    node p = first;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}
void xuat_file(node first, string path)
{
    ofstream o;
    o.open(path.c_str());
    node p;
    p = first;
    o << soLuongSinhVien(first) << "\n";
    while (p != NULL)
    {
        o << p->masv << "\n";
        o << p->hoten << "\n";
        o << p->lop << "\n";
        o << p->toan << "\n";
        o << p->ly << "\n";
        o << p->hoa << "\n";
        o << p->diemtb << "\n";
        p = p->next;
    }
}
void insert(string ma, string ten, string l, float toan, float ly, float hoa, float dtb, node &first)
{
    node p, q;
    p = new (nut);
    p->masv = ma;
    p->hoten = ten;
    p->lop = l;
    p->toan = toan;
    p->ly = ly;
    p->hoa = hoa;
    p->diemtb = dtb;
    p->next = NULL;
    if (first == NULL)
        first = p;
    else
    {
        q = first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
void doc_file(node &first, string path)
{
    ifstream i;
    i.open(path.c_str());
    string ma;
    string ten;
    string l;
    float toan;
    float ly;
    float hoa;
    float dtb;
    int n;
    i >> n;
    string bf;
    getline(i, bf);
    while (n--)
    {
        getline(i, ma);
        getline(i, ten);
        getline(i, l);
        i >> toan;
        i >> ly;
        i >> hoa;
        i >> dtb;
        getline(i, bf);
        insert(ma, ten, l, toan, ly, hoa, dtb, first);
    }
}
bool checkTrungTen(node first, string ma)
{
    node q = first;
    while (q != NULL)
    {
        if (q->masv == ma)
            return 0;
        q = q->next;
    }
    return 1;
}
void themThongTin(string &ma, string &ten, string &lop, float &toan, float &ly, float &hoa, float &dtb, node &first)
{
    while (true)
    {
        cout << "\nPLEASE INPUT STUDENT'S ID  : ";
        getline(cin, ma);
        if (ma.length() > 0 && checkTrungTen(first, ma))
            break;
        else
            cout << "ERROR, ";
    }
    while (true)
    {
        cout << "PLEASE INPUT FULL NAME     : ";
        getline(cin, ten);
        if (ten.length() > 0)
            break;
        else
            cout << "ERROR, ";
    }
    while (true)
    {
        cout << "PLEASE INPUT CLASS         : ";
        getline(cin, lop);
        if (lop.length() > 0)
            break;
        else
            cout << "ERROR, ";
    }
    while (true)
    {
        string input;
        cout << "INPUT MATH SCORE(0-10)      : ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> toan && toan >= 0 && toan <= 10)
            break;
        cout << "ERROR, PLEASE ";
    }
    while (true)
    {
        string input;
        cout << "INPUT PHYSICS SCORE(0-10)   : ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> ly && ly >= 0 && ly <= 10)
            break;
        cout << "ERROR, PLEASE ";
    }
    while (true)
    {
        string input;
        cout << "INPUT CHEMISTRY SCORE(0-10) : ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> hoa && hoa >= 0 && hoa <= 10)
            break;
        cout << "ERROR, PLEASE ";
    }
    dtb = (toan + ly + hoa) / 3;
}
void nhap(node &first) // Ham nhap cua ds don
{
    system("cls");
    char ch;
    first = NULL;
    string ma, ten, lop;
    float toan, ly, hoa, dtb;
    do
    {
        themThongTin(ma, ten, lop, toan, ly, hoa, dtb, first);
        insert(ma, ten, lop, toan, ly, hoa, dtb, first);
        cout << "\n        PRESS ESC TO EXIT\n        PRESS ENTER TO CONTINUE";
        cin.sync();
        ch = _getch();
    } while (ch != 27);
}
void xuat(node first) // xuat xuoi
{
    char ch;
    system("cls");
    node p;
    p = first;
    while (p != NULL)
    {
        cout << "\nStudent's ID       : " << p->masv;
        cout << "\nFull Name          : " << p->hoten;
        cout << "\nClass              : " << p->lop;
        cout << "\nMath Score         : " << p->toan;
        cout << "\nPhysics Score      : " << p->ly;
        cout << "\nChemistry Score    : " << p->hoa;
        cout << "\nAverage Score      : " << p->diemtb << "\n";
        p = p->next;
    }
    cin.sync();
    ch = _getch();
}
void tim_ma(node first) // tim kiem sinh vien theo ma
{
    system("cls");
    node p;
    p = first;
    string ma;
    char ch;
    cout << "\nInput Student's ID you are looking for : ";
    cin >> ma;
    while (p != NULL)
    {
        if (p->masv == ma)
        {
            cout << "\nStudent's ID       : " << p->masv;
            cout << "\nFull Name          : " << p->hoten;
            cout << "\nClass              : " << p->lop;
            cout << "\nMath Score         : " << p->toan;
            cout << "\nPhysics Score      : " << p->ly;
            cout << "\nChemistry Score    : " << p->hoa;
            cout << "\nAverage Score      : " << p->diemtb << "\n";
            cin.sync();
            ch = _getch();
            return;
        }
        p = p->next;
    }
    cout << "CANNOT FIND THIS STUDENT BY NAME";
    cin.sync();
    ch = _getch();
}
void xoa(node &first) // xoa sinh vien theo ma
{
    system("cls");
    node p, q;
    p = first;
    q = first;
    string ma;
    cout << "\nInput Student's ID to delete : ";
    cin >> ma;
    while (p != NULL && p->masv != ma)
        p = p->next;
    if (p == first)
        first = first->next;
    else
    {
        if (p == NULL)
        {
            cout << "\nCan's find student to delete!";
        }
        else
        {
            while (q != NULL && q->next != p)
                q = q->next;
            q->next = p->next;
        }
    }
    system("cls");
    xuat(first);
    _getch();
}
void themVaoDauDanhSach(node &first)
{
    system("cls");
    char ch;
    string ma, ten, lop;
    float toan, ly, hoa, dtb;
    themThongTin(ma, ten, lop, toan, ly, hoa, dtb, first);
    node p;
    p = new (nut);
    p->masv = ma;
    p->hoten = ten;
    p->lop = lop;
    p->toan = toan;
    p->ly = ly;
    p->hoa = hoa;
    p->diemtb = dtb;
    p->next = first;
    first = p;
    cin.sync();
    cin.sync();
    ch = _getch();
    ;
}
void themsv(node &first) // bo sung sv moi vao danh sach
{

    system("cls");
    char ch;
    string ma, ten, lop;
    float toan, ly, hoa, dtb;
    do
    {
        themThongTin(ma, ten, lop, toan, ly, hoa, dtb, first);
        insert(ma, ten, lop, toan, ly, hoa, dtb, first);
        cout << "\n        PRESS ESC TO EXIT\n        PRESS ENTER TO CONTINUE";
        cin.sync();
        cin.sync();
        ch = _getch();
    } while (ch != 27);
}
void dtb_max(node first) // in ra sinh vien co diem trung binh max
{
    char ch;
    system("cls");
    if (first == NULL)
    {
        cout << "THERE IS NO STUDENT IN LIST";
        cin.sync();
        ch = _getch();
        return;
    }
    node p = first, q = first, l = first;
    float max = p->diemtb;
    p = p->next;
    while (p != NULL)
    {
        if (p->diemtb > max)
        {
            max = p->diemtb;
            q = p;
        }
        p = p->next;
    }
    while (l != NULL)
    {
        if (l == q)
        {
            cout << "\nStudent's ID       : " << l->masv;
            cout << "\nFull Name          : " << l->hoten;
            cout << "\nClass              : " << l->lop;
            cout << "\nMath Score         : " << l->toan;
            cout << "\nPhysics Score      : " << l->ly;
            cout << "\nChemistry Score    : " << l->hoa;
            cout << "\nAverage Score      : " << l->diemtb << "\n";
            break;
        }
        l = l->next;
    }
    cin.sync();
    ch = _getch();
}
void hoanvi(float &a, float &b)
{
    float c = a;
    a = b;
    b = c;
}
void hoanvi1(string &a, string &b)
{
    string c = a;
    a = b;
    b = c;
}
void sapxep(node first) // sx sv tang dan theo dtb
{
    char ch;
    system("cls");
    node p = first, q;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->diemtb > q->diemtb)
            {
                hoanvi1(p->masv, q->masv);
                hoanvi1(p->hoten, q->hoten);
                hoanvi1(p->lop, q->lop);
                hoanvi(p->toan, q->toan);
                hoanvi(p->ly, q->ly);
                hoanvi(p->hoa, q->hoa);
                hoanvi(p->diemtb, q->diemtb);
            }
            q = q->next;
        }
        p = p->next;
    }
    xuat(first);
    cin.sync();
    ch = _getch();
}
void sapxepTheoTen(node first) // sx sv tang dan theo ten
{
    char ch;
    system("cls");
    node p = first, q;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->hoten > q->hoten)
            {
                hoanvi1(p->masv, q->masv);
                hoanvi1(p->hoten, q->hoten);
                hoanvi1(p->lop, q->lop);
                hoanvi(p->toan, q->toan);
                hoanvi(p->ly, q->ly);
                hoanvi(p->hoa, q->hoa);
                hoanvi(p->diemtb, q->diemtb);
            }
            q = q->next;
        }
        p = p->next;
    }
    xuat(first);
    cin.sync();
    ch = _getch();
}

void sua(node first) // sua sinh vien
{
    char ch;
    system("cls");
    node p;
    p = first;
    string ma;
    cout << "\nInput Student's ID you want to justify : ";
    getline(cin, ma);
    while (p != NULL)
    {
        if (p->masv == ma)
        {
            system("cls");
            char ch;
            string ma, ten, lop;
            float toan, ly, hoa, dtb;
            fflush(stdin);
            themThongTin(ma, ten, lop, toan, ly, hoa, dtb, p);
            p->masv = ma;
            p->hoten = ten;
            p->lop = lop;
            p->toan = toan;
            p->ly = ly;
            p->hoa = hoa;
            p->diemtb = dtb;
            cin.sync();
            ch = _getch();
            return;
        }
        p = p->next;
    }
    printf("CANNOT FILE THIS ID");
    cin.sync();
    ch = _getch();
    return;
}

void xoaDauDanhSach(node &first)
{
    char ch;
    if (first == NULL)
    {
        system("cls");
        cout << "\nTHERE IS NO STUDENT IN LIST\n";
        cin.sync();
        ch = _getch();
        return;
    }
    first = first->next;
    system("cls");
    xuat(first);
    cin.sync();
    ch = _getch();
}

void xoaCuoiDanhSach(node &first)
{
    char ch;
    node p;
    p = first;
    if (first == NULL)
    {
        system("cls");
        cout << "\nTHERE IS NO STUDENT IN LIST\n";
        cin.sync();
        ch = _getch();
        return;
    }
    if (p->next == NULL)
    {
        first = NULL;
        system("cls");
        xuat(first);
        cin.sync();
        ch = _getch();
        return;
    }
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    system("cls");
    xuat(first);
    cin.sync();
    ch = _getch();
}

void xoaTheoTen(node &first) // xoa sinh vien theo ma
{
    char ch;
    system("cls");
    node p, q;
    p = first;
    q = first;
    string name;
    cout << "\nInput Student's name to delete : ";
    getline(cin, name);
    while (p != NULL && p->hoten != name)
        p = p->next;
    if (p == first)
        first = first->next;
    else
    {
        if (p == NULL)
        {
            cout << "\nCan't find student to delete!";
            system("cls");
            xuat(first);
            cin.sync();
            ch = _getch();
        }
        else
        {
            while (q != NULL && q->next != p)
                q = q->next;
            q->next = p->next;
        }
    }
    system("cls");
    xuat(first);
    cin.sync();
    ch = _getch();
}
void timTheoTen(node first)
{
    char ch;
    system("cls");
    node p;
    p = first;
    string name;
    cout << "\nInput Student's name you are looking for : ";
    getline(cin, name);
    while (p != NULL)
    {
        if (p->hoten == name)
        {
            cout << "\nStudent's ID       : " << p->masv;
            cout << "\nFull Name          : " << p->hoten;
            cout << "\nClass              : " << p->lop;
            cout << "\nMath Score         : " << p->toan;
            cout << "\nPhysics Score      : " << p->ly;
            cout << "\nChemistry Score    : " << p->hoa;
            cout << "\nAverage Score      : " << p->diemtb << "\n";
            //                   cin.sync();
            ch = _getch();
            //            return;
        }
        p = p->next;
    }
    //    cout << "CANNOT FIND THIS STUDENT BY NAME";
    cin.sync();
    ch = _getch();
}
void inDiemTren(node first)
{
    char ch;
    system("cls");
    node p;
    p = first;
    float score;
    cout << "\nInput Student's average score : ";
    cin >> score;
    cout << "\nNhung hoc sinh co diem lon hon hoac bang " << score << " la: ";
    while (p != NULL)
    {
        if (p->diemtb >= score)
        {
            cout << "\nStudent's ID       : " << p->masv;
            cout << "\nFull Name          : " << p->hoten;
            cout << "\nClass              : " << p->lop;
            cout << "\nMath Score         : " << p->toan;
            cout << "\nPhysics Score      : " << p->ly;
            cout << "\nChemistry Score    : " << p->hoa;
            cout << "\nAverage Score      : " << p->diemtb << "\n";
            //                   cin.sync();
//            ch = _getch();
            //            return;
        }
        p = p->next;
    }
    //    cout << "CANNOT FIND THIS STUDENT BY NAME";
    cin.sync();
    ch = _getch();
}
void inDiemDuoi(node first)
{
    char ch;
    system("cls");
    node p;
    p = first;
    int score;
    cout << "\nInput Student's average score : ";
    cin >> score;
    cout << "\nNhung hoc sinh co diem be hon bang " << score << " la: ";
    while (p != NULL)
    {
        if (p->diemtb <= score)
        {
            cout << "\nStudent's ID       : " << p->masv;
            cout << "\nFull Name          : " << p->hoten;
            cout << "\nClass              : " << p->lop;
            cout << "\nMath Score         : " << p->toan;
            cout << "\nPhysics Score      : " << p->ly;
            cout << "\nChemistry Score    : " << p->hoa;
            cout << "\nAverage Score      : " << p->diemtb << "\n";
            //                   cin.sync();
//            ch = _getch();
            //            return;
        }
        p = p->next;
    }
    //    cout << "CANNOT FIND THIS STUDENT BY NAME";
    cin.sync();
    ch = _getch();
}
void menu()
{
    int opt = 1;
    while (opt)
    {
        cout << "\n\t\t\t\t\t _______________________________________\n";
        cout << "\t\t\t\t\t|                                       |\n";
        cout << "\t\t\t\t\t|          STUDENT MANAGEMENT           |";
        //				cout << "\t\t\t\t\t|                                       |";
        cout << "\n\t\t\t\t    ____|_______________________________________|____\n";
        cout << "\t\t\t\t   |                     ______                      |\n";
        cout << "\t\t\t\t   |                 .-'        '-.                  |\n";
        cout << "\t\t\t\t   |                (              )                 |\n";
        cout << "\t\t\t\t   |      _         |              |          _      |\n";
        cout << "\t\t\t\t   |     ( )       (    .-.  .-.  , )        ( )     |\n";
        cout << "\t\t\t\t   |       > 'o _    | )(_)  (_)( |     _ o' <       |\n";
        cout << "\t\t\t\t   |     (_)'o _'=. |(    (  )     )| .=' o'(_)      |\n";
        cout << "\t\t\t\t   |             'o '(     ^^     )' o'              |\n";
        cout << "\t\t\t\t   |               '=|__|IIIIII|__|='                |\n";
        cout << "\t\t\t\t   |               .='| (IIIIII) |'=.                |\n";
        cout << "\t\t\t\t   |           .='.='(           )'=._'=._           |\n";
        cout << "\t\t\t\t   |     ( )_.='_.='    --------     '=._'=._( )     |\n";
        cout << "\t\t\t\t   |       > .='                         '=. <       |\n";
        cout << "\t\t\t\t   |     ()                                   ()     |";
        cout << "\n\t\t\t\t   |_________________________________________________|\n";
        cout << "\t\t\t\t\t|                                       |\n";
        cout << "\t\t\t\t\t|      1/ GENERATE NEW STUDENT LIST     |\n";
        cout << "\t\t\t\t\t|      2/ PRINT ALL STUDENT             |\n";
        cout << "\t\t\t\t\t|      3/ FIND STUDENT BY ID            |\n";
        cout << "\t\t\t\t\t|      4/ DELETE STUDENT BY ID          |\n";
        cout << "\t\t\t\t\t|      5/ ADD NEW STUDENT               |\n";
        cout << "\t\t\t\t\t|      6/ MAX AVERAGE SCORE             |\n";
        cout << "\t\t\t\t\t|      7/ SORT ALL STUDENT'S BY SCORE   |\n";
        cout << "\t\t\t\t\t|      8/ JUSTIFY STUDENT INFO          |\n";
        cout << "\t\t\t\t\t|      9/ SORT ALL STUDENT'S BY NAME    |\n";
        cout << "\t\t\t\t\t|      10/ EXPORT TO FILE               |\n";
        cout << "\t\t\t\t\t|      11/ IMPORT FROM FILE             |\n";
        cout << "\t\t\t\t\t|      12/ ADD TO TOP OF THE LIST       |\n";
        cout << "\t\t\t\t\t|      13/ DELETE THE END OF THE LIST   |\n";
        cout << "\t\t\t\t\t|      14/ DELETE THE TOP OF THE LIST   |\n";
        cout << "\t\t\t\t\t|      15/ DELETE BY NAME               |\n";
        cout << "\t\t\t\t\t|      16/ FIND STUDENT BY NAME         |\n";
        cout << "\t\t\t\t\t|      17/ FIND STUDENT WITH GPA ABOVE  |\n";
        cout << "\t\t\t\t\t|      18/ FIND STUDENT WITH GPA BELOW  |\n";
        cout << "\t\t\t\t\t|_______________________________________|\n";
        cout << "\t\t\t\t\tYOUR CHOICE: ";
        cin >> opt;
        string bf;
        getline(cin, bf);
        switch (opt)
        {
        case 1:
            nhap(first);
            break;
        case 2:
            xuat(first);
            break;
        case 3:
            tim_ma(first);
            break;
        case 4:
            xoa(first);
            break;
        case 5:
            themsv(first);
            break;
        case 6:
            dtb_max(first);
            break;
        case 7:
            sapxep(first);
            break;
        case 8:
            sua(first);
            break;
        case 9:
            sapxepTheoTen(first);
            break;
        case 10:
            xuat_file(first, "sinhvien.txt");
            break;
        case 11:
            doc_file(first, "sinhvien.txt");
            break;
        case 12:
            themVaoDauDanhSach(first);
            break;
        case 13:
            xoaCuoiDanhSach(first);
            break;
        case 14:
            xoaDauDanhSach(first);
            break;
        case 15:
            xoaTheoTen(first);
            break;
        case 16:
            timTheoTen(first);
            break;
        case 17:
            inDiemTren(first);
            break;
        case 18:
            inDiemDuoi(first);
            break;
        default:
            cout << "\n\t\t\t\t\t\t        _______ \n";
            cout << "\t\t\t\t\t\t       |       |\n";
            cout << "\t\t\t\t\t\t       | ERROR |\n";
            cout << "\t\t\t\t\t\t       |_______|\n";
            opt = 0;
            break;
        }
    }
}
int main()
{
    // nhap(first);
    // xuat(first);111
    // //        tim_ma(first);
    // //        xoa(first);
    // //        xuat(first); // xuat sau khi xoa
    // //        themsv(first);
    // //        xuat(first); // xuat sau khi them
    // //        dtb_max(first);
    // //        sapxep(first);
    // //        xuat(first); // xuat sau khi sap xep
    menu();
    return 0;
}
