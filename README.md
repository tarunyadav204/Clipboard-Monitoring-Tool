# Clipboard Monitoring Tool

A lightweight C++ program to monitor clipboard contents for file copy-paste operations. The program checks if the files copied to the clipboard are within a specified root directory and displays relevant information with color-coded outputs.

---

## Features
- Monitors the clipboard every second for file copy-paste actions.
- Checks if clipboard files are within a specified root directory.
- Color-coded terminal output:
  - **Green**: Access allowed (file is within the root directory).
  - **Red**: Access denied (file is outside the root directory).
  - **Yellow**: No files found in the clipboard.
  - **Cyan**: Informational messages.
- Supports multiple files in the clipboard.
- Lightweight and easy to use.

---

## Requirements
- **Operating System**: Windows (required for clipboard and console APIs).
- **Compiler**: MinGW (g++) or Visual Studio (cl.exe).
- **Libraries**: 
  - Windows API (`user32`, `comdlg32`).

---

## How It Works
1. **Clipboard Access**:
   - Opens the clipboard and checks if it contains file paths.
   - Uses the `CF_HDROP` format to retrieve file paths.

2. **File Validation**:
   - Compares each file path to the specified root directory.
   - Determines whether access is allowed or denied.

3. **Color-Coded Output**:
   - **Green**: File access is allowed.
   - **Red**: File access is denied.
   - **Yellow**: No files detected in the clipboard.
   - **Cyan**: Status or informational messages.

4. **Monitoring**:
   - The program continuously monitors the clipboard, polling every second.

---

## Installation

### 1. Clone the Repository
Download or clone the source code to your local machine:
```bash
https://github.com/tarunyadav204/Clipboard-Monitoring-Tool.git
cd clipboard-monitor
