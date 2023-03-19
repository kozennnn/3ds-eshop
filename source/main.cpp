#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv) {
    gfxInitDefault();

    PrintConsole topScreen, bottomScreen;

    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);

    consoleSelect(&topScreen)
    printf("\x1b[16;20HHello World");

    while(aptMainLoop()) {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
