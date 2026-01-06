#include <windows.h>

// Função de callback da janela (processa mensagens enviadas pelo Windows)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY: // Quando a janela é fechada
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // 1. Definir a classe da janela
    const char CLASS_NAME[] = "MinhaJanelaSimples";

    WNDCLASS wc = {};
    wc.lpfnWndProc   = WindowProc;      // Função que processa mensagens
    wc.hInstance     = hInstance;       // Instância do programa
    wc.lpszClassName = CLASS_NAME;      // Nome da classe
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW); // Cursor padrão
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // Cor de fundo

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Falha ao registrar a classe da janela!", "Erro", MB_ICONERROR);
        return 1;
    }

    // 2. Criar a janela
    HWND hwnd = CreateWindowEx(
        0,                              // Estilo estendido
        CLASS_NAME,                     // Nome da classe
        "MILKERIUM",        // Título da janela
        WS_OVERLAPPEDWINDOW,            // Estilo da janela
        CW_USEDEFAULT, CW_USEDEFAULT,   // Posição inicial
        300, 200,                       // Largura e altura
        NULL,                           // Sem janela pai
        NULL,                           // Sem menu
        hInstance,                      // Instância
        NULL                            // Parâmetros extras
    );

    if (!hwnd) {
        MessageBox(NULL, "MILKERIUM IS INFECTING", "Error", MB_ICONERROR);
        return 1;
    }

    // 3. Mostrar a janela
    ShowWindow(hwnd, nCmdShow);

    // 4. Loop de mensagens
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
