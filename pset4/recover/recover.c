#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{   
    FILE *in_file, *out_file;
    unsigned char buffer[513]; //512 bytes and 0x00
    char filename[8];          //123.jpg and 0x00
    int  found = 0;
    bool writing = 0;

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    in_file = fopen(argv[1], "r");

    if (!in_file)
    {
        printf("File not found\n");
        return 1;
    }

    while (fread(buffer, 1, 512, in_file) == 512)
    {
        buffer[512] = 0x00; //Null byte at the end of the string
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0)
        {
            if (found > 0)
            {
                fclose(out_file);
            }
            found++;
            writing = true;
            sprintf(filename, "%03i.jpg", found);
            out_file = fopen(filename, "w");
        }
        
        if (writing)
        {
            fwrite(buffer, 512, 1, out_file);
        }
    }
    fclose(in_file);
    return 0;
}
