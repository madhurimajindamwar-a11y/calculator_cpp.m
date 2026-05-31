#include <windows.h>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

#define ID_EDIT      101
#define ID_BUTTON    102

int secretNumber;
int attempts = 0;

HWND hEdit;
HWND hResult;
HWND hAttempts;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg,
                            WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            srand((unsigned)time(NULL));
            secretNumber = rand() % 100 + 1;

            CreateWindowA(
                "STATIC",
                "Guess a Number Between 1 and 100",
                WS_VISIBLE | WS_CHILD,
                70, 20, 220, 25,
                hwnd, NULL, NULL, NULL);

            hEdit = CreateWindowA(
                "EDIT",
                "",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                110, 60, 120, 25,
                hwnd,
                (HMENU)ID_EDIT,
                NULL,
                NULL);

            CreateWindowA(
                "BUTTON",
                "Submit Guess",
                WS_VISIBLE | WS_CHILD,
                100, 100, 140, 35,
                hwnd,
                (HMENU)ID_BUTTON,
                NULL,
                NULL);

            hResult = CreateWindowA(
                "STATIC",
                "Start Guessing...",
                WS_VISIBLE | WS_CHILD,
                90, 150, 220, 25,
                hwnd,
                NULL,
                NULL,
                NULL);

            hAttempts = CreateWindowA(
                "STATIC",
                "Attempts: 0",
                WS_VISIBLE | WS_CHILD,
                120, 180, 120, 25,
                hwnd,
                NULL,
                NULL,
                NULL);

            break;
        }

        case WM_COMMAND:
        {
            if (LOWORD(wParam) == ID_BUTTON)
            {
                char buffer[50];
                GetWindowTextA(hEdit, buffer, 50);

                if (strlen(buffer) == 0)
                {
                    MessageBoxA(
                        hwnd,
                        "Please enter a number!",
                        "Input Error",
                        MB_OK | MB_ICONWARNING);
                    return 0;
                }

                int guess = atoi(buffer);
                attempts++;

                std::stringstream attemptText;
                attemptText << "Attempts: " << attempts;

                SetWindowTextA(
                    hAttempts,
                    attemptText.str().c_str());

                if (guess > secretNumber)
                {
                    SetWindowTextA(
                        hResult,
                        "Too High! Try Again.");
                }
                else if (guess < secretNumber)
                {
                    SetWindowTextA(
                        hResult,
                        "Too Low! Try Again.");
                }
                else
                {
                    std::stringstream winMessage;

                    winMessage << "Congratulations!\n\n"
                               << "You guessed the correct number: "
                               << secretNumber
                               << "\n\nTotal Attempts: "
                               << attempts;

                    MessageBoxA(
                        hwnd,
                        winMessage.str().c_str(),
                        "You Won!",
                        MB_OK | MB_ICONINFORMATION);

                    // New Game
                    secretNumber = rand() % 100 + 1;
                    attempts = 0;

                    SetWindowTextA(
                        hAttempts,
                        "Attempts: 0");

                    SetWindowTextA(
                        hResult,
                        "New Game Started!");

                    SetWindowTextA(
                        hEdit,
                        "");
                }
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(
        hwnd,
        msg,
        wParam,
        lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE,
                   LPSTR,
                   int nCmdShow)
{
    const char CLASS_NAME[] = "GuessingGame";

    WNDCLASSA wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowA(
        CLASS_NAME,
        "Number Guessing Game",
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        380,
        280,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (!hwnd)
        return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}