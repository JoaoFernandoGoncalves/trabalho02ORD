#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define BUCKET_LENGTH 5

FILE *arqv_dir;
FILE *arqv_bckt;

int hash_function(int key)
{
    return key;
}

typedef struct
{
    int prof;
    int in_key;
    int chaves [BUCKET_LENGTH];
}bucket;

typedef struct
{
    int bucket_rrn;
}dir_cell;

typedef struct
{
    dir_cell *cells;
    int dir_prof;
}diretory;


void inicializa(char *nome_dir, char *nome_bucket)
{
    FILE *arqv_dir, *arqv_bucket;

    arqv_dir = fopen(nome_dir, "w+b");
    arqv_bucket = fopen(nome_bucket, "w+b");

    /*dir_cell *diretorio;
    int dir_prof = 0;*/

    diretory diretorio;

    if(arqv_dir != NULL)
    {
        fread(diretorio.cells, sizeof(int), 256, arqv_dir);
        diretorio.dir_prof = log2(sizeof(diretorio.cells));
    }
    else
    {
        dir_cell cell;
        diretorio.cells = malloc(sizeof(&cell));
        diretorio.dir_prof = 0;

        bucket balde;
        fwrite(&balde, sizeof(balde), 1, arqv_bucket);
        cell.bucket_rrn = (arqv_bucket, -sizeof(balde), SEEK_CUR);
    }
}

void finaliza(char *nome_dir, char *nome_bucket)
{
    FILE *arqv_dir, *arq_bckt;
    diretory diretorio;

    fwrite(diretorio.cells, sizeof(dir_cell), sizeof(diretorio.cells), arqv_dir);
    fclose(arqv_dir);
    fclose(arq_bckt);
}

bool op_find(int key, bucket found_bucket)
{   
    diretory diretorio;

    int address = key;
    int rrn_found_bucket = diretorio.cells[address].bucket_rrn;

    fseek(arqv_bckt, rrn_found_bucket, SEEK_SET);
    fread(&found_bucket, sizeof(bucket), 1, arqv_bckt);
    
    for(int i = 0; i < BUCKET_LENGTH; i++)
    {
        if(found_bucket.chaves[i] == key)
        {
            return true;
        }
        else{
            return false;
        }
    }


}

/*bool op_add(int key)
{
    if(op_find(key, found.bucket))
    {
        return false;
    }
    
    bk_add_key(found_bucket, key);
    return true;
}

void bk_add_key(bucket balde, int key)
{
    if(balde.in_key < BUCKET_LENGTH)
    {
        balde.chaves = malloc(key);
    }
    else{
        bk_split(balde);
        op_add(key);
    }
}*/

int main()
{

}