#define COPY_TO_CLIPBOARD

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#ifdef COPY_TO_CLIPBOARD
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#ifdef COPY_TO_CLIPBOARD
namespace utils 
{
    void copy_to_clipboard(std::string data)
    {
        auto buf = GlobalAlloc(GMEM_MOVEABLE, data.size());
        memcpy(GlobalLock(buf), data.c_str(), data.size());
        GlobalUnlock(buf);

        OpenClipboard(nullptr);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, buf);
        CloseClipboard();

        GlobalFree(buf);
    }
}
#endif

int main()
{
    std::stringstream ss;

    ss << R"(function isOdd(num) {
    if (isNaN(num)) {
        throw "Input value is not a number!";
    } else {)" << std::endl;

    for (int i = -INT_MAX; i <= INT_MAX; ++i) {
        ss  << "        if (num === " << i << ")\n"
            << "            return " << ((!(i % 2)) ? "false;\n" : "true;\n");
    }
    ss << "    }\n}\n";

#ifdef COPY_TO_CLIPBOARD
    utils::copy_to_clipboard(ss.str());
    std::cout << "Code content copied to clipboard." << std::endl;
#else
    std::cout << ss.str() << std::endl;
#endif

    std::getchar();
}
