#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int id;
    char name[20];
} item1;

int main(){
    printf("61. Files.\n");
    // File type for file stream.
    // fopen(filename, mode): returns a file pointer to file filename which is opened using mode.
    // If file cannot be read, NULL is returned.
    // r : open for reading
    // w: writing : file need not exist
    // a : append (need not exist)
    // r+ : reading and writing from beginning
    // w+ : open for reading and writing, overwriting file
    //  a+ : open for reading and writing, overwriting file
    // fclose(fp): closes FILE fp : returning 0 if close was successful. 
    // EOF is returned if there is an error in closing.
    FILE *fptr;
    fptr = fopen("testFile.txt", "w");
    if(fptr == NULL){
        printf("Error opening file");
        return -1;
    }
    fclose(fptr);

    printf("62. Reading from File\n");
    // File can be read one character at a time or an entire string can be read into a character buffer,
    // which is typically a char array used for temporary storage.
    // fgetc(fp) : Returns the next character from the file pointed to by fp. If the end of the file
    // has been reached, then EOF is returned.
    // fgets(buff, n, fp): Reads n-1 characters from the file pointed to by fp and stores the string in the buff
    // A NULL charactrer '\0' is appended as the last character in the buff. If fgets encounters a newline character,
    // or the end of file before n-1 character is reached, then only the characters up to that point are stored in buff.
    // fscanf(fp, conversion_specifiers, vars): Reads characters from the file pointed to by fp and assigns input to 
    // a list of variable pointers vara using conversion_specifiers. As with scanf, fscanf stops reading a string when 
    // a space or newline is encountered.
    FILE *fp;
    int c, stock;
    char buffer[200], item[10];
    float price;
    fp = fopen("myFile.txt", "r");
    fgets(buffer, 20, fptr);
    printf("Using fgets: %s\n", buffer);
    fscanf(fp, "%d%s%f", &stock, item, &price);
    printf("Using fscanf: %d %s %4.2f\n", stock, item, price);
    printf("using getc: \n");
    while((c = getc(fp)) != EOF){
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
    // gets() : reads up until the newline.
    // fscanf(): reads according to given specifiers.

    printf("63. Writig to a file\n");
    // fputc(char, fp): writes character
    // fputs(str, fp): writes string
    // fprintf(fp, str, vars): Prints string str to the file. str can optionally include
    // format specifiers and a list of variables vars.
    FILE *fp2;
    char filename[] = "testFile.txt";
    //printf("Enter the filename of the file to create: ");
    //fgets(filename, 50, stdin);
    fp2 = fopen(filename, "w");
    fprintf(fp2, "Inventory\n");
    fprintf(fp2, "%d %s %f \n", 100, "Widget", 0.29);
    fputs("End of List", fp2);
    fclose(fp2);

    printf("64. Binary File I/O \n");
    // Writing structures/arrays to files
    // fopen() function parameters:
    // rb: reading
    // wb: writing
    // ab: append
    // rb+ : reading and writing from beginning
    // wb+ : reading and writing , overwriting
    // ab+ : open for reading and writing, appending
    // fwrite(ptr, item_size, num_items, fp): Writes num_items items of item_size size from pointer ptr to 
    // the file pointed to by the pointer fp.
    // fread(ptr, item_size, num_items, fp): REads num_items items of item_size size from the file pointed
    // to by file pointer fp into the memory pointed to by ptr.
    // fclose(fp): Closes file openend with file fp, returning 0 if close was successful.
    // EOF is returned if there is an error in closing.
    // feof(fp): Returns 0 when the end of the file stream has reached.
    FILE *fp3;
    int arr[10];
    int x[10];
    int y;
    int k;
    for(k=0; k<10; k++){
        arr[k] = k;
    }
    fp3 = fopen("datafile.bin", "wb");
    fwrite(arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fp3);
    fclose(fp3);
    fp3 = fopen("datafile.bin", "rb");
    fread(x, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fp3);
    fclose(fp3);
    for(k=0; k<10; k++){
        printf("%d ", x[k]);
    }
    printf("\n");
    // The item size and number of items were determined by using the size of an element
    // and the size of the entire variable.
    // File extensions are useful in providing the type of data stored in them.
    // .txt: text
    // .bin: binary data
    // .csv : comma separated values
    // .dat: data file

    printf("65. Controlling the File Pointers\n");
    // ftell(fp): Returns a long int value corresponding to the fp file pointer position in number of
    // bytes from the start of the file
    // fseek(fp, num_bytes, from_pos): Moves fp file pointer position by num_bytes relative to position 
    // from_pos, which can be one of the following constants:
    // SEEK_SET: start of the file
    // SEEK_CUR: current position
    // SEEK_END: end of the file
    FILE *fp4;
    item1 first, second, secondf;
    first.id = 10276;
    strcpy(first.name, "Widget");
    second.id = 18823;
    strcpy(second.name, "Gadget");
    fp4 = fopen("info.dat", "wb");
    fwrite(&first, 1, sizeof(first), fp4);
    fwrite(&second, 1, sizeof(second), fp4);
    fclose(fp4);
    fp4 = fopen("info.dat", "rb");
    fseek(fp4, 1*sizeof(item1), SEEK_SET);
    fread(&secondf, 1, sizeof(item1), fp4);
    printf("%d %s\n", secondf.id, secondf.name);
    fclose(fp4);
    // We wrote two items in file.
    // To get the second record, we moved file pointer 1*sizeof(item1) forward.
    // If we want to get the 4th record, we seek to 3*sizeof(item) from the beginning of the file.
    return 0;
}