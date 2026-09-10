#include "OpenSystem.h"
#include <iostream>
#include <locale>
#include <cstring>
#pragma comment(lib, "shell32.lib")

std::wstring GetExeDirectory()
{
    wchar_t path[MAX_PATH] = { 0 };
    GetModuleFileNameW(NULL, path, MAX_PATH);
    wchar_t* lastSlash = wcsrchr(path, L'\\');
    if (lastSlash)
    {
        *lastSlash = L'\0';
    }
    return std::wstring(path);
}

void OpenPDF(const wchar_t* fullPath)
{
    HINSTANCE hRes = ShellExecuteW(
        NULL,
        L"open",
        fullPath,
        NULL,
        NULL,
        SW_SHOWNORMAL
    );
    if ((INT_PTR)hRes <= 32)
    {
        std::wcout << L"ShellExecuteW Ê§”¡£¬åeÕ`´ú´a:" << (INT_PTR)hRes << std::endl;
    }
    else
    {
        std::wcout << L"ºô½ÐPDFé†×xÆ÷³É¹¦" << std::endl;
    }
}

int main() {
    std::wcout.imbue(std::locale(""));

    std::wcout << L"Text mq-XXX to open pdf" << std::endl;
    std::wstring input, Path;
    std::wcin >> input;

    std::wstring exeDir = GetExeDirectory();
    Path = exeDir + L"\\skills\\" + input + L".pdf";

    OpenPDF(Path.c_str());
    return 0;
}