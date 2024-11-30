#include <iostream>
#include <windows.h>
#include <string>

// Define the root directory you want to monitor
const std::wstring ROOT_DIRECTORY = L"C:\\Users\\tarun\\OneDrive\\Desktop\\root_code\\root\\";

// Function to set console text color
void setConsoleTextColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to check if a file path is inside the root directory
bool isInRootFolder(const std::wstring& filePath) {
    return filePath.find(ROOT_DIRECTORY) == 0; // Check if the file path starts with ROOT_DIRECTORY
}

// Function to process clipboard data and print details
void processClipboard() {
    // Open the clipboard to access its content
    if (OpenClipboard(nullptr)) {
        // Get data from the clipboard in the format of a file list
        HANDLE clipboardData = GetClipboardData(CF_HDROP);

        if (clipboardData != nullptr) {
            // Convert the clipboard data to a file list handle
            HDROP hDrop = (HDROP)clipboardData;

            // Get the number of files in the clipboard
            UINT fileCount = DragQueryFileW(hDrop, 0xFFFFFFFF, nullptr, 0);

            setConsoleTextColor(10); // Green for success
            std::wcout << L"Clipboard contains files:\n";

            // Loop through each file in the clipboard
            for (UINT i = 0; i < fileCount; ++i) {
                wchar_t filePath[MAX_PATH];
                DragQueryFileW(hDrop, i, filePath, MAX_PATH); // Get the file path
                std::wstring file(filePath);

                std::wcout << L"  " << file << L"\n";

                // Check if the file is inside the root directory
                if (isInRootFolder(file)) {
                    setConsoleTextColor(10); // Green for allowed
                    std::wcout << L"Access allowed: File is within the root directory.\n";
                } else {
                    setConsoleTextColor(12); // Red for denied
                    std::wcout << L"Access denied: File is outside the root directory.\n";
                }
            }

            // Clean up the file list handle
            DragFinish(hDrop);
        } else {
            setConsoleTextColor(14); // Yellow for warnings
            std::wcout << L"No files found in the clipboard.\n";
        }

        // Close the clipboard
        CloseClipboard();
    } else {
        setConsoleTextColor(12); // Red for errors
        std::wcout << L"Failed to open the clipboard.\n";
    }

    // Reset color to default (white)
    setConsoleTextColor(7);
}

int main() {
    setConsoleTextColor(11); // Cyan for informational messages
    std::wcout << L"Starting clipboard monitoring...\n";

    // Monitor the clipboard in a loop
    while (true) {
        processClipboard();
        Sleep(2000); // Wait for 2 second before checking again
    }

    // Reset color to default (white)
    setConsoleTextColor(7);

    return 0;
}
