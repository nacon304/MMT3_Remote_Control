#ifndef LISTAPP_H
#define LISTAPP_H
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <locale>
#include <codecvt>
#include <tlhelp32.h>

#pragma comment(lib, "advapi32.lib")

using namespace std;

// Chỗ này lấy tất cả app trên máy, chỉ có tên
std::vector<std::string> listAllApp()
{
    std::vector<std::string> installed_programs;

    HKEY hKey;
    LSTATUS result;

    result = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey);
    if (result != ERROR_SUCCESS) {
        std::cerr << "Không thể mở registry key." << std::endl;
            return {};
    }

    DWORD subkeyCount;
    result = RegQueryInfoKey(hKey, NULL, NULL, NULL, &subkeyCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    if (result != ERROR_SUCCESS) {
        std::cerr << "Không thể truy vấn thông tin registry key." << std::endl;
                                                                                 return{};
    }

    // Liệt kê các subkey và in ra tên ứng dụng
    for (DWORD i = 0; i < subkeyCount; i++) {
        wchar_t subkeyName[256];
        DWORD subkeyNameLength = 256;
        result = RegEnumKeyExW(hKey, i, subkeyName, &subkeyNameLength, NULL, NULL, NULL, NULL);
        if (result != ERROR_SUCCESS) {
            std::cerr << "Không thể liệt kê subkey." << std::endl;
                                                                    return {};
        }

        HKEY appKey;
        result = RegOpenKeyExW(hKey, subkeyName, 0, KEY_READ, &appKey);
        if (result != ERROR_SUCCESS) {
            continue;
        }

        DWORD valueSize;
        wchar_t displayName[256];
        valueSize = 256;
        result = RegQueryValueExW(appKey, L"DisplayName", NULL, NULL, (LPBYTE)displayName, &valueSize);
        if (result != ERROR_SUCCESS) {
            continue;
        }

        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::wstring wideStr(displayName);
        installed_programs.push_back(converter.to_bytes(wideStr));

        RegCloseKey(appKey);
    }

    RegCloseKey(hKey);

    installed_programs.erase(unique(installed_programs.begin(), installed_programs.end()), installed_programs.end());
    sort(installed_programs.begin(), installed_programs.end());

    vector<string> results;
    int cnt = 0;
    for (auto const & program : installed_programs)
    {
        if(program == "${{arpDisplayName}}")
            continue;
        results.push_back(program);
    }

    return results;
}

// Chỗ này liệt kê các app có thể chạy được trên máy
vector<string> listAllAppRun()
{
    std::vector<std::string> installed_programs;

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths", 0, KEY_READ | KEY_WOW64_32KEY, &hKey) != ERROR_SUCCESS) {
        std::cerr << "Failed to open registry key" << std::endl;
        return {};
    }

    wchar_t szDisplayName[1024];
    wchar_t szKeyName[1024];
    DWORD dwSize = sizeof(szDisplayName);

    for (DWORD i = 0, retValue = ERROR_SUCCESS; retValue == ERROR_SUCCESS; ++i) {
        retValue = RegEnumKeyExW(hKey, i, szKeyName, &dwSize, NULL, NULL, NULL, NULL);
        dwSize = sizeof(szKeyName);

        if (retValue == ERROR_SUCCESS) {
            HKEY hSubKey;
            if (RegOpenKeyExW(hKey, szKeyName, 0, KEY_READ | KEY_WOW64_32KEY, &hSubKey) == ERROR_SUCCESS) {
                dwSize = sizeof(szDisplayName);
                if (RegQueryValueExW(hSubKey, NULL, NULL, NULL, (LPBYTE)szDisplayName, &dwSize) == ERROR_SUCCESS) {
                    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                    std::wstring wideStr(szDisplayName);
                    installed_programs.push_back(converter.to_bytes(wideStr));
                }
                RegCloseKey(hSubKey);
            }
        }
    }

    RegCloseKey(hKey);

    installed_programs.erase(unique(installed_programs.begin(), installed_programs.end()), installed_programs.end());

    vector<string> results;
    int cnt = 0;
    for (;cnt < installed_programs.size(); cnt++)
    {
        installed_programs[cnt].erase(remove(installed_programs[cnt].begin(), installed_programs[cnt].end(), '\"'), installed_programs[cnt].end());
        string program = installed_programs[cnt];
        results.push_back(program);
    }

    return results;
}

string ConvertExePath(const string& path)
{
    std::wstring convertedPath;
    char expandedPath[MAX_PATH];
    ExpandEnvironmentStringsA(path.c_str(), expandedPath, MAX_PATH);
    std::string newPath = std::string(expandedPath);

    for (char c : newPath)
    {
        if (c == '\\')
            convertedPath += L"\\\\";
        else
            convertedPath += wchar_t(c);
    }

    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideStr(convertedPath);
    string results= converter.to_bytes(wideStr);
    return results;
}

std::wstring ConvertToWideString(const std::string& str)
{
    int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    std::wstring wideStr(size, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wideStr[0], size);
    return wideStr;
}

// Muốn chạy áp nào thì vào đây
// Phải cho đường dẫn đầy đủ đến file thực thi
bool runApp(const std::string& exePath)
{
    std::wstring convertedPath = ConvertToWideString(ConvertExePath(exePath));
    std::wcerr << convertedPath << std::endl;

    ShellExecuteW(NULL, L"open", convertedPath.c_str(), NULL, NULL, SW_SHOWNORMAL);

    return true;
}


// Ví dụ: (tắt là tắt hết, suy nghĩ kĩ trước khi xài)
//const char* processName = "UniKeyNT.exe";
//if (closeApp(processName)) {
//    std::cout << "Process terminated successfully." << std::endl;
//} else {
//    std::cout << "Failed to terminate the process." << std::endl;
//}
bool closeApp(const char* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        return false;
    }

    bool found = false;
    do {
        int length = WideCharToMultiByte(CP_UTF8, 0, pe.szExeFile, -1, NULL, 0, NULL, NULL);
        char* buffer = new char[length];
        WideCharToMultiByte(CP_UTF8, 0, pe.szExeFile, -1, buffer, length, NULL, NULL);
        std::string result(buffer);
        delete[] buffer;

        if (_stricmp(result.c_str(), processName) == 0) {
            found = true;
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe.th32ProcessID);
            if (hProcess != NULL) {
                TerminateProcess(hProcess, 0);
                CloseHandle(hProcess);
            }
        }
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return found;
}

#endif // LISTAPP_H
