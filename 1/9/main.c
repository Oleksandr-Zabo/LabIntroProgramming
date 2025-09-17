#include <windows.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define WIDTH 500
#define HEIGHT 500
#define N 5

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void DrawPentagonAndCircle(HDC hdc) {
    int cx = WIDTH / 2, cy = HEIGHT / 2, R = 180;
    POINT pent[N];
    for (int i = 0; i < N; ++i) {
        double angle = 2 * M_PI * i / N - M_PI / 2;
        pent[i].x = (LONG)(cx + R * cos(angle));
        pent[i].y = (LONG)(cy + R * sin(angle));
    }

    HPEN hCirclePen = CreatePen(PS_SOLID, 6, RGB(255, 0, 0));
    HGDIOBJ oldPen = SelectObject(hdc, hCirclePen);
    HGDIOBJ oldBrush = SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Ellipse(hdc, cx - R, cy - R, cx + R, cy + R);
    SelectObject(hdc, oldBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(hCirclePen);

    HPEN hPentPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    oldPen = SelectObject(hdc, hPentPen);
    Polyline(hdc, pent, N);
    MoveToEx(hdc, pent[N-1].x, pent[N-1].y, NULL);
    LineTo(hdc, pent[0].x, pent[0].y);
    SelectObject(hdc, oldPen);
    DeleteObject(hPentPen);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "PentagonWin";
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    RegisterClass(&wc);

    HWND hwnd = CreateWindow("PentagonWin", "Pentagon and Circle",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        DrawPentagonAndCircle(hdc);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}