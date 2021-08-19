#include <stdio.h>
#include "diretorio.h"

int main()
{
    char folder_name[20];
    int folder_file_length;
    int opcode;

    scanf("%s %d", folder_name, &folder_file_length);
    fflush(stdin);

    Folder *folder = createFolder(folder_name, folder_file_length);

    do{
        scanf("%d", &opcode);
        fflush(stdin);
        switch(opcode)
        {
            case 2:
                deleFilesAndFolder(folder);
                break;

            case 3:
                addFileFolder(folder);
                break;

            case 4:
                printf("%d\n", removeFileFolder(folder));
                break;

            case 5:
                printf("%.6f\n", folderSize(folder));
                break;

            case 6:
                printf("%s\n", getFolderName(folder));
                break;

            case 7:
                renameFolder(folder);
                break;

            case 8:
                printf("%d\n", renameFileFolder(folder));
                break;

            case 9:
                listFolderFile(folder);
                break;
        }

    } while(opcode != 10);

    return 0;
}
