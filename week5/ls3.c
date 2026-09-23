#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h> 

void doLs(const char * dirName, int l, int a);
void showStatInfo(const char *fname, struct stat *buf);
void getMode( mode_t mode, char str[]);

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
                    if (lstat(pEntry->d_name, &info) != -1)
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
    char str_mode[11] ="----------";
    getMode(buf->st_mode, str_mode);
    printf("   mode: %s\n", str_mode);

    printf("   links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("   user: %s\n", getpwuid(buf->st_uid)->pw_name);

    printf("   group: %d\n", buf->st_gid);
    printf("   group: %s\n", getgrgid(buf->st_gid)->gr_name);

    printf("   size: %ld\n", buf->st_size);
    printf("   modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}
void getMode( mode_t mode, char str[])
{
    switch (mode & S_IFMT) 
    {
        case S_IFBLK:  str[0]='b';             break;
        case S_IFCHR:  str[0]='c';              break;
        case S_IFDIR:  str[0]='d';             break;
        case S_IFIFO:  str[0]='p';             break;
        case S_IFLNK:  str[0]='l';             break;
        case S_IFREG:  str[0]='-';             break;
        case S_IFSOCK: str[0]='s';             break;
        default:       str[0]='?';             break;
    }
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';

}

