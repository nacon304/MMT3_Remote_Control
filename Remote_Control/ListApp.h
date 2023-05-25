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

#pragma comment(lib, "advapi32.lib")

using namespace std;

std::vector<std::string> listAllApp()
{
    std::vector<std::string> installed_programs;

    HKEY hKey;
    LSTATUS result;

    // Mở registry key
    result = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &hKey);
    if (result != ERROR_SUCCESS) {
        std::cerr << "Không thể mở registry key." << std::endl;
        return {};
    }

    // Lấy số lượng subkey
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

    // Đóng registry key
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
//        std::cerr << ++cnt << ". " << program << std::endl;
    }

    return results;
}

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
//        std::cerr << ++cnt << ". " << program << std::endl;
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

void runApp(const std::string& exePath)
{
    std::wstring convertedPath = ConvertToWideString(ConvertExePath(exePath));
    std::wcerr << convertedPath << std::endl;

    ShellExecuteW(NULL, L"open", convertedPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
#endif // LISTAPP_H
