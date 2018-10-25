#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 256

char links[SIZE][SIZE][SIZE];
int link_used[SIZE];
int inodes[SIZE];

int main() 
{
  for(int i = 0; i < SIZE; i++){
    inodes[i] = -1;
    link_used[i] = 0;
  }

  DIR *tmpdir = opendir("tmp");

  char path[SIZE];
  struct dirent *d;
  while ((d = readdir(tmpdir)) != NULL) {
    path[0] = '\0';
    strcat(path, "tmp/");
    strcat(path, d->d_name);    
    struct stat st;
     stat(path, &st);

    int inode = st.st_ino;
    int ind = -1;
    int i;
    for (i = 0; i < SIZE; i++) {
      if (inodes[i] == inode) {
        ind = i;
        break;
      }
      if(inodes[i] == -1) break;
    }
    if(i >= SIZE) { printf("Too many inodes\n"); break; }
    if(ind == -1) { inodes[i] = inode; ind = inodes[i]; }
    strcpy(links[i][link_used[i]], path);
    link_used[i]++;
  }
  
  for (int i = 0; i < SIZE; i++) {
    if (link_used[i] >= 2) {
      printf("For node %d:\n", inodes[i]);
      for(int j = 0; j < link_used[i]; j++){
        printf("%s\n", links[i][j]);
      }
    }
  }
}
