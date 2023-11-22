#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"
#include <stdlib.h>

// Function definition for read and validate decode args
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    printf("INFO : Opening required files\n");
    if (strcmp(strstr(argv[2], "."), ".bmp") == 0)
    {
        printf("INFO : Opened %s\n",argv[2]);
        decInfo->d_src_image_fname = argv[2];
    }
    else
        return e_failure;
    if (argv[3] != NULL)
        decInfo->d_secret_fname = argv[3];
    else
        decInfo->d_secret_fname = "decode.txt";
    return e_success;
}

// Function definition for open files for decoding
Status open_files_dec(DecodeInfo *decInfo)
{
    //Stego Image file
    decInfo->fptr_d_src_image = fopen(decInfo->d_src_image_fname, "r");

    //Do Error handling
    if (decInfo->fptr_d_src_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_src_image_fname);
        return e_failure;
    }
    //Dest file
    decInfo->fptr_d_secret = fopen(decInfo->d_secret_fname, "w");

    //Do Error handling
    if (decInfo->fptr_d_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->d_secret_fname);
        return e_failure;
    }

    // If no failure then return e_success
    return e_success;
}

// Function definition for decode magic string
Status decode_magic_string(DecodeInfo *decInfo)
{
    fseek(decInfo->fptr_d_src_image, 54, SEEK_SET);
    int i = strlen(MAGIC_STRING);

    decInfo->magic_data = malloc(strlen(MAGIC_STRING) + 1);
    decode_data_from_image(strlen(MAGIC_STRING), decInfo->fptr_d_src_image, decInfo);

    decInfo->magic_data[i] = '\0';

    if (strcmp(decInfo->magic_data, MAGIC_STRING) == 0)
        return e_success;
    else
        return e_failure;
}

// Function definition for decoding data fom image
Status decode_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    int i;
    char str[8];
    for (i = 0; i < size; i++)
    {
        fread(str, 8, sizeof(char), fptr_d_src_image);
        decode_byte_from_lsb(&decInfo->magic_data[i], str);
    }

    return e_success;
}

// Function definition for decode byte from lsb
Status decode_byte_from_lsb(char *data, char *image_buffer)
{
    int bit = 7;
    unsigned char ch = 0x00;
    for (int i = 0; i < 8; i++)
    {
        ch = ((image_buffer[i] & 0x01) << i) | ch;
       
    }
    *data = ch;
//   printf("%d\n",*data);
    return e_success;
}

// Function definition for decode file extn size
Status decode_file_extn_size(int size, FILE *fptr_d_src_image)
{
    char str[32];
    int length;

    fread(str, 32, sizeof(char), fptr_d_src_image);
    decode_size_from_lsb(str, &length);

    if (length == size)
        return e_success;
    else
        return e_failure;
}
// Function definition decode size from lsb
Status decode_size_from_lsb(char *buffer, int *size)
{
    int j = 31;
    int num = 0x00;
    for (int i = 0; i < 32; i++)
    {
        num = ((buffer[i] & 0x01) << i) | num;
    }
    *size = num;
}

// Function definition for decode secret file extn
Status decode_secret_file_extn(char *file_ext, DecodeInfo *decInfo)
{
    file_ext = ".txt";
    int i = strlen(file_ext);
    decInfo->d_extn_secret_file = malloc(i + 1);
    decode_extension_data_from_image(strlen(file_ext), decInfo->fptr_d_src_image, decInfo);

    decInfo->d_extn_secret_file[i] = '\0';

    if (strcmp(decInfo->d_extn_secret_file, file_ext) == 0)
        return e_success;
    else
        return e_failure;
}

// Function definition decode extension data from image
Status decode_extension_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo)
{
    for (int i = 0; i < size; i++)
    {
        fread(decInfo->d_src_image_fname, 8, 1, fptr_d_src_image);
        decode_byte_from_lsb(&decInfo->d_extn_secret_file[i], decInfo->d_src_image_fname);
    }
    return e_success;
}

// Function definition for decode secret file size
Status decode_secret_file_size(int file_size, DecodeInfo *decInfo)
{
    char str[32];
    fread(str, 32, sizeof(char), decInfo->fptr_d_src_image);
    decode_size_from_lsb(str, &file_size);
    decInfo->size_secret_file = file_size;
    

    return e_success;
}

// Function definition for decode secret file data
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char ch,ch1;
    for (int i = 0; i < decInfo->size_secret_file; i++)
    {
        fread (decInfo->d_src_image_fname, 8, sizeof(char), decInfo->fptr_d_src_image);
        decode_byte_from_lsb(&ch, decInfo->d_src_image_fname);
        fputc(ch, decInfo->fptr_d_secret);
        printf("%c",ch);
       
    }
   
    return e_success;
}

// Function definition for do decoding
Status do_decoding(DecodeInfo *decInfo)
{
    if (open_files_dec(decInfo) == e_success)
    {
        printf("INFO : Open files is a success\n");
        if (decode_magic_string(decInfo) == e_success)
        {
            printf("INFO : Decoded magic string Successfully\n");
            printf("INFO : Done\n");
            if (decode_file_extn_size(strlen(".txt"), decInfo->fptr_d_src_image) == e_success)
            {
                printf("INFO : Decoded file extension size Succesfully\n");
                printf("INFO : Done\n");
                if (decode_secret_file_extn(decInfo->d_extn_secret_file, decInfo) == e_success)
                {
                    printf("INFO : Decoded Secret File Extension Succesfully\n");
                    printf("INFO : Done\n");
                    
                    if (decode_secret_file_size(decInfo->size_secret_file, decInfo) == e_success)
                    {
                        printf("INFO : Decoded secret file size Successfully\n");
                        printf("INFO : Done\n");
                        printf("=====THE DECODED SERECT MSG IS=====\n");
                        if (decode_secret_file_data(decInfo) == e_success)
                        {
                            printf("INFO : Decoded secret file data Succuessfully\n");
                            printf("INFO : Done\n");

                        }
                        else
                        {
                            printf("ERROR : Decoding of secret file data is a failure\n");
                           // printf("INFO: DOne\n");
                        }
                    }
                    else
                    {
                        printf("ERROR : Decode of secret file size is a failure\n");
                        return e_failure;
                    }
                }
                else
                {
                    printf("ERROR : Decode of Secret file extension is a failure\n");
                    return e_failure;
                }
            }
            else
            {
                printf("ERROR : Decoded of file extension size is a failure\n");
                return e_failure;
            }
        }
        else
        {
            printf("ERROR : Decoding of magic string is a failure\n");
            return e_failure;
        }
    }
    else
    {
        printf("ERROR : Open files is a failure\n");
        return e_failure;
    }
    return e_success;
}
