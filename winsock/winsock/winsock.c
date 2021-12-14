#include <WinSock2.h>
#include <stdio.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)
void main()
{
    WSADATA wsadata;
    SOCKET soketTanim, istemciSoketTanim;
    struct sockaddr_in soketAdres;
    int sonuc, istemci_sayisi = 0;

    sonuc = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (sonuc) {
        puts("soket API basarisiz");
        return;

    }

    soketTanim = socket(AF_INET, SOCK_STREAM, 0);
    if (soketTanim == INVALID_SOCKET) {
        puts("Soket Basarisiz");
        return;
    }

    soketAdres.sin_family = AF_INET;
    //inet_addr(AF_INET, L"192.168.100.2", &soketAdres.sin_addr.s_addr);
    soketAdres.sin_addr.s_addr = inet_addr("192.168.100.2");
    soketAdres.sin_port = htons(2225);

    sonuc = bind(soketTanim, (SOCKADDR*)&soketAdres, sizeof(soketAdres));

    if (sonuc == SOCKET_ERROR)
        puts("Adres atamasi basarisiz");


    sonuc = listen(soketTanim, 5);
    if (sonuc == SOCKET_ERROR)
        puts("listen basarisiz");


    do {
        int bitir = 1;

        istemciSoketTanim = INVALID_SOCKET;

        while (istemciSoketTanim = accept(soketTanim, NULL, NULL));
        istemciSoketTanim = accept(soketTanim, NULL, NULL);

        do {
            char cikis[10] = "\0";

            recv(istemciSoketTanim, cikis, 10, 0);
            printf("Istemci: %s\n", cikis);

            if (strcmp(cikis, "cikis") == 0)
                bitir = -1;
            else if (strcmp(cikis, "OK") == 0)
                send(istemciSoketTanim, "Merhaba Istemci", 16, 0);

        } while (bitir != -1);
        Sleep(5000);
        puts("Istemci icin acilan soket kapatiliyor");
        closesocket(istemciSoketTanim);
        istemci_sayisi++;
    } while (istemci_sayisi <= 3);

    puts("Sunucu soketi kapatiliyor");
    closesocket(soketTanim);
    WSACleanup();
}