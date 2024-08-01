// FlameApi.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include "FLAMEHttpServer.h"
#include <thread>

void gg()
{
    printf("GG\n");
}

int main()
{
    FLAMEHttpServer fserver;

    fserver.Get("/", [](HttpHandler* httphdl) {
        httphdl->AddStr("Test");
        });
    fserver.Start(8080);


    /*


    // Receive until the peer shuts down the connection
    do {

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);

            // Echo the buffer back to the sender
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();
    */

    int exitcode = -1;
    std::cout << "Enter 0 to exit." << std::endl;
    std::cin >> exitcode;
    while (exitcode != 0)
    {
        std::cin >> exitcode;
    }

    fserver.waitShutDown();

    return 0;
}
