#include <iostream>
#include "WindowsManager.h"


int main(int argc, char *args[])
{
    WindowsManager window;
    if (!window.init())
    {
        std::cerr << "Unable to load Game" << std::endl;
        return 1;
    }
    window.running();
    window.close();
    return 0;
}
