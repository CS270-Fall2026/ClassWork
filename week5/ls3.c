#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void doLs(const char * dirName, int l, int a);
void showStatInfo(const char *fname, struct stat *buf);

int main(int argc, char *argv[])
{
    int l=0, a = 0;
    if (argc == 1){
        doLs(".", l, a);
    }else{
        //find -l or -a
        for (int i = 1; i<argc; i++){
            if (strncmp(argv[i], "-l", 2)==0){
                l = 1;
            }else if (strncmp(argv[i], "-a", 2)==0){
                a = 1;
            }
        }
        while(--argc && strncmp(*++argv, "-a",2)!=0 &&strncmp(*argv, "-l",2)!=0)
        {
            printf("%s:\n", *argv);
            doLs(*argv, l,a);
        }
    }
    return 0;  
}
/**
 * @brief List file in directory 
 * 
 * @param dirName name of directory
 */
void doLs(const char * dirName, int l, int a)
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir(dirName))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            if (pEntry->d_name[0] != '.' ||
                (pEntry->d_name[0] == '.' && a==1))
            {
                printf("%s\n", pEntry->d_name);
                if (l){
                    struct stat info; 
                    if (stat(pEntry->d_name, &info) != -1)
                    {
                        showStatInfo(pEntry->d_name, &info);
                    }

                }
            }
        }
    }
}

void showStatInfo(const char *fname, struct stat *buf)
{
    printf("   mode: %o\n", buf->st_mode);
    printf("   links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("   group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("   modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}

