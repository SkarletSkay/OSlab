#include <stdio.h>
#include <string.h>



#define MAX_PROC 100
#define MAX_RES 100
#define LINE_BUF_SIZE 500

int m; // res
int tot_res[MAX_RES];
int avail_res[MAX_RES];

int n; // proc
int cur_res[MAX_PROC][MAX_RES];
int req_res[MAX_PROC][MAX_RES];
int is_running[MAX_PROC];
int running;

int find_r()
{
    int i, j;
    for (i = 0; i < n; i++) {
        if (!is_running[i]) {
            continue;
        }
        int good = 1;
        for (j = 0; j < m; j++) {
            if (req_res[i][j] > avail_res[j] + cur_res[i][j]) {
                good = 0;
                break;
            }   
        }
        if (good) {
            return i;
        }
    }
    return -1;
}

void free_res(int r) {
    int i;
    for (i = 0; i < m; i++) {
        avail_res[i] += cur_res[r][i];
        cur_res[r][i] = 0;
    }
}

int main()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int i, j;

    m = 0;
    char c = '1';
    for (i = 0; c != '\n';i++) {
	fscanf(fin, "%d%c", &tot_res[i], &c);
    }
    m = i;

    for (i = 0; i < m; i++) {
        fscanf(fin, "%d", &tot_res[i]);
    }

    for (i = 0; i < m; i++) {
        fscanf(fin, "%d", &avail_res[i]);
    }

    char line_array[LINE_BUF_SIZE];
    char *line = line_array;
    n = 0;
    fgets(line, LINE_BUF_SIZE, fin);
    for (i = 0; n == 0; i++) {
    	char *last_read = fgets(line, LINE_BUF_SIZE, fin);
	if (line[0] == '\n') {
		n = i + 1;
		break;
	}
        for (j = 0; j < m; j++) {
	    int x = sscanf(line, "%d", &cur_res[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(fin, "%d", &req_res[i][j]);
        }
    }

    running = n;
    for (i = 0; i < n; i++) {
        is_running[i] = 1;
    }

    int r;

    while ((r = find_r()) != -1) {
        free_res(r);
        running--;
        is_running[r] = 0;
    }
    if (running) {
        fprintf(fout, "Deadlock! Proccesses:\n");
        for (i = 0; i < n; i++) {
            if (is_running[i]) {
                fprintf(fout, "%d ", i);
            }
        }
        fprintf(fout, "\n");
    } else {
        fprintf(fout, "No deadlock\n");
    }

}
