#include <rapidjson/document.h>
#include <Windows.h>

int main() {
    DWORD written;
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "Child process started!\n", 24, &written, NULL);
    rapidjson::Document doc;
    doc.Parse("{\"key\": 3}");
    const auto result = doc["key"].GetInt();
    return 0;
}
