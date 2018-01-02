/*
  Beep関数による簡易年齢チェック(Mosquite)
  2014/02/26 Tubo
*/

#include <stdio.h>
#include <windows.h>
#include <commctrl.h>
#include "resource.h"

#pragma (lib, comctl32.lib)

#define DURATION 1000

HWND hWnd;
HINSTANCE hInst;

char szClassName[] = "Mosquite";
char szHz[10];

LRESULT CALLBACK DlgProc(HWND hDlgWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    HWND hBar;
    HICON hIcon;
    static int pos;

    hBar = GetDlgItem(hDlgWnd, IDC_SLIDER1);

    switch(msg){
        case WM_INITDIALOG:
            hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, 0);
            SendMessage(hDlgWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            InitCommonControls();
            SendMessage(hBar, TBM_SETRANGE, TRUE, MAKELPARAM(37, 32767));
            SendMessage(hBar, TBM_SETTICFREQ, 1000, 0);
            SendMessage(hBar, TBM_SETPOS, TRUE, 10000);
            SendMessage(hBar, TBM_SETPAGESIZE, 0, 200);
            break;

        case WM_COMMAND:
            switch(LOWORD(wp)){
                case IDC_BUTTON_1K:
                    Beep(1000,  DURATION);
                    break;
                case IDC_BUTTON_2K:
                    Beep(2000,  DURATION);
                    break;
                case IDC_BUTTON_3K:
                    Beep(3000,  DURATION);
                    break;
                case IDC_BUTTON_4K:
                    Beep(4000,  DURATION);
                    break;
                case IDC_BUTTON_5K:
                    Beep(5000,  DURATION);
                    break;
                case IDC_BUTTON_6K:
                    Beep(6000,  DURATION);
                    break;
                case IDC_BUTTON_7K:
                    Beep(7000,  DURATION);
                    break;
                case IDC_BUTTON_8K:
                    Beep(8000,  DURATION);
                    break;
                case IDC_BUTTON_9K:
                    Beep(9000,  DURATION);
                    break;
                case IDC_BUTTON_10K:
                    Beep(10000, DURATION);
                    break;
                case IDC_BUTTON_11K:
                    Beep(11000, DURATION);
                    break;
                case IDC_BUTTON_12K:
                    Beep(12000, DURATION);
                    break;
                case IDC_BUTTON_13K:
                    Beep(13000, DURATION);
                    break;
                case IDC_BUTTON_14K:
                    Beep(14000, DURATION);
                    break;
                case IDC_BUTTON_15K:
                    Beep(15000, DURATION);
                    break;
                case IDC_BUTTON_16K:
                    Beep(16000, DURATION);
                    break;
                case IDC_BUTTON_PLAY:
                    if(37 <= pos && pos <= 32767){
                        Beep(pos, DURATION);
                    }
                    break;
                case IDC_QUITE:
                    DestroyWindow(hDlgWnd);
                    break;
                default:
                    return DefWindowProc(hDlgWnd, msg, wp, lp);
            }
            break;

        case WM_VSCROLL:
            if(GetDlgItem(hDlgWnd, IDC_SLIDER1) == (HWND)lp){
                pos = SendMessage(hBar, TBM_GETPOS, NULL, NULL);
                sprintf(szHz, "%dHz", pos);
                SetDlgItemText(hDlgWnd, IDC_EDIT1, szHz);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hDlgWnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
    MSG msg;
    WNDCLASS wc;
    hInst = hInstance;

    wc.style         = 0;
    wc.lpfnWndProc   = DlgProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = DLGWINDOWEXTRA;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, MAKEINTRESOURCE(IDD_DIALOG1));
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = szClassName;

    RegisterClass(&wc);
    hWnd = CreateDialog(hInst,MAKEINTRESOURCE(IDD_DIALOG1),0,(DLGPROC)DlgProc);

    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0)){
        if(IsDialogMessage(hWnd,&msg) == FALSE){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (msg.wParam);
}
