#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

struct FileDetails {
    string withoutName;
    string lastName;
    string withoutP;
    string fileExtension;
    string fileW;
};

FileDetails parseFilePath(const string& filePath) {
    FileDetails details;

    size_t lastSlashPos = filePath.find_last_of("\\/");
    if (lastSlashPos != string::npos) {
        details.withoutName = filePath.substr(0, lastSlashPos);
    }

    size_t secondLastSlashPos = details.withoutName.find_last_of("\\/");
    if (secondLastSlashPos != string::npos) {
        details.lastName = details.withoutName.substr(secondLastSlashPos + 1);
    }

    size_t lastDotPos = filePath.find_last_of(".");
    if (lastDotPos != string::npos && lastDotPos > lastSlashPos) {
        details.withoutP = filePath.substr(lastSlashPos + 1);
    }

    if (!details.withoutP.empty()) {
        details.fileExtension = details.withoutP.substr(details.withoutP.find_last_of(".") + 1);
    }

    size_t fileNameStartPos = (lastSlashPos != string::npos) ? lastSlashPos + 1 : 0;
    size_t fileNameEndPos = (lastDotPos != string::npos && lastDotPos > lastSlashPos) ? lastDotPos : filePath.size();
    details.fileW = filePath.substr(fileNameStartPos, fileNameEndPos - fileNameStartPos);

    return details;
}

int main() {
    string filePath = "C:\\Step\\C++lesson_03\\Docs\\Less03.docx";
    FileDetails details = parseFilePath(filePath);

    cout << "a) " << details.withoutName << endl;
    cout << "b) " << details.lastName << endl;
    cout << "c) " << details.withoutP << endl;
    cout << "d) ." << details.fileExtension << endl;
    cout << "e) " << details.fileW << endl;

    return 0;
}
