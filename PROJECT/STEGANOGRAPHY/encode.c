#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include<string.h>

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    //printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
   // printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}


/* Read and validate cla for encoding*/
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    if(strcmp( (strstr(argv[2],".")) ,".bmp") ==0)
    {
        printf("INFO : Opened %s\n",argv[2]);
        encInfo->src_image_fname=argv[2];
    }
    else
    {
        return e_failure;
    }
    if(strcmp( (strstr(argv[3],".")) ,".txt") ==0 )
    {
        printf("INFO : Opened %s\n",argv[3]);
        encInfo->secret_fname = argv[3];
    }
    else
    {
        return e_failure;    
    }
    if(argv[4]!=NULL)
    {
        printf("INFO : Opended %s\n",argv[4]);
        encInfo->stego_image_fname = argv[4];
    }
    else
    {

        printf("INFO : Output File not mentioned. Creating data.bmp as default\n");
        encInfo->stego_image_fname = "data.bmp";
        printf("INFO : Opened data.bmp\n");
    }
    return e_success;
}


//image data size
uint get_file_size(FILE *fptr)
{
    fseek(fptr,0,SEEK_END);
    return ftell(fptr);
}


//to check the capacity 
Status check_capacity(EncodeInfo *encInfo)
{
    printf("INFO : Checking for secret.txt size\n");
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

    //to check whether the rgb iamge size is greater than the file size
    if(encInfo->image_capacity > (16+32+32+32+(encInfo->size_secret_file * 8)))
    {
        printf("INFO : DONE. NOT EMPTY\n");
        return e_success;
    }
    else
    {
        return e_failure;
    }
}

//to Encode scret file data
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    char str[encInfo->size_secret_file];
    fseek(encInfo->fptr_secret,0,SEEK_SET);
    fread(str,encInfo->size_secret_file,1,encInfo->fptr_secret);
    encode_data_to_image(str,encInfo->size_secret_file,encInfo);
    return e_success;
}
//encode of byte to lsb
Status encode_byte_to_lsb(char data,char *image_buffer)
{ 
    for(int i = 0; i < 8 ; i++)
    {
    image_buffer[i]=(image_buffer[i] & 0xFE) | ((data>>i) & 1);
    }
}


//to encode data to struct
Status encode_data_to_image(char *data,int size,EncodeInfo *encInfo)
{
    for(int i = 0; i < size ; i++ )
    {
        //reading 8 bytes from src file
        fread(encInfo->image_data,8,1,encInfo->fptr_src_image);
        //encoding 1 char in 8 bytes
        encode_byte_to_lsb(data[i],encInfo->image_data);
        //writing encoded data in dest image
        fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);
    }
    return e_success;
}


//encode MAGIC_STRING
Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)
{
   // printf("%s",magic_string);
    encode_data_to_image(magic_string,strlen(magic_string),encInfo);
    return e_success;
}

//encode size to lsb
Status encode_size_to_lsb(int size,EncodeInfo *encInfo)
{
    char str[32];
    fread(str,32,1,encInfo->fptr_src_image);
    for(int i = 0 ; str[i] < 31 ; i++)
    {
       str[i] = (str[i] & 0xFE) | ((size>>i) & 1);
    }
    fwrite(str,32,1,encInfo->fptr_stego_image);
}
//Encode secret file extn size
Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo)
{
    encode_size_to_lsb(size,encInfo);
    return e_success;
}

//Encode secret file extn
Status encode_secret_file_extn(char *file_extn,EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn,strlen(file_extn),encInfo);
    return e_success;
}

//Encode secret file size
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    encode_size_to_lsb(file_size,encInfo);
    return e_success;
}


//To copy the header
Status copy_bmp_header(EncodeInfo *encInfo)
{
    char str[54];
    fseek(encInfo->fptr_src_image,0,SEEK_SET);
    fread(str,54,1,encInfo->fptr_src_image);
    fwrite(str,54,1,encInfo->fptr_stego_image);

    return e_success;
}

//TO COPY REMAINING DATA
Status copy_remaining_img_data(EncodeInfo *encInfo)
{
    int len = (encInfo->image_capacity + 54) - ftell(encInfo->fptr_src_image);
    char str[len];
    fread(str,len,1,encInfo->fptr_src_image);
    fwrite(str,len,1,encInfo->fptr_stego_image);
    return e_success;
}


//To do encoding
Status do_encoding(EncodeInfo *encInfo)
{
    //to open file
   if( open_files(encInfo) == e_success)
   {
     
       printf("INFO : ## Encoding Procedure Started ##\n");
       
       //to check capacity
       if(check_capacity(encInfo) == e_success)
       {
           printf("INFO : Checking for .bmp file cpacity to handle .txt file\n");
           printf("INFO : DONE. FOUND OK\n");

           //to copy the header to default.bmp
           if( copy_bmp_header(encInfo) == e_success)
           {
               printf("INFO : Copied bmp header successfully\n");
               printf("INFO : Done\n");

               //to get magic string
               if(encode_magic_string(MAGIC_STRING,encInfo) == e_success)
               {
                   printf("INFO : Encoded magic string successfully\n");
                   printf("INFO : Done\n");

                   //to get the strings in secret file
                   strcpy(encInfo->extn_secret_file,strstr(encInfo->secret_fname , "."));
                   printf("INFO : The extern of secret file is : %s\n",encInfo->extn_secret_file);

                   //to get file extn size
                   if(encode_secret_file_extn_size(strlen(encInfo->extn_secret_file),encInfo) == e_success)
                   {
                       printf("INFO : Encoded secret file extern size successfully\n");
                       printf("INFO : Done\n");

                       //to get sile extn
                       if( encode_secret_file_extn(encInfo->extn_secret_file,encInfo) == e_success)
                       {
                           printf("INFO : Encoded secret file extn successfully\n");
                           printf("INFO : Done\n");

                           //to get the secret file's size
                           if(encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
                           {
                              printf("INFO : Encoded secret file size successfully\n");
                              printf("INFO : Done\n");



                              //to store the secret msg to image
                              if(encode_secret_file_data(encInfo) == e_success)
                              {
                                  printf("INFO : Encoded secret data successfully\n");
                                  printf("INFO : Done\n");


                                  //to copy the remaining data 
                                  if(copy_remaining_img_data(encInfo) == e_success)
                                  {
                                      printf("INFO : Copied Left Over Data\n");
                                      printf("INFO : Done\n");
                                  }
                                  else
                                  {
                                      printf("ERROR : NOT COPIED\n");
                                      return e_failure;
                                  }
                              }
                              else
                              {
                                  printf("ERROR : Failed to encode secret file data\n");
                                  return e_failure;
                              }
                           }
                           else
                           {
                              printf("ERROR : Failed to encode secret file\n");
                             return e_failure;
                           } 
                       }
                       else
                       {
                           printf("ERROR : Failed to Encoden secret file extn\n");
                           return e_failure;
                       }
                   }
                   else
                   {
                   printf("ERROR : FAILED -> NOT EXTERNED\n");
                   return e_failure;
                   }

               }
               else
               {
                   printf("ERROR : ENCODING MAGIC STRING IS FAILED\n");
                   return e_failure;
               }
           }
           else
           {
               printf("ERROR : NOT COPIED BMP HEADER\n");
               return e_failure;
           }

       }
       else
       {
           printf("ERROR : Secret Msg can't fit in given image\n");
           return e_failure;
       }

   }
   else

   {
       printf("ERROR : failed to open files\n");
       return e_failure;
   }
   return e_success;
}

