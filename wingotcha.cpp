#include "stdafx.h"
#include "resource.h"
#include "MainWnd.h"

HINSTANCE g_hInstance = NULL;

void RunProtect()
{
    CMainWindow *pMainWindow = new CMainWindow(g_hInstance);

    pMainWindow->Register();
    if (pMainWindow != NULL)
    {
        WCHAR szTitle[DEFAULT_STRING_SIZE] = L"wingotcha";
        HWND hwnd = CreateWindowEx(
            WS_EX_TOPMOST,
            CMainWindow::g_wszMainClass,
            szTitle,
            WS_POPUP | WS_CLIPCHILDREN,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT, 
            CW_USEDEFAULT,
            NULL,
            NULL,
            g_hInstance,
            pMainWindow
        );
		if (hwnd)
        {
			pMainWindow->OnStartup(hwnd);
            pMainWindow->DoModal();
        }
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, PSTR , int)
{
    INITCOMMONCONTROLSEX iccex;

	g_hInstance = hInstance;
    iccex.dwSize = sizeof(iccex);
    iccex.dwICC  = ICC_BAR_CLASSES;
    InitCommonControlsEx(&iccex);

    HRESULT hr = CoInitialize(NULL);

    if (SUCCEEDED(hr))
    {
        RunProtect();
        CoUninitialize();
		return 0;
    }
    return 1;
}

