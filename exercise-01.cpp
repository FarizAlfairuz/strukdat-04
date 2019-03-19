/*
Author		: Falah Rizqi Abdullah Fairuz
NPM			: 140810180069
Kelas		: A
Deskripsi   : exercise linked list 1
Tanggal		:19 Maret 2019
*/

#include <iostream>
using namespace std;

struct pegawai
{
    char nama[20];
    char div[20];
    int gaji;
    pegawai* next;
};

typedef pegawai* pointer;
typedef pointer list;

void createlist (list& first)
{
    first = NULL;
}

void createPgw (pointer& pBaru)
{
    pBaru = new pegawai;
    cout << "Nama   : "; cin.ignore(); cin.getline(pBaru->nama, 20);
    cout << "Divisi : "; cin >> pBaru->div;
    cout << "Gaji   : "; cin >> pBaru->gaji;
    cout << endl;
    pBaru->next = NULL;
}

void insertFirst (list& first, pointer pBaru)
{
    if (first == NULL)
    {
        first = pBaru;
    }

    else
    {
        pBaru->next = first;
        first = pBaru;
    }
    
}

void insertLast (list& first, pointer pBaru)
{
    pointer last;
    if (first == NULL)
    {
        first = pBaru;
    }

    else
    {
        last = first;
        while(pBaru->next != NULL)
        {
            last = last->next;
        }
        last->next = pBaru;
    }
    
}

void deleteFirst (list& first, pointer& pHapus)
{
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }

    else if (first->next == NULL)
    {
        pHapus = first;
        first = NULL;
    }

    else
    {
        pHapus = first;
        first = first->next;
        pHapus->next = NULL;
    }
    
}

void deleteLast (list& first, pointer& pHapus)
{
    pointer last, preclast;
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }

    else if (first->next == NULL)
    {
        pHapus = first;
        first = NULL;
    }

    else
    {
        last = first;
        preclast = NULL;
        while (last->next != NULL)
        {
            preclast = last;
            last = last->next;
        }
        pHapus = last;
        preclast->next = NULL;
    }
    
}

void traversal (list first)
{
    pointer pBantu;
    if (first == NULL)
    {
        cout << "List kosong" << endl;
    }

    else
    {
        pBantu = first;
        do
        {
            cout << "Nama\t\t\tBidang\t\tGaji" << endl;
            cout << pBantu->nama << "\t\t\t" << pBantu->div << "\t\t" << pBantu->gaji << endl;
            cout << endl;
            pBantu = pBantu->next;
        } while (pBantu->next != NULL);
        
    }
    
}

main ()
{
    pointer p;
    list l;
    int menu;

    createlist (l);
    do
    {
        cout << "1. Insert first" << endl;
        cout << "2. Insert last" << endl;
        cout << "3. Delete first" << endl;
        cout << "4. Delete last" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : "; cin >> menu;

        switch (menu)
        {
            case 1:
                createPgw (p);
                insertFirst (l, p);
                break;

            case 2 :
                createPgw (p);
                insertLast (l, p);
                break;

            case 3 :
                deleteFirst (l, p);
                break;

            case 4 :
                deleteLast (l, p);
                break;

            case 5 :
                traversal (l);
                break;

            default:
                cout << "Exit" << endl;
                break;
        }
    } while (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5);
    
}