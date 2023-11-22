#include <stdio.h>
#include "decode.h"
#include "encode.h"
#include "types.h"
#include<string.h>

int main(int argc,char *argv[])
{
    if(argc>1){
 EncodeInfo E1;
 DecodeInfo decInfo;
 int res=check_operation_type(argv);
 if(res==e_encode)
 {
     printf("INFO : Selected Encoding\n");
     if( (read_and_validate_encode_args (argv, &E1 )) == e_success)
     {
         printf("INFO : Read and validate is sucessfully\n");        //<------validating the condition read and validate
         if(do_encoding(&E1)== e_success)
         {
             printf("INFO : ## Encoding Done Successlly ## \n");   //<------validating the condition encoding
         }
         else
         {
             printf("ERROR : Encoding is failure\n");
             return 3;
         }

     }
     else
     {
         printf("ERROR : Failed to read and validate");
         return 2;
     }


 }
 else if(res==e_decode)
 {
     printf("INFO : Selected Decoding\n");
     printf("INFO : ## Decoding Procedure Started ##\n");
    if ( (read_and_validate_decode_args(argv, &decInfo)) == e_success)   //<---- validating the condition read and validate
	{
	    printf("INFO : Read and validate is succussfull\n");
	    if ( do_decoding(&decInfo) == e_success)   //<---- validating the condition decoding
	    {
		printf("INFO : ## DECODING DONE SUCCESSFULLY ##\n");
        }
	    else
	    {
		printf("ERROR: Decoding is failure\n");
	    }
	}
 
	else
	{
	    printf("ERROR: Validation is failure\n");
	}

}
 
 else{
     printf("ERROR : Unsupported Operation\nFor Encoding:\n./a.out -e beautiful.bmp secret.txt [stegno.bmp]\nFor Decoding:\n./a.out -d steggno.bmp data.txt\n");
 }
    }
    else
        printf("PLEASE ENTER CLA\n");
}
OperationType check_operation_type(char *argv[]){
    if(strcmp(argv[1],"-e")==0)
        return e_encode;
    else if(strcmp(argv[1],"-d")==0)
        return e_decode;
    else
        return e_unsupported;
}

