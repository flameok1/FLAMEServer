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

    fserver.switchBolckMode(true);

    fserver.start(8080);

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
