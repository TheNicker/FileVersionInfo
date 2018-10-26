#include "FileVersionInfo.h"
#include <iostream>

int main()
{
    using namespace std;
    FileVersion::FileVersionInfo info;
    const FileVersion::string_type fileName = FILE_INFO_TEXT("c:\\Windows\\System32\\user32.dll");


    if (info.Init(fileName) == true)
    {
        using namespace FileVersion;
        const VersionQuadWord& fileVersion = info.GetFileVersion();

        wcout << endl << L"Showing version info for the file: " << fileName << endl;
        wcout << endl << L"File version       : " << fileVersion.major << "." << fileVersion.minor << "." << fileVersion.build << "." << fileVersion.revision;
        wcout << endl << L"Product version    : " << info.GetInfoString(StringInfoField::ProductVersion);
        wcout << endl << L"File description   : " << info.GetInfoString(StringInfoField::FileDescription);
        wcout << endl << L"Internal name      : " << info.GetInfoString(StringInfoField::InternalName);
        wcout << endl << L"Comments           : " << info.GetInfoString(StringInfoField::Comments);
        wcout << endl << L"Legal copyright    : " << info.GetInfoString(StringInfoField::LegalCopyright);
        wcout << endl << L"Legal trademarks   : " << info.GetInfoString(StringInfoField::LegalTrademarks);
        wcout << endl << L"Original file name : " << info.GetInfoString(StringInfoField::OriginalFileName);
        wcout << endl << L"Private build      : " << info.GetInfoString(StringInfoField::PrivateBuild);
        wcout << endl << L"Special build      : " << info.GetInfoString(StringInfoField::SpecialBuild);
    }
    else
    {
        wcout << endl << L"cannot open the file: " << fileName;
    }

    wcout << endl << L"Press any key to continue";

    getchar();
    return 0;
}
